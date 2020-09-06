/*
Copyright 2019 Tomoaki Itoh
This software is released under the MIT License, see LICENSE.txt.
//*/

#include "LCWOscWaveSource.h"

const LCWOscWaveTable gLcwOscTriTable = {
    0x0000, 0x0010, 0x0020, 0x0030, 0x003F, 0x004F, 0x005F, 0x006F,
    0x007F, 0x008F, 0x009E, 0x00AE, 0x00BE, 0x00CE, 0x00DE, 0x00EE,
    0x00FD, 0x010D, 0x011D, 0x012D, 0x013D, 0x014D, 0x015C, 0x016C,
    0x017C, 0x018C, 0x019C, 0x01AC, 0x01BC, 0x01CB, 0x01DB, 0x01EB,
    0x01FB, 0x020B, 0x021B, 0x022A, 0x023A, 0x024A, 0x025A, 0x026A,
    0x027A, 0x0289, 0x0299, 0x02A9, 0x02B9, 0x02C9, 0x02D9, 0x02E8,
    0x02F8, 0x0308, 0x0318, 0x0328, 0x0338, 0x0348, 0x0357, 0x0367,
    0x0377, 0x0387, 0x0397, 0x03A7, 0x03B6, 0x03C6, 0x03D6, 0x03E6,
    0x03F6, 0x0406, 0x0415, 0x0425, 0x0435, 0x0445, 0x0455, 0x0465,
    0x0474, 0x0484, 0x0494, 0x04A4, 0x04B4, 0x04C4, 0x04D4, 0x04E3,
    0x04F3, 0x0503, 0x0513, 0x0523, 0x0533, 0x0542, 0x0552, 0x0562,
    0x0572, 0x0582, 0x0592, 0x05A1, 0x05B1, 0x05C1, 0x05D1, 0x05E1,
    0x05F1, 0x0600, 0x0610, 0x0620, 0x0630, 0x0640, 0x0650, 0x0660,
    0x066F, 0x067F, 0x068F, 0x069F, 0x06AF, 0x06BF, 0x06CE, 0x06DE,
    0x06EE, 0x06FE, 0x070E, 0x071E, 0x072D, 0x073D, 0x074D, 0x075D,
    0x076D, 0x077D, 0x078C, 0x079C, 0x07AC, 0x07BC, 0x07CC, 0x07DC,
    0x07EC, 0x07FB, 0x080B, 0x081B, 0x082B, 0x083B, 0x084B, 0x085A,
    0x086A, 0x087A, 0x088A, 0x089A, 0x08AA, 0x08B9, 0x08C9, 0x08D9,
    0x08E9, 0x08F9, 0x0909, 0x0918, 0x0928, 0x0938, 0x0948, 0x0958,
    0x0968, 0x0978, 0x0987, 0x0997, 0x09A7, 0x09B7, 0x09C7, 0x09D7,
    0x09E6, 0x09F6, 0x0A06, 0x0A16, 0x0A26, 0x0A36, 0x0A45, 0x0A55,
    0x0A65, 0x0A75, 0x0A85, 0x0A95, 0x0AA4, 0x0AB4, 0x0AC4, 0x0AD4,
    0x0AE4, 0x0AF4, 0x0B04, 0x0B13, 0x0B23, 0x0B33, 0x0B43, 0x0B53,
    0x0B63, 0x0B72, 0x0B82, 0x0B92, 0x0BA2, 0x0BB2, 0x0BC2, 0x0BD1,
    0x0BE1, 0x0BF1, 0x0C01, 0x0C11, 0x0C21, 0x0C30, 0x0C40, 0x0C50,
    0x0C60, 0x0C70, 0x0C80, 0x0C90, 0x0C9F, 0x0CAF, 0x0CBF, 0x0CCF,
    0x0CDF, 0x0CEF, 0x0CFE, 0x0D0E, 0x0D1E, 0x0D2E, 0x0D3E, 0x0D4E,
    0x0D5D, 0x0D6D, 0x0D7D, 0x0D8D, 0x0D9D, 0x0DAD, 0x0DBC, 0x0DCC,
    0x0DDC, 0x0DEC, 0x0DFC, 0x0E0C, 0x0E1C, 0x0E2B, 0x0E3B, 0x0E4B,
    0x0E5B, 0x0E6B, 0x0E7B, 0x0E8A, 0x0E9A, 0x0EAA, 0x0EBA, 0x0ECA,
    0x0EDA, 0x0EE9, 0x0EF9, 0x0F09, 0x0F19, 0x0F29, 0x0F39, 0x0F48,
    0x0F58, 0x0F68, 0x0F78, 0x0F88, 0x0F98, 0x0FA8, 0x0FB7, 0x0FC7,
    0x0FD7, 0x0FE7, 0x0FF7, 0x1007, 0x1016, 0x1026, 0x1036, 0x1046,
    0x1056, 0x1066, 0x1075, 0x1085, 0x1095, 0x10A5, 0x10B5, 0x10C5,
    0x10D4, 0x10E4, 0x10F4, 0x1104, 0x1114, 0x1124, 0x1134, 0x1143,
    0x1153, 0x1163, 0x1173, 0x1183, 0x1193, 0x11A2, 0x11B2, 0x11C2,
    0x11D2, 0x11E2, 0x11F2, 0x1201, 0x1211, 0x1221, 0x1231, 0x1241,
    0x1251, 0x1260, 0x1270, 0x1280, 0x1290, 0x12A0, 0x12B0, 0x12C0,
    0x12CF, 0x12DF, 0x12EF, 0x12FF, 0x130F, 0x131F, 0x132E, 0x133E,
    0x134E, 0x135E, 0x136E, 0x137E, 0x138D, 0x139D, 0x13AD, 0x13BD,
    0x13CD, 0x13DD, 0x13EC, 0x13FC, 0x140C, 0x141C, 0x142C, 0x143C,
    0x144C, 0x145B, 0x146B, 0x147B, 0x148B, 0x149B, 0x14AB, 0x14BA,
    0x14CA, 0x14DA, 0x14EA, 0x14FA, 0x150A, 0x1519, 0x1529, 0x1539,
    0x1549, 0x1559, 0x1569, 0x1578, 0x1588, 0x1598, 0x15A8, 0x15B8,
    0x15C8, 0x15D8, 0x15E7, 0x15F7, 0x1607, 0x1617, 0x1627, 0x1637,
    0x1646, 0x1656, 0x1666, 0x1676, 0x1686, 0x1696, 0x16A5, 0x16B5,
    0x16C5, 0x16D5, 0x16E5, 0x16F5, 0x1704, 0x1714, 0x1724, 0x1734,
    0x1744, 0x1754, 0x1764, 0x1773, 0x1783, 0x1793, 0x17A3, 0x17B3,
    0x17C3, 0x17D2, 0x17E2, 0x17F2, 0x1802, 0x1812, 0x1822, 0x1831,
    0x1841, 0x1851, 0x1861, 0x1871, 0x1881, 0x1890, 0x18A0, 0x18B0,
    0x18C0, 0x18D0, 0x18E0, 0x18F0, 0x18FF, 0x190F, 0x191F, 0x192F,
    0x193F, 0x194F, 0x195E, 0x196E, 0x197E, 0x198E, 0x199E, 0x19AE,
    0x19BD, 0x19CD, 0x19DD, 0x19ED, 0x19FD, 0x1A0D, 0x1A1C, 0x1A2C,
    0x1A3C, 0x1A4C, 0x1A5C, 0x1A6C, 0x1A7C, 0x1A8B, 0x1A9B, 0x1AAB,
    0x1ABB, 0x1ACB, 0x1ADB, 0x1AEA, 0x1AFA, 0x1B0A, 0x1B1A, 0x1B2A,
    0x1B3A, 0x1B49, 0x1B59, 0x1B69, 0x1B79, 0x1B89, 0x1B99, 0x1BA8,
    0x1BB8, 0x1BC8, 0x1BD8, 0x1BE8, 0x1BF8, 0x1C08, 0x1C17, 0x1C27,
    0x1C37, 0x1C47, 0x1C57, 0x1C67, 0x1C76, 0x1C86, 0x1C96, 0x1CA6,
    0x1CB6, 0x1CC6, 0x1CD5, 0x1CE5, 0x1CF5, 0x1D05, 0x1D15, 0x1D25,
    0x1D34, 0x1D44, 0x1D54, 0x1D64, 0x1D74, 0x1D84, 0x1D94, 0x1DA3,
    0x1DB3, 0x1DC3, 0x1DD3, 0x1DE3, 0x1DF3, 0x1E02, 0x1E12, 0x1E22,
    0x1E32, 0x1E42, 0x1E52, 0x1E61, 0x1E71, 0x1E81, 0x1E91, 0x1EA1,
    0x1EB1, 0x1EC0, 0x1ED0, 0x1EE0, 0x1EF0, 0x1F00, 0x1F10, 0x1F20,
    0x1F2F, 0x1F3F, 0x1F4F, 0x1F5F, 0x1F6F, 0x1F7F, 0x1F8E, 0x1F9E,
    0x1FAE, 0x1FBE, 0x1FCE, 0x1FDE, 0x1FED, 0x1FFD, 0x200D, 0x201D,
    0x202D, 0x203D, 0x204C, 0x205C, 0x206C, 0x207C, 0x208C, 0x209C,
    0x20AC, 0x20BB, 0x20CB, 0x20DB, 0x20EB, 0x20FB, 0x210B, 0x211A,
    0x212A, 0x213A, 0x214A, 0x215A, 0x216A, 0x2179, 0x2189, 0x2199,
    0x21A9, 0x21B9, 0x21C9, 0x21D8, 0x21E8, 0x21F8, 0x2208, 0x2218,
    0x2228, 0x2238, 0x2247, 0x2257, 0x2267, 0x2277, 0x2287, 0x2297,
    0x22A6, 0x22B6, 0x22C6, 0x22D6, 0x22E6, 0x22F6, 0x2305, 0x2315,
    0x2325, 0x2335, 0x2345, 0x2355, 0x2364, 0x2374, 0x2384, 0x2394,
    0x23A4, 0x23B4, 0x23C4, 0x23D3, 0x23E3, 0x23F3, 0x2403, 0x2413,
    0x2423, 0x2432, 0x2442, 0x2452, 0x2462, 0x2472, 0x2482, 0x2491,
    0x24A1, 0x24B1, 0x24C1, 0x24D1, 0x24E1, 0x24F0, 0x2500, 0x2510,
    0x2520, 0x2530, 0x2540, 0x2550, 0x255F, 0x256F, 0x257F, 0x258F,
    0x259F, 0x25AF, 0x25BE, 0x25CE, 0x25DE, 0x25EE, 0x25FE, 0x260E,
    0x261D, 0x262D, 0x263D, 0x264D, 0x265D, 0x266D, 0x267C, 0x268C,
    0x269C, 0x26AC, 0x26BC, 0x26CC, 0x26DC, 0x26EB, 0x26FB, 0x270B,
    0x271B, 0x272B, 0x273B, 0x274A, 0x275A, 0x276A, 0x277A, 0x278A,
    0x279A, 0x27A9, 0x27B9, 0x27C9, 0x27D9, 0x27E9, 0x27F9, 0x2808,
    0x2818, 0x2828, 0x2838, 0x2848, 0x2858, 0x2868, 0x2877, 0x2887,
    0x2897, 0x28A7, 0x28B7, 0x28C7, 0x28D6, 0x28E6, 0x28F6, 0x2906,
    0x2916, 0x2926, 0x2935, 0x2945, 0x2955, 0x2965, 0x2975, 0x2985,
    0x2994, 0x29A4, 0x29B4, 0x29C4, 0x29D4, 0x29E4, 0x29F4, 0x2A03,
    0x2A13, 0x2A23, 0x2A33, 0x2A43, 0x2A53, 0x2A62, 0x2A72, 0x2A82,
    0x2A92, 0x2AA2, 0x2AB2, 0x2AC1, 0x2AD1, 0x2AE1, 0x2AF1, 0x2B01,
    0x2B11, 0x2B20, 0x2B30, 0x2B40, 0x2B50, 0x2B60, 0x2B70, 0x2B80,
    0x2B8F, 0x2B9F, 0x2BAF, 0x2BBF, 0x2BCF, 0x2BDF, 0x2BEE, 0x2BFE,
    0x2C0E, 0x2C1E, 0x2C2E, 0x2C3E, 0x2C4D, 0x2C5D, 0x2C6D, 0x2C7D,
    0x2C8D, 0x2C9D, 0x2CAC, 0x2CBC, 0x2CCC, 0x2CDC, 0x2CEC, 0x2CFC,
    0x2D0C, 0x2D1B, 0x2D2B, 0x2D3B, 0x2D4B, 0x2D5B, 0x2D6B, 0x2D7A,
    0x2D8A, 0x2D9A, 0x2DAA, 0x2DBA, 0x2DCA, 0x2DD9, 0x2DE9, 0x2DF9,
    0x2E09, 0x2E19, 0x2E29, 0x2E38, 0x2E48, 0x2E58, 0x2E68, 0x2E78,
    0x2E88, 0x2E98, 0x2EA7, 0x2EB7, 0x2EC7, 0x2ED7, 0x2EE7, 0x2EF7,
    0x2F06, 0x2F16, 0x2F26, 0x2F36, 0x2F46, 0x2F56, 0x2F65, 0x2F75,
    0x2F85, 0x2F95, 0x2FA5, 0x2FB5, 0x2FC4, 0x2FD4, 0x2FE4, 0x2FF4,
    0x3004, 0x3014, 0x3024, 0x3033, 0x3043, 0x3053, 0x3063, 0x3073,
    0x3083, 0x3092, 0x30A2, 0x30B2, 0x30C2, 0x30D2, 0x30E2, 0x30F1,
    0x3101, 0x3111, 0x3121, 0x3131, 0x3141, 0x3150, 0x3160, 0x3170,
    0x3180, 0x3190, 0x31A0, 0x31B0, 0x31BF, 0x31CF, 0x31DF, 0x31EF,
    0x31FF, 0x320F, 0x321E, 0x322E, 0x323E, 0x324E, 0x325E, 0x326E,
    0x327D, 0x328D, 0x329D, 0x32AD, 0x32BD, 0x32CD, 0x32DC, 0x32EC,
    0x32FC, 0x330C, 0x331C, 0x332C, 0x333C, 0x334B, 0x335B, 0x336B,
    0x337B, 0x338B, 0x339B, 0x33AA, 0x33BA, 0x33CA, 0x33DA, 0x33EA,
    0x33FA, 0x3409, 0x3419, 0x3429, 0x3439, 0x3449, 0x3459, 0x3468,
    0x3478, 0x3488, 0x3498, 0x34A8, 0x34B8, 0x34C8, 0x34D7, 0x34E7,
    0x34F7, 0x3507, 0x3517, 0x3527, 0x3536, 0x3546, 0x3556, 0x3566,
    0x3576, 0x3586, 0x3595, 0x35A5, 0x35B5, 0x35C5, 0x35D5, 0x35E5,
    0x35F4, 0x3604, 0x3614, 0x3624, 0x3634, 0x3644, 0x3654, 0x3663,
    0x3673, 0x3683, 0x3693, 0x36A3, 0x36B3, 0x36C2, 0x36D2, 0x36E2,
    0x36F2, 0x3702, 0x3712, 0x3721, 0x3731, 0x3741, 0x3751, 0x3761,
    0x3771, 0x3780, 0x3790, 0x37A0, 0x37B0, 0x37C0, 0x37D0, 0x37E0,
    0x37EF, 0x37FF, 0x380F, 0x381F, 0x382F, 0x383F, 0x384E, 0x385E,
    0x386E, 0x387E, 0x388E, 0x389E, 0x38AD, 0x38BD, 0x38CD, 0x38DD,
    0x38ED, 0x38FD, 0x390C, 0x391C, 0x392C, 0x393C, 0x394C, 0x395C,
    0x396C, 0x397B, 0x398B, 0x399B, 0x39AB, 0x39BB, 0x39CB, 0x39DA,
    0x39EA, 0x39FA, 0x3A0A, 0x3A1A, 0x3A2A, 0x3A39, 0x3A49, 0x3A59,
    0x3A69, 0x3A79, 0x3A89, 0x3A98, 0x3AA8, 0x3AB8, 0x3AC8, 0x3AD8,
    0x3AE8, 0x3AF8, 0x3B07, 0x3B17, 0x3B27, 0x3B37, 0x3B47, 0x3B57,
    0x3B66, 0x3B76, 0x3B86, 0x3B96, 0x3BA6, 0x3BB6, 0x3BC5, 0x3BD5,
    0x3BE5, 0x3BF5, 0x3C05, 0x3C15, 0x3C24, 0x3C34, 0x3C44, 0x3C54,
    0x3C64, 0x3C74, 0x3C84, 0x3C93, 0x3CA3, 0x3CB3, 0x3CC3, 0x3CD3,
    0x3CE3, 0x3CF2, 0x3D02, 0x3D12, 0x3D22, 0x3D32, 0x3D42, 0x3D51,
    0x3D61, 0x3D71, 0x3D81, 0x3D91, 0x3DA1, 0x3DB0, 0x3DC0, 0x3DD0,
    0x3DE0, 0x3DF0, 0x3E00, 0x3E10, 0x3E1F, 0x3E2F, 0x3E3F, 0x3E4F,
    0x3E5F, 0x3E6F, 0x3E7E, 0x3E8E, 0x3E9E, 0x3EAE, 0x3EBE, 0x3ECE,
    0x3EDD, 0x3EED, 0x3EFD, 0x3F0D, 0x3F1D, 0x3F2D, 0x3F3C, 0x3F4D,
    0x3F59, 0x3F4D, 0x3F3C, 0x3F2D, 0x3F1D, 0x3F0D, 0x3EFD, 0x3EED,
    0x3EDD, 0x3ECE, 0x3EBE, 0x3EAE, 0x3E9E, 0x3E8E, 0x3E7E, 0x3E6F,
    0x3E5F, 0x3E4F, 0x3E3F, 0x3E2F, 0x3E1F, 0x3E10, 0x3E00, 0x3DF0,
    0x3DE0, 0x3DD0, 0x3DC0, 0x3DB0, 0x3DA1, 0x3D91, 0x3D81, 0x3D71,
    0x3D61, 0x3D51, 0x3D42, 0x3D32, 0x3D22, 0x3D12, 0x3D02, 0x3CF2,
    0x3CE3, 0x3CD3, 0x3CC3, 0x3CB3, 0x3CA3, 0x3C93, 0x3C84, 0x3C74,
    0x3C64, 0x3C54, 0x3C44, 0x3C34, 0x3C24, 0x3C15, 0x3C05, 0x3BF5,
    0x3BE5, 0x3BD5, 0x3BC5, 0x3BB6, 0x3BA6, 0x3B96, 0x3B86, 0x3B76,
    0x3B66, 0x3B57, 0x3B47, 0x3B37, 0x3B27, 0x3B17, 0x3B07, 0x3AF8,
    0x3AE8, 0x3AD8, 0x3AC8, 0x3AB8, 0x3AA8, 0x3A98, 0x3A89, 0x3A79,
    0x3A69, 0x3A59, 0x3A49, 0x3A39, 0x3A2A, 0x3A1A, 0x3A0A, 0x39FA,
    0x39EA, 0x39DA, 0x39CB, 0x39BB, 0x39AB, 0x399B, 0x398B, 0x397B,
    0x396C, 0x395C, 0x394C, 0x393C, 0x392C, 0x391C, 0x390C, 0x38FD,
    0x38ED, 0x38DD, 0x38CD, 0x38BD, 0x38AD, 0x389E, 0x388E, 0x387E,
    0x386E, 0x385E, 0x384E, 0x383F, 0x382F, 0x381F, 0x380F, 0x37FF,
    0x37EF, 0x37E0, 0x37D0, 0x37C0, 0x37B0, 0x37A0, 0x3790, 0x3780,
    0x3771, 0x3761, 0x3751, 0x3741, 0x3731, 0x3721, 0x3712, 0x3702,
    0x36F2, 0x36E2, 0x36D2, 0x36C2, 0x36B3, 0x36A3, 0x3693, 0x3683,
    0x3673, 0x3663, 0x3654, 0x3644, 0x3634, 0x3624, 0x3614, 0x3604,
    0x35F4, 0x35E5, 0x35D5, 0x35C5, 0x35B5, 0x35A5, 0x3595, 0x3586,
    0x3576, 0x3566, 0x3556, 0x3546, 0x3536, 0x3527, 0x3517, 0x3507,
    0x34F7, 0x34E7, 0x34D7, 0x34C8, 0x34B8, 0x34A8, 0x3498, 0x3488,
    0x3478, 0x3468, 0x3459, 0x3449, 0x3439, 0x3429, 0x3419, 0x3409,
    0x33FA, 0x33EA, 0x33DA, 0x33CA, 0x33BA, 0x33AA, 0x339B, 0x338B,
    0x337B, 0x336B, 0x335B, 0x334B, 0x333C, 0x332C, 0x331C, 0x330C,
    0x32FC, 0x32EC, 0x32DC, 0x32CD, 0x32BD, 0x32AD, 0x329D, 0x328D,
    0x327D, 0x326E, 0x325E, 0x324E, 0x323E, 0x322E, 0x321E, 0x320F,
    0x31FF, 0x31EF, 0x31DF, 0x31CF, 0x31BF, 0x31B0, 0x31A0, 0x3190,
    0x3180, 0x3170, 0x3160, 0x3150, 0x3141, 0x3131, 0x3121, 0x3111,
    0x3101, 0x30F1, 0x30E2, 0x30D2, 0x30C2, 0x30B2, 0x30A2, 0x3092,
    0x3083, 0x3073, 0x3063, 0x3053, 0x3043, 0x3033, 0x3024, 0x3014,
    0x3004, 0x2FF4, 0x2FE4, 0x2FD4, 0x2FC4, 0x2FB5, 0x2FA5, 0x2F95,
    0x2F85, 0x2F75, 0x2F65, 0x2F56, 0x2F46, 0x2F36, 0x2F26, 0x2F16,
    0x2F06, 0x2EF7, 0x2EE7, 0x2ED7, 0x2EC7, 0x2EB7, 0x2EA7, 0x2E98,
    0x2E88, 0x2E78, 0x2E68, 0x2E58, 0x2E48, 0x2E38, 0x2E29, 0x2E19,
    0x2E09, 0x2DF9, 0x2DE9, 0x2DD9, 0x2DCA, 0x2DBA, 0x2DAA, 0x2D9A,
    0x2D8A, 0x2D7A, 0x2D6B, 0x2D5B, 0x2D4B, 0x2D3B, 0x2D2B, 0x2D1B,
    0x2D0C, 0x2CFC, 0x2CEC, 0x2CDC, 0x2CCC, 0x2CBC, 0x2CAC, 0x2C9D,
    0x2C8D, 0x2C7D, 0x2C6D, 0x2C5D, 0x2C4D, 0x2C3E, 0x2C2E, 0x2C1E,
    0x2C0E, 0x2BFE, 0x2BEE, 0x2BDF, 0x2BCF, 0x2BBF, 0x2BAF, 0x2B9F,
    0x2B8F, 0x2B80, 0x2B70, 0x2B60, 0x2B50, 0x2B40, 0x2B30, 0x2B20,
    0x2B11, 0x2B01, 0x2AF1, 0x2AE1, 0x2AD1, 0x2AC1, 0x2AB2, 0x2AA2,
    0x2A92, 0x2A82, 0x2A72, 0x2A62, 0x2A53, 0x2A43, 0x2A33, 0x2A23,
    0x2A13, 0x2A03, 0x29F4, 0x29E4, 0x29D4, 0x29C4, 0x29B4, 0x29A4,
    0x2994, 0x2985, 0x2975, 0x2965, 0x2955, 0x2945, 0x2935, 0x2926,
    0x2916, 0x2906, 0x28F6, 0x28E6, 0x28D6, 0x28C7, 0x28B7, 0x28A7,
    0x2897, 0x2887, 0x2877, 0x2868, 0x2858, 0x2848, 0x2838, 0x2828,
    0x2818, 0x2808, 0x27F9, 0x27E9, 0x27D9, 0x27C9, 0x27B9, 0x27A9,
    0x279A, 0x278A, 0x277A, 0x276A, 0x275A, 0x274A, 0x273B, 0x272B,
    0x271B, 0x270B, 0x26FB, 0x26EB, 0x26DC, 0x26CC, 0x26BC, 0x26AC,
    0x269C, 0x268C, 0x267C, 0x266D, 0x265D, 0x264D, 0x263D, 0x262D,
    0x261D, 0x260E, 0x25FE, 0x25EE, 0x25DE, 0x25CE, 0x25BE, 0x25AF,
    0x259F, 0x258F, 0x257F, 0x256F, 0x255F, 0x2550, 0x2540, 0x2530,
    0x2520, 0x2510, 0x2500, 0x24F0, 0x24E1, 0x24D1, 0x24C1, 0x24B1,
    0x24A1, 0x2491, 0x2482, 0x2472, 0x2462, 0x2452, 0x2442, 0x2432,
    0x2423, 0x2413, 0x2403, 0x23F3, 0x23E3, 0x23D3, 0x23C4, 0x23B4,
    0x23A4, 0x2394, 0x2384, 0x2374, 0x2364, 0x2355, 0x2345, 0x2335,
    0x2325, 0x2315, 0x2305, 0x22F6, 0x22E6, 0x22D6, 0x22C6, 0x22B6,
    0x22A6, 0x2297, 0x2287, 0x2277, 0x2267, 0x2257, 0x2247, 0x2238,
    0x2228, 0x2218, 0x2208, 0x21F8, 0x21E8, 0x21D8, 0x21C9, 0x21B9,
    0x21A9, 0x2199, 0x2189, 0x2179, 0x216A, 0x215A, 0x214A, 0x213A,
    0x212A, 0x211A, 0x210B, 0x20FB, 0x20EB, 0x20DB, 0x20CB, 0x20BB,
    0x20AC, 0x209C, 0x208C, 0x207C, 0x206C, 0x205C, 0x204C, 0x203D,
    0x202D, 0x201D, 0x200D, 0x1FFD, 0x1FED, 0x1FDE, 0x1FCE, 0x1FBE,
    0x1FAE, 0x1F9E, 0x1F8E, 0x1F7F, 0x1F6F, 0x1F5F, 0x1F4F, 0x1F3F,
    0x1F2F, 0x1F20, 0x1F10, 0x1F00, 0x1EF0, 0x1EE0, 0x1ED0, 0x1EC0,
    0x1EB1, 0x1EA1, 0x1E91, 0x1E81, 0x1E71, 0x1E61, 0x1E52, 0x1E42,
    0x1E32, 0x1E22, 0x1E12, 0x1E02, 0x1DF3, 0x1DE3, 0x1DD3, 0x1DC3,
    0x1DB3, 0x1DA3, 0x1D94, 0x1D84, 0x1D74, 0x1D64, 0x1D54, 0x1D44,
    0x1D34, 0x1D25, 0x1D15, 0x1D05, 0x1CF5, 0x1CE5, 0x1CD5, 0x1CC6,
    0x1CB6, 0x1CA6, 0x1C96, 0x1C86, 0x1C76, 0x1C67, 0x1C57, 0x1C47,
    0x1C37, 0x1C27, 0x1C17, 0x1C08, 0x1BF8, 0x1BE8, 0x1BD8, 0x1BC8,
    0x1BB8, 0x1BA8, 0x1B99, 0x1B89, 0x1B79, 0x1B69, 0x1B59, 0x1B49,
    0x1B3A, 0x1B2A, 0x1B1A, 0x1B0A, 0x1AFA, 0x1AEA, 0x1ADB, 0x1ACB,
    0x1ABB, 0x1AAB, 0x1A9B, 0x1A8B, 0x1A7C, 0x1A6C, 0x1A5C, 0x1A4C,
    0x1A3C, 0x1A2C, 0x1A1C, 0x1A0D, 0x19FD, 0x19ED, 0x19DD, 0x19CD,
    0x19BD, 0x19AE, 0x199E, 0x198E, 0x197E, 0x196E, 0x195E, 0x194F,
    0x193F, 0x192F, 0x191F, 0x190F, 0x18FF, 0x18F0, 0x18E0, 0x18D0,
    0x18C0, 0x18B0, 0x18A0, 0x1890, 0x1881, 0x1871, 0x1861, 0x1851,
    0x1841, 0x1831, 0x1822, 0x1812, 0x1802, 0x17F2, 0x17E2, 0x17D2,
    0x17C3, 0x17B3, 0x17A3, 0x1793, 0x1783, 0x1773, 0x1764, 0x1754,
    0x1744, 0x1734, 0x1724, 0x1714, 0x1704, 0x16F5, 0x16E5, 0x16D5,
    0x16C5, 0x16B5, 0x16A5, 0x1696, 0x1686, 0x1676, 0x1666, 0x1656,
    0x1646, 0x1637, 0x1627, 0x1617, 0x1607, 0x15F7, 0x15E7, 0x15D8,
    0x15C8, 0x15B8, 0x15A8, 0x1598, 0x1588, 0x1578, 0x1569, 0x1559,
    0x1549, 0x1539, 0x1529, 0x1519, 0x150A, 0x14FA, 0x14EA, 0x14DA,
    0x14CA, 0x14BA, 0x14AB, 0x149B, 0x148B, 0x147B, 0x146B, 0x145B,
    0x144C, 0x143C, 0x142C, 0x141C, 0x140C, 0x13FC, 0x13EC, 0x13DD,
    0x13CD, 0x13BD, 0x13AD, 0x139D, 0x138D, 0x137E, 0x136E, 0x135E,
    0x134E, 0x133E, 0x132E, 0x131F, 0x130F, 0x12FF, 0x12EF, 0x12DF,
    0x12CF, 0x12C0, 0x12B0, 0x12A0, 0x1290, 0x1280, 0x1270, 0x1260,
    0x1251, 0x1241, 0x1231, 0x1221, 0x1211, 0x1201, 0x11F2, 0x11E2,
    0x11D2, 0x11C2, 0x11B2, 0x11A2, 0x1193, 0x1183, 0x1173, 0x1163,
    0x1153, 0x1143, 0x1134, 0x1124, 0x1114, 0x1104, 0x10F4, 0x10E4,
    0x10D4, 0x10C5, 0x10B5, 0x10A5, 0x1095, 0x1085, 0x1075, 0x1066,
    0x1056, 0x1046, 0x1036, 0x1026, 0x1016, 0x1007, 0x0FF7, 0x0FE7,
    0x0FD7, 0x0FC7, 0x0FB7, 0x0FA8, 0x0F98, 0x0F88, 0x0F78, 0x0F68,
    0x0F58, 0x0F48, 0x0F39, 0x0F29, 0x0F19, 0x0F09, 0x0EF9, 0x0EE9,
    0x0EDA, 0x0ECA, 0x0EBA, 0x0EAA, 0x0E9A, 0x0E8A, 0x0E7B, 0x0E6B,
    0x0E5B, 0x0E4B, 0x0E3B, 0x0E2B, 0x0E1C, 0x0E0C, 0x0DFC, 0x0DEC,
    0x0DDC, 0x0DCC, 0x0DBC, 0x0DAD, 0x0D9D, 0x0D8D, 0x0D7D, 0x0D6D,
    0x0D5D, 0x0D4E, 0x0D3E, 0x0D2E, 0x0D1E, 0x0D0E, 0x0CFE, 0x0CEF,
    0x0CDF, 0x0CCF, 0x0CBF, 0x0CAF, 0x0C9F, 0x0C90, 0x0C80, 0x0C70,
    0x0C60, 0x0C50, 0x0C40, 0x0C30, 0x0C21, 0x0C11, 0x0C01, 0x0BF1,
    0x0BE1, 0x0BD1, 0x0BC2, 0x0BB2, 0x0BA2, 0x0B92, 0x0B82, 0x0B72,
    0x0B63, 0x0B53, 0x0B43, 0x0B33, 0x0B23, 0x0B13, 0x0B04, 0x0AF4,
    0x0AE4, 0x0AD4, 0x0AC4, 0x0AB4, 0x0AA4, 0x0A95, 0x0A85, 0x0A75,
    0x0A65, 0x0A55, 0x0A45, 0x0A36, 0x0A26, 0x0A16, 0x0A06, 0x09F6,
    0x09E6, 0x09D7, 0x09C7, 0x09B7, 0x09A7, 0x0997, 0x0987, 0x0978,
    0x0968, 0x0958, 0x0948, 0x0938, 0x0928, 0x0918, 0x0909, 0x08F9,
    0x08E9, 0x08D9, 0x08C9, 0x08B9, 0x08AA, 0x089A, 0x088A, 0x087A,
    0x086A, 0x085A, 0x084B, 0x083B, 0x082B, 0x081B, 0x080B, 0x07FB,
    0x07EC, 0x07DC, 0x07CC, 0x07BC, 0x07AC, 0x079C, 0x078C, 0x077D,
    0x076D, 0x075D, 0x074D, 0x073D, 0x072D, 0x071E, 0x070E, 0x06FE,
    0x06EE, 0x06DE, 0x06CE, 0x06BF, 0x06AF, 0x069F, 0x068F, 0x067F,
    0x066F, 0x0660, 0x0650, 0x0640, 0x0630, 0x0620, 0x0610, 0x0600,
    0x05F1, 0x05E1, 0x05D1, 0x05C1, 0x05B1, 0x05A1, 0x0592, 0x0582,
    0x0572, 0x0562, 0x0552, 0x0542, 0x0533, 0x0523, 0x0513, 0x0503,
    0x04F3, 0x04E3, 0x04D4, 0x04C4, 0x04B4, 0x04A4, 0x0494, 0x0484,
    0x0474, 0x0465, 0x0455, 0x0445, 0x0435, 0x0425, 0x0415, 0x0406,
    0x03F6, 0x03E6, 0x03D6, 0x03C6, 0x03B6, 0x03A7, 0x0397, 0x0387,
    0x0377, 0x0367, 0x0357, 0x0348, 0x0338, 0x0328, 0x0318, 0x0308,
    0x02F8, 0x02E8, 0x02D9, 0x02C9, 0x02B9, 0x02A9, 0x0299, 0x0289,
    0x027A, 0x026A, 0x025A, 0x024A, 0x023A, 0x022A, 0x021B, 0x020B,
    0x01FB, 0x01EB, 0x01DB, 0x01CB, 0x01BC, 0x01AC, 0x019C, 0x018C,
    0x017C, 0x016C, 0x015C, 0x014D, 0x013D, 0x012D, 0x011D, 0x010D,
    0x00FD, 0x00EE, 0x00DE, 0x00CE, 0x00BE, 0x00AE, 0x009E, 0x008F,
    0x007F, 0x006F, 0x005F, 0x004F, 0x003F, 0x0030, 0x0020, 0x0010,
    0x0000, 0xFFF0, 0xFFE0, 0xFFD0, 0xFFC1, 0xFFB1, 0xFFA1, 0xFF91,
    0xFF81, 0xFF71, 0xFF62, 0xFF52, 0xFF42, 0xFF32, 0xFF22, 0xFF12,
    0xFF03, 0xFEF3, 0xFEE3, 0xFED3, 0xFEC3, 0xFEB3, 0xFEA4, 0xFE94,
    0xFE84, 0xFE74, 0xFE64, 0xFE54, 0xFE44, 0xFE35, 0xFE25, 0xFE15,
    0xFE05, 0xFDF5, 0xFDE5, 0xFDD6, 0xFDC6, 0xFDB6, 0xFDA6, 0xFD96,
    0xFD86, 0xFD77, 0xFD67, 0xFD57, 0xFD47, 0xFD37, 0xFD27, 0xFD18,
    0xFD08, 0xFCF8, 0xFCE8, 0xFCD8, 0xFCC8, 0xFCB8, 0xFCA9, 0xFC99,
    0xFC89, 0xFC79, 0xFC69, 0xFC59, 0xFC4A, 0xFC3A, 0xFC2A, 0xFC1A,
    0xFC0A, 0xFBFA, 0xFBEB, 0xFBDB, 0xFBCB, 0xFBBB, 0xFBAB, 0xFB9B,
    0xFB8C, 0xFB7C, 0xFB6C, 0xFB5C, 0xFB4C, 0xFB3C, 0xFB2C, 0xFB1D,
    0xFB0D, 0xFAFD, 0xFAED, 0xFADD, 0xFACD, 0xFABE, 0xFAAE, 0xFA9E,
    0xFA8E, 0xFA7E, 0xFA6E, 0xFA5F, 0xFA4F, 0xFA3F, 0xFA2F, 0xFA1F,
    0xFA0F, 0xFA00, 0xF9F0, 0xF9E0, 0xF9D0, 0xF9C0, 0xF9B0, 0xF9A0,
    0xF991, 0xF981, 0xF971, 0xF961, 0xF951, 0xF941, 0xF932, 0xF922,
    0xF912, 0xF902, 0xF8F2, 0xF8E2, 0xF8D3, 0xF8C3, 0xF8B3, 0xF8A3,
    0xF893, 0xF883, 0xF874, 0xF864, 0xF854, 0xF844, 0xF834, 0xF824,
    0xF814, 0xF805, 0xF7F5, 0xF7E5, 0xF7D5, 0xF7C5, 0xF7B5, 0xF7A6,
    0xF796, 0xF786, 0xF776, 0xF766, 0xF756, 0xF747, 0xF737, 0xF727,
    0xF717, 0xF707, 0xF6F7, 0xF6E8, 0xF6D8, 0xF6C8, 0xF6B8, 0xF6A8,
    0xF698, 0xF688, 0xF679, 0xF669, 0xF659, 0xF649, 0xF639, 0xF629,
    0xF61A, 0xF60A, 0xF5FA, 0xF5EA, 0xF5DA, 0xF5CA, 0xF5BB, 0xF5AB,
    0xF59B, 0xF58B, 0xF57B, 0xF56B, 0xF55C, 0xF54C, 0xF53C, 0xF52C,
    0xF51C, 0xF50C, 0xF4FC, 0xF4ED, 0xF4DD, 0xF4CD, 0xF4BD, 0xF4AD,
    0xF49D, 0xF48E, 0xF47E, 0xF46E, 0xF45E, 0xF44E, 0xF43E, 0xF42F,
    0xF41F, 0xF40F, 0xF3FF, 0xF3EF, 0xF3DF, 0xF3D0, 0xF3C0, 0xF3B0,
    0xF3A0, 0xF390, 0xF380, 0xF370, 0xF361, 0xF351, 0xF341, 0xF331,
    0xF321, 0xF311, 0xF302, 0xF2F2, 0xF2E2, 0xF2D2, 0xF2C2, 0xF2B2,
    0xF2A3, 0xF293, 0xF283, 0xF273, 0xF263, 0xF253, 0xF244, 0xF234,
    0xF224, 0xF214, 0xF204, 0xF1F4, 0xF1E4, 0xF1D5, 0xF1C5, 0xF1B5,
    0xF1A5, 0xF195, 0xF185, 0xF176, 0xF166, 0xF156, 0xF146, 0xF136,
    0xF126, 0xF117, 0xF107, 0xF0F7, 0xF0E7, 0xF0D7, 0xF0C7, 0xF0B8,
    0xF0A8, 0xF098, 0xF088, 0xF078, 0xF068, 0xF058, 0xF049, 0xF039,
    0xF029, 0xF019, 0xF009, 0xEFF9, 0xEFEA, 0xEFDA, 0xEFCA, 0xEFBA,
    0xEFAA, 0xEF9A, 0xEF8B, 0xEF7B, 0xEF6B, 0xEF5B, 0xEF4B, 0xEF3B,
    0xEF2C, 0xEF1C, 0xEF0C, 0xEEFC, 0xEEEC, 0xEEDC, 0xEECC, 0xEEBD,
    0xEEAD, 0xEE9D, 0xEE8D, 0xEE7D, 0xEE6D, 0xEE5E, 0xEE4E, 0xEE3E,
    0xEE2E, 0xEE1E, 0xEE0E, 0xEDFF, 0xEDEF, 0xEDDF, 0xEDCF, 0xEDBF,
    0xEDAF, 0xEDA0, 0xED90, 0xED80, 0xED70, 0xED60, 0xED50, 0xED40,
    0xED31, 0xED21, 0xED11, 0xED01, 0xECF1, 0xECE1, 0xECD2, 0xECC2,
    0xECB2, 0xECA2, 0xEC92, 0xEC82, 0xEC73, 0xEC63, 0xEC53, 0xEC43,
    0xEC33, 0xEC23, 0xEC14, 0xEC04, 0xEBF4, 0xEBE4, 0xEBD4, 0xEBC4,
    0xEBB4, 0xEBA5, 0xEB95, 0xEB85, 0xEB75, 0xEB65, 0xEB55, 0xEB46,
    0xEB36, 0xEB26, 0xEB16, 0xEB06, 0xEAF6, 0xEAE7, 0xEAD7, 0xEAC7,
    0xEAB7, 0xEAA7, 0xEA97, 0xEA88, 0xEA78, 0xEA68, 0xEA58, 0xEA48,
    0xEA38, 0xEA28, 0xEA19, 0xEA09, 0xE9F9, 0xE9E9, 0xE9D9, 0xE9C9,
    0xE9BA, 0xE9AA, 0xE99A, 0xE98A, 0xE97A, 0xE96A, 0xE95B, 0xE94B,
    0xE93B, 0xE92B, 0xE91B, 0xE90B, 0xE8FC, 0xE8EC, 0xE8DC, 0xE8CC,
    0xE8BC, 0xE8AC, 0xE89C, 0xE88D, 0xE87D, 0xE86D, 0xE85D, 0xE84D,
    0xE83D, 0xE82E, 0xE81E, 0xE80E, 0xE7FE, 0xE7EE, 0xE7DE, 0xE7CF,
    0xE7BF, 0xE7AF, 0xE79F, 0xE78F, 0xE77F, 0xE770, 0xE760, 0xE750,
    0xE740, 0xE730, 0xE720, 0xE710, 0xE701, 0xE6F1, 0xE6E1, 0xE6D1,
    0xE6C1, 0xE6B1, 0xE6A2, 0xE692, 0xE682, 0xE672, 0xE662, 0xE652,
    0xE643, 0xE633, 0xE623, 0xE613, 0xE603, 0xE5F3, 0xE5E4, 0xE5D4,
    0xE5C4, 0xE5B4, 0xE5A4, 0xE594, 0xE584, 0xE575, 0xE565, 0xE555,
    0xE545, 0xE535, 0xE525, 0xE516, 0xE506, 0xE4F6, 0xE4E6, 0xE4D6,
    0xE4C6, 0xE4B7, 0xE4A7, 0xE497, 0xE487, 0xE477, 0xE467, 0xE458,
    0xE448, 0xE438, 0xE428, 0xE418, 0xE408, 0xE3F8, 0xE3E9, 0xE3D9,
    0xE3C9, 0xE3B9, 0xE3A9, 0xE399, 0xE38A, 0xE37A, 0xE36A, 0xE35A,
    0xE34A, 0xE33A, 0xE32B, 0xE31B, 0xE30B, 0xE2FB, 0xE2EB, 0xE2DB,
    0xE2CC, 0xE2BC, 0xE2AC, 0xE29C, 0xE28C, 0xE27C, 0xE26C, 0xE25D,
    0xE24D, 0xE23D, 0xE22D, 0xE21D, 0xE20D, 0xE1FE, 0xE1EE, 0xE1DE,
    0xE1CE, 0xE1BE, 0xE1AE, 0xE19F, 0xE18F, 0xE17F, 0xE16F, 0xE15F,
    0xE14F, 0xE140, 0xE130, 0xE120, 0xE110, 0xE100, 0xE0F0, 0xE0E0,
    0xE0D1, 0xE0C1, 0xE0B1, 0xE0A1, 0xE091, 0xE081, 0xE072, 0xE062,
    0xE052, 0xE042, 0xE032, 0xE022, 0xE013, 0xE003, 0xDFF3, 0xDFE3,
    0xDFD3, 0xDFC3, 0xDFB4, 0xDFA4, 0xDF94, 0xDF84, 0xDF74, 0xDF64,
    0xDF54, 0xDF45, 0xDF35, 0xDF25, 0xDF15, 0xDF05, 0xDEF5, 0xDEE6,
    0xDED6, 0xDEC6, 0xDEB6, 0xDEA6, 0xDE96, 0xDE87, 0xDE77, 0xDE67,
    0xDE57, 0xDE47, 0xDE37, 0xDE28, 0xDE18, 0xDE08, 0xDDF8, 0xDDE8,
    0xDDD8, 0xDDC8, 0xDDB9, 0xDDA9, 0xDD99, 0xDD89, 0xDD79, 0xDD69,
    0xDD5A, 0xDD4A, 0xDD3A, 0xDD2A, 0xDD1A, 0xDD0A, 0xDCFB, 0xDCEB,
    0xDCDB, 0xDCCB, 0xDCBB, 0xDCAB, 0xDC9C, 0xDC8C, 0xDC7C, 0xDC6C,
    0xDC5C, 0xDC4C, 0xDC3C, 0xDC2D, 0xDC1D, 0xDC0D, 0xDBFD, 0xDBED,
    0xDBDD, 0xDBCE, 0xDBBE, 0xDBAE, 0xDB9E, 0xDB8E, 0xDB7E, 0xDB6F,
    0xDB5F, 0xDB4F, 0xDB3F, 0xDB2F, 0xDB1F, 0xDB10, 0xDB00, 0xDAF0,
    0xDAE0, 0xDAD0, 0xDAC0, 0xDAB0, 0xDAA1, 0xDA91, 0xDA81, 0xDA71,
    0xDA61, 0xDA51, 0xDA42, 0xDA32, 0xDA22, 0xDA12, 0xDA02, 0xD9F2,
    0xD9E3, 0xD9D3, 0xD9C3, 0xD9B3, 0xD9A3, 0xD993, 0xD984, 0xD974,
    0xD964, 0xD954, 0xD944, 0xD934, 0xD924, 0xD915, 0xD905, 0xD8F5,
    0xD8E5, 0xD8D5, 0xD8C5, 0xD8B6, 0xD8A6, 0xD896, 0xD886, 0xD876,
    0xD866, 0xD857, 0xD847, 0xD837, 0xD827, 0xD817, 0xD807, 0xD7F8,
    0xD7E8, 0xD7D8, 0xD7C8, 0xD7B8, 0xD7A8, 0xD798, 0xD789, 0xD779,
    0xD769, 0xD759, 0xD749, 0xD739, 0xD72A, 0xD71A, 0xD70A, 0xD6FA,
    0xD6EA, 0xD6DA, 0xD6CB, 0xD6BB, 0xD6AB, 0xD69B, 0xD68B, 0xD67B,
    0xD66C, 0xD65C, 0xD64C, 0xD63C, 0xD62C, 0xD61C, 0xD60C, 0xD5FD,
    0xD5ED, 0xD5DD, 0xD5CD, 0xD5BD, 0xD5AD, 0xD59E, 0xD58E, 0xD57E,
    0xD56E, 0xD55E, 0xD54E, 0xD53F, 0xD52F, 0xD51F, 0xD50F, 0xD4FF,
    0xD4EF, 0xD4E0, 0xD4D0, 0xD4C0, 0xD4B0, 0xD4A0, 0xD490, 0xD480,
    0xD471, 0xD461, 0xD451, 0xD441, 0xD431, 0xD421, 0xD412, 0xD402,
    0xD3F2, 0xD3E2, 0xD3D2, 0xD3C2, 0xD3B3, 0xD3A3, 0xD393, 0xD383,
    0xD373, 0xD363, 0xD354, 0xD344, 0xD334, 0xD324, 0xD314, 0xD304,
    0xD2F4, 0xD2E5, 0xD2D5, 0xD2C5, 0xD2B5, 0xD2A5, 0xD295, 0xD286,
    0xD276, 0xD266, 0xD256, 0xD246, 0xD236, 0xD227, 0xD217, 0xD207,
    0xD1F7, 0xD1E7, 0xD1D7, 0xD1C8, 0xD1B8, 0xD1A8, 0xD198, 0xD188,
    0xD178, 0xD168, 0xD159, 0xD149, 0xD139, 0xD129, 0xD119, 0xD109,
    0xD0FA, 0xD0EA, 0xD0DA, 0xD0CA, 0xD0BA, 0xD0AA, 0xD09B, 0xD08B,
    0xD07B, 0xD06B, 0xD05B, 0xD04B, 0xD03C, 0xD02C, 0xD01C, 0xD00C,
    0xCFFC, 0xCFEC, 0xCFDC, 0xCFCD, 0xCFBD, 0xCFAD, 0xCF9D, 0xCF8D,
    0xCF7D, 0xCF6E, 0xCF5E, 0xCF4E, 0xCF3E, 0xCF2E, 0xCF1E, 0xCF0F,
    0xCEFF, 0xCEEF, 0xCEDF, 0xCECF, 0xCEBF, 0xCEB0, 0xCEA0, 0xCE90,
    0xCE80, 0xCE70, 0xCE60, 0xCE50, 0xCE41, 0xCE31, 0xCE21, 0xCE11,
    0xCE01, 0xCDF1, 0xCDE2, 0xCDD2, 0xCDC2, 0xCDB2, 0xCDA2, 0xCD92,
    0xCD83, 0xCD73, 0xCD63, 0xCD53, 0xCD43, 0xCD33, 0xCD24, 0xCD14,
    0xCD04, 0xCCF4, 0xCCE4, 0xCCD4, 0xCCC4, 0xCCB5, 0xCCA5, 0xCC95,
    0xCC85, 0xCC75, 0xCC65, 0xCC56, 0xCC46, 0xCC36, 0xCC26, 0xCC16,
    0xCC06, 0xCBF7, 0xCBE7, 0xCBD7, 0xCBC7, 0xCBB7, 0xCBA7, 0xCB98,
    0xCB88, 0xCB78, 0xCB68, 0xCB58, 0xCB48, 0xCB38, 0xCB29, 0xCB19,
    0xCB09, 0xCAF9, 0xCAE9, 0xCAD9, 0xCACA, 0xCABA, 0xCAAA, 0xCA9A,
    0xCA8A, 0xCA7A, 0xCA6B, 0xCA5B, 0xCA4B, 0xCA3B, 0xCA2B, 0xCA1B,
    0xCA0C, 0xC9FC, 0xC9EC, 0xC9DC, 0xC9CC, 0xC9BC, 0xC9AC, 0xC99D,
    0xC98D, 0xC97D, 0xC96D, 0xC95D, 0xC94D, 0xC93E, 0xC92E, 0xC91E,
    0xC90E, 0xC8FE, 0xC8EE, 0xC8DF, 0xC8CF, 0xC8BF, 0xC8AF, 0xC89F,
    0xC88F, 0xC880, 0xC870, 0xC860, 0xC850, 0xC840, 0xC830, 0xC820,
    0xC811, 0xC801, 0xC7F1, 0xC7E1, 0xC7D1, 0xC7C1, 0xC7B2, 0xC7A2,
    0xC792, 0xC782, 0xC772, 0xC762, 0xC753, 0xC743, 0xC733, 0xC723,
    0xC713, 0xC703, 0xC6F4, 0xC6E4, 0xC6D4, 0xC6C4, 0xC6B4, 0xC6A4,
    0xC694, 0xC685, 0xC675, 0xC665, 0xC655, 0xC645, 0xC635, 0xC626,
    0xC616, 0xC606, 0xC5F6, 0xC5E6, 0xC5D6, 0xC5C7, 0xC5B7, 0xC5A7,
    0xC597, 0xC587, 0xC577, 0xC568, 0xC558, 0xC548, 0xC538, 0xC528,
    0xC518, 0xC508, 0xC4F9, 0xC4E9, 0xC4D9, 0xC4C9, 0xC4B9, 0xC4A9,
    0xC49A, 0xC48A, 0xC47A, 0xC46A, 0xC45A, 0xC44A, 0xC43B, 0xC42B,
    0xC41B, 0xC40B, 0xC3FB, 0xC3EB, 0xC3DC, 0xC3CC, 0xC3BC, 0xC3AC,
    0xC39C, 0xC38C, 0xC37C, 0xC36D, 0xC35D, 0xC34D, 0xC33D, 0xC32D,
    0xC31D, 0xC30E, 0xC2FE, 0xC2EE, 0xC2DE, 0xC2CE, 0xC2BE, 0xC2AF,
    0xC29F, 0xC28F, 0xC27F, 0xC26F, 0xC25F, 0xC250, 0xC240, 0xC230,
    0xC220, 0xC210, 0xC200, 0xC1F0, 0xC1E1, 0xC1D1, 0xC1C1, 0xC1B1,
    0xC1A1, 0xC191, 0xC182, 0xC172, 0xC162, 0xC152, 0xC142, 0xC132,
    0xC123, 0xC113, 0xC103, 0xC0F3, 0xC0E3, 0xC0D3, 0xC0C4, 0xC0B3,
    0xC0A7, 0xC0B3, 0xC0C4, 0xC0D3, 0xC0E3, 0xC0F3, 0xC103, 0xC113,
    0xC123, 0xC132, 0xC142, 0xC152, 0xC162, 0xC172, 0xC182, 0xC191,
    0xC1A1, 0xC1B1, 0xC1C1, 0xC1D1, 0xC1E1, 0xC1F0, 0xC200, 0xC210,
    0xC220, 0xC230, 0xC240, 0xC250, 0xC25F, 0xC26F, 0xC27F, 0xC28F,
    0xC29F, 0xC2AF, 0xC2BE, 0xC2CE, 0xC2DE, 0xC2EE, 0xC2FE, 0xC30E,
    0xC31D, 0xC32D, 0xC33D, 0xC34D, 0xC35D, 0xC36D, 0xC37C, 0xC38C,
    0xC39C, 0xC3AC, 0xC3BC, 0xC3CC, 0xC3DC, 0xC3EB, 0xC3FB, 0xC40B,
    0xC41B, 0xC42B, 0xC43B, 0xC44A, 0xC45A, 0xC46A, 0xC47A, 0xC48A,
    0xC49A, 0xC4A9, 0xC4B9, 0xC4C9, 0xC4D9, 0xC4E9, 0xC4F9, 0xC508,
    0xC518, 0xC528, 0xC538, 0xC548, 0xC558, 0xC568, 0xC577, 0xC587,
    0xC597, 0xC5A7, 0xC5B7, 0xC5C7, 0xC5D6, 0xC5E6, 0xC5F6, 0xC606,
    0xC616, 0xC626, 0xC635, 0xC645, 0xC655, 0xC665, 0xC675, 0xC685,
    0xC694, 0xC6A4, 0xC6B4, 0xC6C4, 0xC6D4, 0xC6E4, 0xC6F4, 0xC703,
    0xC713, 0xC723, 0xC733, 0xC743, 0xC753, 0xC762, 0xC772, 0xC782,
    0xC792, 0xC7A2, 0xC7B2, 0xC7C1, 0xC7D1, 0xC7E1, 0xC7F1, 0xC801,
    0xC811, 0xC820, 0xC830, 0xC840, 0xC850, 0xC860, 0xC870, 0xC880,
    0xC88F, 0xC89F, 0xC8AF, 0xC8BF, 0xC8CF, 0xC8DF, 0xC8EE, 0xC8FE,
    0xC90E, 0xC91E, 0xC92E, 0xC93E, 0xC94D, 0xC95D, 0xC96D, 0xC97D,
    0xC98D, 0xC99D, 0xC9AC, 0xC9BC, 0xC9CC, 0xC9DC, 0xC9EC, 0xC9FC,
    0xCA0C, 0xCA1B, 0xCA2B, 0xCA3B, 0xCA4B, 0xCA5B, 0xCA6B, 0xCA7A,
    0xCA8A, 0xCA9A, 0xCAAA, 0xCABA, 0xCACA, 0xCAD9, 0xCAE9, 0xCAF9,
    0xCB09, 0xCB19, 0xCB29, 0xCB38, 0xCB48, 0xCB58, 0xCB68, 0xCB78,
    0xCB88, 0xCB98, 0xCBA7, 0xCBB7, 0xCBC7, 0xCBD7, 0xCBE7, 0xCBF7,
    0xCC06, 0xCC16, 0xCC26, 0xCC36, 0xCC46, 0xCC56, 0xCC65, 0xCC75,
    0xCC85, 0xCC95, 0xCCA5, 0xCCB5, 0xCCC4, 0xCCD4, 0xCCE4, 0xCCF4,
    0xCD04, 0xCD14, 0xCD24, 0xCD33, 0xCD43, 0xCD53, 0xCD63, 0xCD73,
    0xCD83, 0xCD92, 0xCDA2, 0xCDB2, 0xCDC2, 0xCDD2, 0xCDE2, 0xCDF1,
    0xCE01, 0xCE11, 0xCE21, 0xCE31, 0xCE41, 0xCE50, 0xCE60, 0xCE70,
    0xCE80, 0xCE90, 0xCEA0, 0xCEB0, 0xCEBF, 0xCECF, 0xCEDF, 0xCEEF,
    0xCEFF, 0xCF0F, 0xCF1E, 0xCF2E, 0xCF3E, 0xCF4E, 0xCF5E, 0xCF6E,
    0xCF7D, 0xCF8D, 0xCF9D, 0xCFAD, 0xCFBD, 0xCFCD, 0xCFDC, 0xCFEC,
    0xCFFC, 0xD00C, 0xD01C, 0xD02C, 0xD03C, 0xD04B, 0xD05B, 0xD06B,
    0xD07B, 0xD08B, 0xD09B, 0xD0AA, 0xD0BA, 0xD0CA, 0xD0DA, 0xD0EA,
    0xD0FA, 0xD109, 0xD119, 0xD129, 0xD139, 0xD149, 0xD159, 0xD168,
    0xD178, 0xD188, 0xD198, 0xD1A8, 0xD1B8, 0xD1C8, 0xD1D7, 0xD1E7,
    0xD1F7, 0xD207, 0xD217, 0xD227, 0xD236, 0xD246, 0xD256, 0xD266,
    0xD276, 0xD286, 0xD295, 0xD2A5, 0xD2B5, 0xD2C5, 0xD2D5, 0xD2E5,
    0xD2F4, 0xD304, 0xD314, 0xD324, 0xD334, 0xD344, 0xD354, 0xD363,
    0xD373, 0xD383, 0xD393, 0xD3A3, 0xD3B3, 0xD3C2, 0xD3D2, 0xD3E2,
    0xD3F2, 0xD402, 0xD412, 0xD421, 0xD431, 0xD441, 0xD451, 0xD461,
    0xD471, 0xD480, 0xD490, 0xD4A0, 0xD4B0, 0xD4C0, 0xD4D0, 0xD4E0,
    0xD4EF, 0xD4FF, 0xD50F, 0xD51F, 0xD52F, 0xD53F, 0xD54E, 0xD55E,
    0xD56E, 0xD57E, 0xD58E, 0xD59E, 0xD5AD, 0xD5BD, 0xD5CD, 0xD5DD,
    0xD5ED, 0xD5FD, 0xD60C, 0xD61C, 0xD62C, 0xD63C, 0xD64C, 0xD65C,
    0xD66C, 0xD67B, 0xD68B, 0xD69B, 0xD6AB, 0xD6BB, 0xD6CB, 0xD6DA,
    0xD6EA, 0xD6FA, 0xD70A, 0xD71A, 0xD72A, 0xD739, 0xD749, 0xD759,
    0xD769, 0xD779, 0xD789, 0xD798, 0xD7A8, 0xD7B8, 0xD7C8, 0xD7D8,
    0xD7E8, 0xD7F8, 0xD807, 0xD817, 0xD827, 0xD837, 0xD847, 0xD857,
    0xD866, 0xD876, 0xD886, 0xD896, 0xD8A6, 0xD8B6, 0xD8C5, 0xD8D5,
    0xD8E5, 0xD8F5, 0xD905, 0xD915, 0xD924, 0xD934, 0xD944, 0xD954,
    0xD964, 0xD974, 0xD984, 0xD993, 0xD9A3, 0xD9B3, 0xD9C3, 0xD9D3,
    0xD9E3, 0xD9F2, 0xDA02, 0xDA12, 0xDA22, 0xDA32, 0xDA42, 0xDA51,
    0xDA61, 0xDA71, 0xDA81, 0xDA91, 0xDAA1, 0xDAB0, 0xDAC0, 0xDAD0,
    0xDAE0, 0xDAF0, 0xDB00, 0xDB10, 0xDB1F, 0xDB2F, 0xDB3F, 0xDB4F,
    0xDB5F, 0xDB6F, 0xDB7E, 0xDB8E, 0xDB9E, 0xDBAE, 0xDBBE, 0xDBCE,
    0xDBDD, 0xDBED, 0xDBFD, 0xDC0D, 0xDC1D, 0xDC2D, 0xDC3C, 0xDC4C,
    0xDC5C, 0xDC6C, 0xDC7C, 0xDC8C, 0xDC9C, 0xDCAB, 0xDCBB, 0xDCCB,
    0xDCDB, 0xDCEB, 0xDCFB, 0xDD0A, 0xDD1A, 0xDD2A, 0xDD3A, 0xDD4A,
    0xDD5A, 0xDD69, 0xDD79, 0xDD89, 0xDD99, 0xDDA9, 0xDDB9, 0xDDC8,
    0xDDD8, 0xDDE8, 0xDDF8, 0xDE08, 0xDE18, 0xDE28, 0xDE37, 0xDE47,
    0xDE57, 0xDE67, 0xDE77, 0xDE87, 0xDE96, 0xDEA6, 0xDEB6, 0xDEC6,
    0xDED6, 0xDEE6, 0xDEF5, 0xDF05, 0xDF15, 0xDF25, 0xDF35, 0xDF45,
    0xDF54, 0xDF64, 0xDF74, 0xDF84, 0xDF94, 0xDFA4, 0xDFB4, 0xDFC3,
    0xDFD3, 0xDFE3, 0xDFF3, 0xE003, 0xE013, 0xE022, 0xE032, 0xE042,
    0xE052, 0xE062, 0xE072, 0xE081, 0xE091, 0xE0A1, 0xE0B1, 0xE0C1,
    0xE0D1, 0xE0E0, 0xE0F0, 0xE100, 0xE110, 0xE120, 0xE130, 0xE140,
    0xE14F, 0xE15F, 0xE16F, 0xE17F, 0xE18F, 0xE19F, 0xE1AE, 0xE1BE,
    0xE1CE, 0xE1DE, 0xE1EE, 0xE1FE, 0xE20D, 0xE21D, 0xE22D, 0xE23D,
    0xE24D, 0xE25D, 0xE26C, 0xE27C, 0xE28C, 0xE29C, 0xE2AC, 0xE2BC,
    0xE2CC, 0xE2DB, 0xE2EB, 0xE2FB, 0xE30B, 0xE31B, 0xE32B, 0xE33A,
    0xE34A, 0xE35A, 0xE36A, 0xE37A, 0xE38A, 0xE399, 0xE3A9, 0xE3B9,
    0xE3C9, 0xE3D9, 0xE3E9, 0xE3F8, 0xE408, 0xE418, 0xE428, 0xE438,
    0xE448, 0xE458, 0xE467, 0xE477, 0xE487, 0xE497, 0xE4A7, 0xE4B7,
    0xE4C6, 0xE4D6, 0xE4E6, 0xE4F6, 0xE506, 0xE516, 0xE525, 0xE535,
    0xE545, 0xE555, 0xE565, 0xE575, 0xE584, 0xE594, 0xE5A4, 0xE5B4,
    0xE5C4, 0xE5D4, 0xE5E4, 0xE5F3, 0xE603, 0xE613, 0xE623, 0xE633,
    0xE643, 0xE652, 0xE662, 0xE672, 0xE682, 0xE692, 0xE6A2, 0xE6B1,
    0xE6C1, 0xE6D1, 0xE6E1, 0xE6F1, 0xE701, 0xE710, 0xE720, 0xE730,
    0xE740, 0xE750, 0xE760, 0xE770, 0xE77F, 0xE78F, 0xE79F, 0xE7AF,
    0xE7BF, 0xE7CF, 0xE7DE, 0xE7EE, 0xE7FE, 0xE80E, 0xE81E, 0xE82E,
    0xE83D, 0xE84D, 0xE85D, 0xE86D, 0xE87D, 0xE88D, 0xE89C, 0xE8AC,
    0xE8BC, 0xE8CC, 0xE8DC, 0xE8EC, 0xE8FC, 0xE90B, 0xE91B, 0xE92B,
    0xE93B, 0xE94B, 0xE95B, 0xE96A, 0xE97A, 0xE98A, 0xE99A, 0xE9AA,
    0xE9BA, 0xE9C9, 0xE9D9, 0xE9E9, 0xE9F9, 0xEA09, 0xEA19, 0xEA28,
    0xEA38, 0xEA48, 0xEA58, 0xEA68, 0xEA78, 0xEA88, 0xEA97, 0xEAA7,
    0xEAB7, 0xEAC7, 0xEAD7, 0xEAE7, 0xEAF6, 0xEB06, 0xEB16, 0xEB26,
    0xEB36, 0xEB46, 0xEB55, 0xEB65, 0xEB75, 0xEB85, 0xEB95, 0xEBA5,
    0xEBB4, 0xEBC4, 0xEBD4, 0xEBE4, 0xEBF4, 0xEC04, 0xEC14, 0xEC23,
    0xEC33, 0xEC43, 0xEC53, 0xEC63, 0xEC73, 0xEC82, 0xEC92, 0xECA2,
    0xECB2, 0xECC2, 0xECD2, 0xECE1, 0xECF1, 0xED01, 0xED11, 0xED21,
    0xED31, 0xED40, 0xED50, 0xED60, 0xED70, 0xED80, 0xED90, 0xEDA0,
    0xEDAF, 0xEDBF, 0xEDCF, 0xEDDF, 0xEDEF, 0xEDFF, 0xEE0E, 0xEE1E,
    0xEE2E, 0xEE3E, 0xEE4E, 0xEE5E, 0xEE6D, 0xEE7D, 0xEE8D, 0xEE9D,
    0xEEAD, 0xEEBD, 0xEECC, 0xEEDC, 0xEEEC, 0xEEFC, 0xEF0C, 0xEF1C,
    0xEF2C, 0xEF3B, 0xEF4B, 0xEF5B, 0xEF6B, 0xEF7B, 0xEF8B, 0xEF9A,
    0xEFAA, 0xEFBA, 0xEFCA, 0xEFDA, 0xEFEA, 0xEFF9, 0xF009, 0xF019,
    0xF029, 0xF039, 0xF049, 0xF058, 0xF068, 0xF078, 0xF088, 0xF098,
    0xF0A8, 0xF0B8, 0xF0C7, 0xF0D7, 0xF0E7, 0xF0F7, 0xF107, 0xF117,
    0xF126, 0xF136, 0xF146, 0xF156, 0xF166, 0xF176, 0xF185, 0xF195,
    0xF1A5, 0xF1B5, 0xF1C5, 0xF1D5, 0xF1E4, 0xF1F4, 0xF204, 0xF214,
    0xF224, 0xF234, 0xF244, 0xF253, 0xF263, 0xF273, 0xF283, 0xF293,
    0xF2A3, 0xF2B2, 0xF2C2, 0xF2D2, 0xF2E2, 0xF2F2, 0xF302, 0xF311,
    0xF321, 0xF331, 0xF341, 0xF351, 0xF361, 0xF370, 0xF380, 0xF390,
    0xF3A0, 0xF3B0, 0xF3C0, 0xF3D0, 0xF3DF, 0xF3EF, 0xF3FF, 0xF40F,
    0xF41F, 0xF42F, 0xF43E, 0xF44E, 0xF45E, 0xF46E, 0xF47E, 0xF48E,
    0xF49D, 0xF4AD, 0xF4BD, 0xF4CD, 0xF4DD, 0xF4ED, 0xF4FC, 0xF50C,
    0xF51C, 0xF52C, 0xF53C, 0xF54C, 0xF55C, 0xF56B, 0xF57B, 0xF58B,
    0xF59B, 0xF5AB, 0xF5BB, 0xF5CA, 0xF5DA, 0xF5EA, 0xF5FA, 0xF60A,
    0xF61A, 0xF629, 0xF639, 0xF649, 0xF659, 0xF669, 0xF679, 0xF688,
    0xF698, 0xF6A8, 0xF6B8, 0xF6C8, 0xF6D8, 0xF6E8, 0xF6F7, 0xF707,
    0xF717, 0xF727, 0xF737, 0xF747, 0xF756, 0xF766, 0xF776, 0xF786,
    0xF796, 0xF7A6, 0xF7B5, 0xF7C5, 0xF7D5, 0xF7E5, 0xF7F5, 0xF805,
    0xF814, 0xF824, 0xF834, 0xF844, 0xF854, 0xF864, 0xF874, 0xF883,
    0xF893, 0xF8A3, 0xF8B3, 0xF8C3, 0xF8D3, 0xF8E2, 0xF8F2, 0xF902,
    0xF912, 0xF922, 0xF932, 0xF941, 0xF951, 0xF961, 0xF971, 0xF981,
    0xF991, 0xF9A0, 0xF9B0, 0xF9C0, 0xF9D0, 0xF9E0, 0xF9F0, 0xFA00,
    0xFA0F, 0xFA1F, 0xFA2F, 0xFA3F, 0xFA4F, 0xFA5F, 0xFA6E, 0xFA7E,
    0xFA8E, 0xFA9E, 0xFAAE, 0xFABE, 0xFACD, 0xFADD, 0xFAED, 0xFAFD,
    0xFB0D, 0xFB1D, 0xFB2C, 0xFB3C, 0xFB4C, 0xFB5C, 0xFB6C, 0xFB7C,
    0xFB8C, 0xFB9B, 0xFBAB, 0xFBBB, 0xFBCB, 0xFBDB, 0xFBEB, 0xFBFA,
    0xFC0A, 0xFC1A, 0xFC2A, 0xFC3A, 0xFC4A, 0xFC59, 0xFC69, 0xFC79,
    0xFC89, 0xFC99, 0xFCA9, 0xFCB8, 0xFCC8, 0xFCD8, 0xFCE8, 0xFCF8,
    0xFD08, 0xFD18, 0xFD27, 0xFD37, 0xFD47, 0xFD57, 0xFD67, 0xFD77,
    0xFD86, 0xFD96, 0xFDA6, 0xFDB6, 0xFDC6, 0xFDD6, 0xFDE5, 0xFDF5,
    0xFE05, 0xFE15, 0xFE25, 0xFE35, 0xFE44, 0xFE54, 0xFE64, 0xFE74,
    0xFE84, 0xFE94, 0xFEA4, 0xFEB3, 0xFEC3, 0xFED3, 0xFEE3, 0xFEF3,
    0xFF03, 0xFF12, 0xFF22, 0xFF32, 0xFF42, 0xFF52, 0xFF62, 0xFF71,
    0xFF81, 0xFF91, 0xFFA1, 0xFFB1, 0xFFC1, 0xFFD0, 0xFFE0, 0xFFF0

};

