#include <Arduino.h>
#include "main.h"

#ifndef __DK_BARREL_H__
#define __DK_BARREL_H__

class DK_Barrel
{
public:
    void init();
    void dropBarrel();

private:
    void randomPositionX(int *positionX);
    void randomPositionY(int *positionY);

    TFT_eSprite barrelSprite = TFT_eSprite(display.getTft());
    SpriteImage barrelSpriteImage;

    int barrelPositionX, barrelPositionY;
    int frameCounter, startDropBarrelFrame;
};

#endif