#include <Arduino.h>
#include "main.h"
#include "donkeyKong/player/dkPlayerPlatform.h"

#ifndef __DK_PLAYER_H__
#define __DK_PLAYER_H__

class DK_Player
{
public:
    void init();
    void movement();
    int *getPositionX();
    int *getPositionY();
    short *getWidth();
    short *getHeight();

private:
    void moveDirectionX(TFT_eSprite *sprite[], SpriteImage *spriteImage[]);
    void drawSprite(TFT_eSprite *sprite, SpriteImage *spriteImage);
    void renderSprites();
    void timeInAirDelay();
    void movementHorizontally();
    void movementVertically();
    void movementJump();
    void enableGravity();

    int playerPositionX = 0,
        playerPositionY = 0,
        // How mutch the player position Y should increase or decrease.
        addPlatformYValue = 8;

    bool isMoving, isMovingX, isMovingY, gravityEnabled = true;
};

#endif