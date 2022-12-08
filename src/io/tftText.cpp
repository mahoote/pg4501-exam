#include "io/tftText.h"

String TFT_Text::leadingZerosString(int digitAmount, int number)
{
    int digitCount = countDigits(number);
    String s = "";

    if (digitCount < digitAmount)
    {
        int remainds = digitAmount - digitCount;
        for (int i = 0; i < remainds; i++)
        {
            s += "0";
        }
    }

    if (number != 0)
    {
        s += String(number);
    }

    return s;
}

int TFT_Text::countDigits(int number)
{
    int count = 0;
    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}

void TFT_Text::writeText(String text, int x, int y, uint16_t color, int textSize)
{
    TFT_eSprite *screenSprite = display.getScreenSprite();

    screenSprite->setTextSize(textSize);
    screenSprite->setTextColor(color);
    screenSprite->setCursor(x, y);
    screenSprite->println(text);
}