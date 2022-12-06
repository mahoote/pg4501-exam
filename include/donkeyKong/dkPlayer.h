#include <Arduino.h>
#include "io/joystick.h"
#include "io/memory.h"
#include "main.h"
#include "donkeyKong/dkPlayerPlatform.h"

#ifndef __DK_PLAYER_H__
#define __DK_PLAYER_H__

class DK_Player
{
public:
    void init();
    void movement();

private:
    void moveDirectionX(TFT_eSprite *sprite[], SpriteImage *spriteImage[]);
    void drawSprite(TFT_eSprite *sprite, SpriteImage *spriteImage);
    void renderSprites();
    void timeInAirDelay();
    void movementHorizontally();
    void movementJump();
    void enableGravity();

    int playerPositionX = 0,
        playerPositionY = 0,
        // How mutch the player position Y should increase or decrease.
        addPlatformYValue = 8;

    bool isMoving, isMovingX, isMovingY;
};

#endif