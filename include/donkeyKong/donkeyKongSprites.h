#include <Arduino.h>

#ifndef __DONKEY_KONG_SPRITES_H__
#define __DONKEY_KONG_SPRITES_H__

class DonkeyKongSprites
{
public:
    const uint16_t mario_standing_01[1024] = {
        0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0000, 0x0000, 0x1000, 0x3800, 0xD223, 0xF1C0, 0xF1A0, 0xF9C0, 0xF9C0, 0xF1C0, // 0x0010 (16) pixels
        0xF9C0, 0xF1C0, 0xF1C1, 0xC1E2, 0x2000, 0x0800, 0x0800, 0x0800, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, // 0x0020 (32) pixels
        0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0820, 0x1000, 0x3000, 0x6000, 0xDA01, 0xF9E0, 0xF9A0, 0xF9A0, 0xF1A0, 0xF1A0, // 0x0030 (48) pixels
        0xF1C0, 0xF9C0, 0xF1C0, 0xD1A1, 0x4800, 0x3000, 0x3800, 0x3800, 0x3000, 0x2800, 0x0800, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, // 0x0040 (64) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x2800, 0xBA65, 0xD9C1, 0xF1E0, 0xF1A0, 0xF9A0, 0xF9A0, 0xF9A0, 0xF9E1, // 0x0050 (80) pixels
        0xF9C0, 0xF1A0, 0xF9C0, 0xF1C0, 0xD9E2, 0xDA44, 0xD202, 0xD223, 0xD244, 0xAA25, 0x1800, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, // 0x0060 (96) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3020, 0xC282, 0xE240, 0xE220, 0xE220, 0xEA20, 0xE200, 0xE200, 0xE1E0, // 0x0070 (112) pixels
        0xEA00, 0xE1E0, 0xE200, 0xEA20, 0xE200, 0xE201, 0xD202, 0xD243, 0xCA23, 0xAA25, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, // 0x0080 (128) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0800, 0x2840, 0xB3A4, 0xC380, 0xC380, 0xCB80, 0xC360, 0xD3A2, 0xFD08, 0xFCE9, // 0x0090 (144) pixels
        0xFCE8, 0xFCC7, 0xCB60, 0xCB81, 0xFD09, 0xE428, 0x3000, 0x2000, 0x1800, 0x1000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00A0 (160) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x2840, 0xABC3, 0xB401, 0xB3E0, 0xB3E0, 0xB3E0, 0xC3E1, 0xF528, 0xFD48, // 0x00B0 (176) pixels
        0xFD07, 0xED06, 0xBBE0, 0xBC01, 0xF568, 0xD488, 0x2000, 0x1000, 0x0800, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00C0 (192) pixels
        0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x18A0, 0x9BC6, 0xB404, 0xF568, 0xED06, 0xB3E1, 0xBC01, 0xF527, 0xFD47, 0xFD48, 0xFD08, // 0x00D0 (208) pixels
        0xFD48, 0xF506, 0xB380, 0xC401, 0xF528, 0xF529, 0xF54B, 0xED4C, 0xED4C, 0xBC6B, 0x1020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, // 0x00E0 (224) pixels
        0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x1860, 0xA403, 0xBC00, 0xFD47, 0xED07, 0xB3C1, 0xBBE1, 0xED06, 0xFD07, 0xFD08, 0xFD28, // 0x00F0 (240) pixels
        0xFD08, 0xFD27, 0xC3E2, 0xC402, 0xF527, 0xF507, 0xFD28, 0xFD28, 0xFD09, 0xDCA9, 0x3060, 0x2080, 0x0800, 0x0000, 0x0000, 0x0000, // 0x0100 (256) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2080, 0xABE2, 0xBC00, 0xF527, 0xED07, 0xB3C1, 0xB3E1, 0xB3E1, 0xC3E1, 0xFD08, 0xFD29, // 0x0110 (272) pixels
        0xFD09, 0xFD09, 0xFD49, 0xED27, 0xBBC1, 0xBBE2, 0xFD08, 0xFD08, 0xFD08, 0xFD2A, 0xED4B, 0xDD6F, 0x0800, 0x0000, 0x0000, 0x0000, // 0x0120 (288) pixels
        0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x1860, 0xAC23, 0xBBE0, 0xED27, 0xE4C6, 0xBBE2, 0xBC02, 0xBBE2, 0xCC23, 0xFD28, 0xFD08, // 0x0130 (304) pixels
        0xFD09, 0xFD09, 0xECE7, 0xE506, 0xABC0, 0xB3E1, 0xECE7, 0xFD07, 0xF4E7, 0xED08, 0xD489, 0xCCAC, 0x1000, 0x0000, 0x0000, 0x0020, // 0x0140 (320) pixels
        0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x2080, 0x9BC3, 0xB3E0, 0xB3C0, 0xCC02, 0xED07, 0xF528, 0xF549, 0xF508, 0xFD29, 0xFD08, // 0x0150 (336) pixels
        0xFD08, 0xF4E7, 0xB3C1, 0xABC0, 0xB401, 0xB3E0, 0xBBE0, 0xB3C0, 0xBC01, 0x9321, 0x1800, 0x1000, 0x0000, 0x0020, 0x0000, 0x0000, // 0x0160 (352) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1880, 0x93E6, 0xA405, 0xA3C4, 0xBBE4, 0xFD49, 0xFD29, 0xFD09, 0xFD29, 0xFD29, 0xFD28, // 0x0170 (368) pixels
        0xFD08, 0xF507, 0xBBE1, 0xB3E0, 0xB3A0, 0xB3C0, 0xB3E1, 0xABE2, 0xA3E3, 0x8B65, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x0180 (384) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0820, 0x0800, 0x1000, 0x3080, 0xED2A, 0xFD28, 0xFD28, 0xFD28, 0xFD08, 0xFD08, // 0x0190 (400) pixels
        0xFD28, 0xFD28, 0xF507, 0xFD27, 0xFD49, 0xF528, 0xF549, 0xCCA9, 0x1800, 0x0800, 0x0000, 0x0000, 0x0020, 0x0000, 0x0001, 0x0000, // 0x01A0 (416) pixels
        0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0800, 0x2880, 0xED49, 0xFD27, 0xFD08, 0xFCE8, 0xFD07, 0xFD68, // 0x01B0 (432) pixels
        0xF568, 0xF548, 0xFD48, 0xFD29, 0xF52B, 0xED2C, 0xED4D, 0xC4AD, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, // 0x01C0 (448) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x1840, 0x9C07, 0xA3E3, 0xB3E1, 0xC380, 0xCA40, 0xD280, 0xC380, 0xB3C0, // 0x01D0 (464) pixels
        0xB3E0, 0xB3E1, 0xB3A1, 0xA342, 0x2000, 0x1000, 0x1000, 0x0800, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, // 0x01E0 (480) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2060, 0x38E0, 0xA402, 0xABE0, 0xB3E0, 0xC360, 0xDA20, 0xDA40, 0xCBA1, 0xB400, // 0x01F0 (496) pixels
        0xAC00, 0xABC0, 0xBB81, 0xAB02, 0x2840, 0x1860, 0x1860, 0x1880, 0x1060, 0x1060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x0200 (512) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1060, 0x9C06, 0xA3E1, 0xAC00, 0xABE0, 0xB3E0, 0xC360, 0xDA40, 0xDA40, 0xCB81, 0xB3C0, // 0x0210 (528) pixels
        0xB3C0, 0xC380, 0xCA60, 0xCA81, 0xB3A4, 0xA404, 0xA403, 0xA403, 0x9C04, 0x8365, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x0220 (544) pixels
        0x0000, 0x0000, 0x0020, 0x0000, 0x1880, 0x3100, 0xA3E2, 0xAC00, 0xABE0, 0xB400, 0xB3E0, 0xC340, 0xDA20, 0xE220, 0xDB01, 0xCB61, // 0x0230 (560) pixels
        0xCB60, 0xDB20, 0xE200, 0xDA40, 0xC381, 0xABE0, 0xABE0, 0xAC00, 0xAC00, 0x9382, 0x2880, 0x1860, 0x0000, 0x0020, 0x0000, 0x0000, // 0x0240 (576) pixels
        0x0000, 0x0000, 0x0000, 0x0800, 0x93C7, 0xA403, 0xAC21, 0xABC0, 0xB400, 0xABE0, 0xBC01, 0xCB61, 0xE220, 0xF1E0, 0xEA00, 0xE200, // 0x0250 (592) pixels
        0xE200, 0xE1E0, 0xF1E0, 0xE240, 0xCBA1, 0xB420, 0xABC0, 0xB3E0, 0xABE0, 0xABE1, 0xABE3, 0x9BE7, 0x1020, 0x0000, 0x0000, 0x0000, // 0x0260 (608) pixels
        0x0000, 0x0000, 0x0001, 0x0800, 0xA3C5, 0xB3C1, 0xBBE1, 0xB3E0, 0xABC0, 0xBBE1, 0xC360, 0xCB00, 0xE240, 0xE9C0, 0xF1C0, 0xF9E0, // 0x0270 (624) pixels
        0xF9C0, 0xF1E0, 0xE9C0, 0xDA40, 0xD340, 0xC3A1, 0xB3C0, 0xB3E0, 0xBBE0, 0xBBE0, 0xB3C0, 0xABC4, 0x0800, 0x0000, 0x0000, 0x0000, // 0x0280 (640) pixels
        0x0000, 0x0001, 0x0000, 0x1000, 0xE54B, 0xF548, 0xF507, 0xF526, 0xBBE0, 0xC380, 0xD280, 0xE281, 0xFC89, 0xFC48, 0xE9E0, 0xF1C0, // 0x0290 (656) pixels
        0xF1C0, 0xF240, 0xFCA8, 0xFC87, 0xD220, 0xCA80, 0xC3A1, 0xBC01, 0xF547, 0xFD27, 0xFD68, 0xE54B, 0x1000, 0x0000, 0x0021, 0x0000, // 0x02A0 (672) pixels
        0x0000, 0x0000, 0x0000, 0x1000, 0xED6C, 0xFD28, 0xFD08, 0xFD07, 0xC3A1, 0xCB40, 0xE220, 0xF240, 0xFC68, 0xFC28, 0xE9E0, 0xF1E0, // 0x02B0 (688) pixels
        0xF1C0, 0xF260, 0xFC88, 0xFC27, 0xEA00, 0xDA40, 0xC361, 0xC3E2, 0xFD27, 0xFD27, 0xFD28, 0xE54B, 0x1000, 0x0000, 0x0000, 0x0000, // 0x02C0 (704) pixels
        0x0000, 0x0000, 0x0000, 0x1000, 0xE52B, 0xFD29, 0xFD2A, 0xFD09, 0xFD08, 0xFCA7, 0xE200, 0xF1C0, 0xFA01, 0xE9A0, 0xF1C0, 0xF1C0, // 0x02D0 (720) pixels
        0xF1E0, 0xF1E0, 0xE1C0, 0xF201, 0xF1C0, 0xEA40, 0xFD09, 0xFD08, 0xFD09, 0xFD29, 0xFD48, 0xE54B, 0x1800, 0x0000, 0x0000, 0x0000, // 0x02E0 (736) pixels
        0x0000, 0x0000, 0x0000, 0x1000, 0xE54C, 0xFD29, 0xFD0A, 0xFCEA, 0xFC88, 0xFC06, 0xE9E0, 0xF9A0, 0xF9A0, 0xF9C1, 0xF1A0, 0xF1E0, // 0x02F0 (752) pixels
        0xF1E0, 0xF1C0, 0xF1C0, 0xF1A0, 0xF9C0, 0xEA00, 0xFC48, 0xFCA8, 0xFD09, 0xFD09, 0xFD28, 0xED4B, 0x1000, 0x0000, 0x0000, 0x0000, // 0x0300 (768) pixels
        0x0020, 0x0000, 0x0000, 0x1000, 0xED4C, 0xFD09, 0xFD0A, 0xFC68, 0xDA00, 0xF1E0, 0xF9C0, 0xF9A0, 0xF9A0, 0xF1A0, 0xF1C1, 0xF1A1, // 0x0310 (784) pixels
        0xF1C0, 0xF1C0, 0xF1C0, 0xF9E0, 0xF9A0, 0xF1C0, 0xEA00, 0xE281, 0xFCC9, 0xFD09, 0xFD29, 0xED4C, 0x1000, 0x0000, 0x0000, 0x0000, // 0x0320 (800) pixels
        0x0000, 0x0020, 0x0000, 0x0800, 0xCCAC, 0xD469, 0xDC69, 0xEBC8, 0xE201, 0xF9A0, 0xF9C0, 0xF9C0, 0xF1C0, 0xE9C0, 0xC9A2, 0xC1C3, // 0x0330 (816) pixels
        0xC9C2, 0xD1A0, 0xE9C0, 0xF1A0, 0xF9C0, 0xF9C0, 0xF1E0, 0xE241, 0xEC29, 0xD48A, 0xCC69, 0xC4AC, 0x0800, 0x0000, 0x0020, 0x0000, // 0x0340 (832) pixels
        0x0000, 0x0000, 0x0000, 0x0800, 0x1000, 0x1800, 0x1800, 0x4000, 0xDA22, 0xF1A0, 0xF1E0, 0xF1C0, 0xF9C0, 0xC9A1, 0x3800, 0x2000, // 0x0350 (848) pixels
        0x2800, 0x5000, 0xE202, 0xF9C0, 0xF1A0, 0xF1E0, 0xE9C0, 0xC1E2, 0x2800, 0x0800, 0x1000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, // 0x0360 (864) pixels
        0x0000, 0x0000, 0x0000, 0x0801, 0x0000, 0x0800, 0x1000, 0x3020, 0xC261, 0xDA20, 0xE240, 0xDA20, 0xD222, 0xB224, 0x1800, 0x0020, // 0x0370 (880) pixels
        0x0000, 0x2800, 0xC266, 0xDA02, 0xDA20, 0xDA20, 0xDA40, 0xA9E0, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x0380 (896) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1860, 0x93E6, 0xA3E3, 0xBBE1, 0xBB80, 0xC380, 0xA301, 0x2800, 0x1800, 0x0800, 0x0000, // 0x0390 (912) pixels
        0x0000, 0x1000, 0x1800, 0x3800, 0xBB83, 0xC380, 0xCBA0, 0xBBC2, 0xA404, 0x8385, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x03A0 (928) pixels
        0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x2080, 0xA403, 0xAC00, 0xAC00, 0xAC00, 0xABE0, 0x9383, 0x0800, 0x0000, 0x0020, 0x0000, // 0x03B0 (944) pixels
        0x0000, 0x0000, 0x0000, 0x1860, 0xAC04, 0xABC0, 0xB400, 0xABE0, 0xABE0, 0x9382, 0x1000, 0x0800, 0x0000, 0x0021, 0x0000, 0x0000, // 0x03C0 (960) pixels
        0x0000, 0x0000, 0x0000, 0x0800, 0x9C05, 0xA3E1, 0xABC1, 0xB3E1, 0xA400, 0xAC00, 0xB401, 0x9343, 0x0800, 0x0000, 0x0000, 0x0020, // 0x03D0 (976) pixels
        0x0020, 0x0000, 0x0020, 0x1860, 0xA3E3, 0xB400, 0xAC20, 0xAC00, 0xB3E0, 0xABE1, 0xA3E2, 0x9C06, 0x0800, 0x0000, 0x0000, 0x0000, // 0x03E0 (992) pixels
        0x0000, 0x0000, 0x0000, 0x0800, 0xA3E2, 0xB400, 0xB3E0, 0xB3E0, 0xAC00, 0xAC00, 0xABC1, 0x9B43, 0x1000, 0x0000, 0x0000, 0x0020, // 0x03F0 (1008) pixels
        0x0020, 0x0020, 0x0000, 0x2060, 0xAC04, 0xB400, 0xAC00, 0xAC20, 0xB3E0, 0xB3E0, 0xB3E0, 0xA3E3, 0x0800, 0x0000, 0x0000, 0x0000, // 0x0400 (1024) pixels
    };
    ;
};

#endif
