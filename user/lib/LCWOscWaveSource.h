/*
Copyright 2019 Tomoaki Itoh
This software is released under the MIT License, see LICENSE.txt.
//*/

#include <stdint.h>

#define LCW_OSC_TABLE_BITS (12)
#define LCW_OSC_TABLE_SIZE (1 << LCW_OSC_TABLE_BITS)
#define LCW_OSC_TABLE_MASK ((LCW_OSC_TABLE_SIZE) - 1)

// SQ1.14
typedef int16_t LCWOscWaveTable[LCW_OSC_TABLE_SIZE];

extern const LCWOscWaveTable gLcwOscPulseTable;
extern const LCWOscWaveTable gLcwOscSawTable;
extern const LCWOscWaveTable gLcwOscTriTable;

