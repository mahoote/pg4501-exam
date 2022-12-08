#include <Arduino.h>
#include "main.h"
#include "donkeyKong/player/dkPlayer.h"

#ifndef __DK_BARREL_H__
#define __DK_BARREL_H__

class DK_Barrel
{
public:
    void init();
    void reset();
    void dropBarrel(DK_Player *player, byte *playerHit);
    bool playerCollision(int *playerX, int *playerY, short *playerWidth, short *playerHeight,
                         int *barrelX, int *barrelY, short *barrelWidth, short *barrelHeight);

private:
    void randomPositionX(int *positionX);
    void randomPositionY(int *positionY);

    TFT_eSprite barrelSprite = TFT_eSprite(display.getTft());
    SpriteImage barrelSpriteImage;

    int barrelPositionX, barrelPositionY;
    int frameCounter, startDropBarrelFrame;
};

#endif