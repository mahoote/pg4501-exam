#include "io/tftText.h"

void TFT_Text::writeText(String text, int x, int y, uint16_t color, int textSize)
{
    TFT_eSprite *screenSprite = display.getScreenSprite();

    screenSprite->setTextSize(textSize);
    screenSprite->setTextColor(color);
    screenSprite->setCursor(x, y);
    screenSprite->println(text);
}