#include <Arduino.h>
#include "main.h"

#ifndef __DK_PRINCESS_H__
#define __DK_PRINCESS_H__

class DK_Princess
{
public:
    void init();
    void drawPrincess();

private:
    TFT_eSprite princessSprite = TFT_eSprite(display.getTft());
    TFT_eSprite princessScreamSprite = TFT_eSprite(display.getTft());
    TFT_eSprite helpSprite = TFT_eSprite(display.getTft());
    SpriteImage princessSpriteImage, princessScreamSpriteImage, helpSpriteImage;

    int princessPositionX, princessPositionY, helpSignX, helpSignY;
    int frameCounter, changeImageFrame;
};

#endif