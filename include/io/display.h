#include <Arduino.h>
#include "io/spriteImage.h"

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#define screenSizeHeight 240
#define screenSizeWidth 135

class Display
{
public:
    Display();
    void initTft();
    void drawImageToScreen(int32_t *posX, int32_t *posY, TFT_eSprite *sprite, SpriteImage *spriteImage);
    TFT_eSPI *getTft();
    TFT_eSprite *getScreenSprite();

private:
    TFT_eSPI tft = TFT_eSPI();
    TFT_eSprite screenSprite = TFT_eSprite(&tft);
};

#endif