#include "Arduino.h"
#include "main.h"

#ifndef __TFT_TEXT_H__
#define __TFT_TEXT_H__

#define TFT_LIGHT_BLUE 0xccff

class TFT_Text
{
public:
    void writeText(String text, int x, int y, uint16_t color, int textSize = 1);
    int countDigits(int number);
    String leadingZerosString(int digitAmount, int number);
};

#endif