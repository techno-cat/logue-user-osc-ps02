/*
Copyright 2020 Tomoaki Itoh
This software is released under the MIT License, see LICENSE.txt.
//*/

#include "userosc.h"
#include "LCWCommon.h"
#include "LCWPitchTable.h"
#include "LCWOscWaveSource.h"
#include "LCWOSCFirParamTable.h"

typedef struct {
  int32_t noteNo;
  uint32_t t;
  uint32_t dt;
} VoiceBlock;

#define NUMBER_OF_VOICE (1)
static VoiceBlock voiceBlocks[NUMBER_OF_VOICE];
static VoiceBlock *activeBlocks[NUMBER_OF_VOICE];

static struct {
  int16_t shape = 0;
  int16_t shiftshape = 0;
  int16_t chord = 0;
  int16_t oct = 0;
  int16_t wave = 0;
} s_param;

static struct {
  int32_t shape_lfo = 0; // = OSC_CYCLEで更新したshape_lfo
} s_modulation;

static const int16_t *s_waveTables[] = {
  &gLcwOscPulseTable[0],
  &gLcwOscSawTable[0],
  &gLcwOscTriTable[0]
};

void OSC_INIT(uint32_t platform, uint32_t api)
{
  for (int32_t i=0; i<NUMBER_OF_VOICE; i++) {
    VoiceBlock *p = &(voiceBlocks[0]) + i;
    p->noteNo = 0;
    p->t = 0;
    p->dt = 0;
    activeBlocks[i] = p;
  }
}

#define LCW_OSC_TIMER_BITS (LCW_PITCH_DELTA_VALUE_BITS)
#define LCW_OSC_TIMER_MAX ((1 << LCW_OSC_TIMER_BITS) - 1)
#define LCW_OSC_TIMER_MASK (LCW_OSC_TIMER_MAX - 1)

// pitch : s7.24, return : SQ.22
__fast_inline int32_t myLookUp(uint32_t t, const int16_t *wave)
{
#if 0
  //return (LCW_OSC_TIMER_MAX >> 1) < t ? 16383 : -16383;
  const uint32_t t0 = t >> (LCW_OSC_TIMER_BITS - LCW_OSC_TABLE_BITS);
  return wave[t0];
#else
  // 補間の準備
  const uint32_t t0 =
    t >> (LCW_OSC_TIMER_BITS - (LCW_OSC_TABLE_BITS + LCW_OSC_FIR_TABLE_BITS));

  // サンプリングしたい位置とはtap数/2ほどずれるのは仕方ない
  const uint32_t i = (t0 >> LCW_OSC_FIR_TABLE_BITS)/* - (LCW_OSC_FIR_TAP >> 1)*/;
  const SQ3_12 *fir = gLcwOscFirTable[t0 & LCW_OSC_FIR_TABLE_MASK];

#if (1)
  int64_t ret = 0;
  for (int32_t j=0; j<LCW_OSC_FIR_TAP; j++) {
      ret += ( (int64_t)(wave[(i + j) & LCW_OSC_TABLE_MASK]) * fir[j] );
  }

  return (int32_t)( ret >> LCW_OSC_FIR_VALUE_BITS );
#else
  return (int32_t)wave[(i + (LCW_OSC_FIR_TAP >> 1)) & LCW_OSC_TABLE_MASK];
#endif
#endif
}

void OSC_CYCLE(const user_osc_param_t * const params,
               int32_t *yn,
               const uint32_t frames)
{
  const int16_t *wave = s_waveTables[s_param.wave];

  // Shapeに対するLFOの値をサンプリング（ノートオン時に参照する）
  s_modulation.shape_lfo = params->shape_lfo;

  q31_t * __restrict y = (q31_t *)yn;
  const q31_t * y_e = y + frames;

  for (; y != y_e; ) {
    int32_t out = 0;
    for (int32_t i=0; i<NUMBER_OF_VOICE; i++) {
      VoiceBlock *block = activeBlocks[i];
      block->t = (block->t + block->dt) & LCW_OSC_TIMER_MASK;
      out += myLookUp( block->t, wave );
    }

    out = clipminmaxi32( -16383, out, 16383 );
    *(y++) = ( out << (31 - 14) );
  }
}

// ポルタメントやピッチベンドが加味されると正しく動作しない
void OSC_NOTEON(const user_osc_param_t * const params)
{
  // If changed array length of chordTable, update "manifest.json".
  // ["Chrd",   0,  4,  ""]
  //                ^ = Array length - 1
  static const struct {
    int16_t table[8];
    int16_t n;
  } chordTable[] = {
    { { 0, 2, 4, 5, 7, 9,11, 0 }, 7 }, // C,D,E,F,G,A,B from C
    { { 0, 3, 7, 0, 0, 0, 0, 0 }, 3 }, // C
    { { 0, 4, 7,11, 0, 0, 0, 0 }, 4 }, // CM7
    { { 0, 3, 7, 0, 0, 0, 0, 0 }, 3 }, // Cm
    { { 0, 3, 7,10, 0, 0, 0, 0 }, 4 }  // Cm7
  };

  const int16_t *noteDeltaTable = &(chordTable[s_param.chord].table[0]);
  const int32_t n = chordTable[s_param.chord].n;

  // 四捨五入でノートNo.を確定
  const int32_t noteNo0 = ((int32_t)params->pitch + 0x80) >> 8;

  // テーブルにマッピング
  const SQ15_16 tmp = (s_modulation.shape_lfo >> 20) * (s_param.shape >> 3);
  const SQ15_16 frac = (SQ15_16)((uint32_t)tmp & 0xFFFF);
  const int32_t delta = noteDeltaTable[(frac * n) >> 16] + ((tmp >> 16) * 12);
  const int32_t noteNo = noteNo0 + delta - (s_param.oct * 12);

  // s11.20に拡張してから、整数部がoctaveになるように加工
  int32_t pitch = ((noteNo - LCW_NOTE_NO_A4) << 20) / 12;

  // しきい値を超えたら音程を反転
  const int32_t th = (int32_t)(s_param.shiftshape - 512) << (20 + 4 - 10); // = -8.0〜8.0
  if ( th < pitch ) {
    pitch = (pitch & 0xFFF00000) + (1 << 20) - (pitch & 0x000FFFFF);
  }

  VoiceBlock *block = activeBlocks[0];
  block->noteNo = noteNo;
  block->dt = pitch_to_timer_delta(pitch >> (20 - 16));
}

void OSC_NOTEOFF(const user_osc_param_t * const params)
{
}

void OSC_PARAM(uint16_t index, uint16_t value)
{
  switch (index) {
  case k_user_osc_param_shape:
    s_param.shape = (int16_t)value;
    break;
  case k_user_osc_param_shiftshape:
    s_param.shiftshape = (int16_t)value;
    break;
  case k_user_osc_param_id1:
    s_param.chord = (int16_t)value;
    break;
  case k_user_osc_param_id2:
    s_param.oct = (int16_t)value;
    break;
  case k_user_osc_param_id3:
    s_param.wave = (int16_t)value;
    break;
  default:
    break;
  }
}
