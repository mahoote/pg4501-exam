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
    void reset();
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

    bool isMoving, isMovingX, isMovingY, gravityEnabled = true, canMove = false;

    int prevPlayerPositionX = 0,
        prevPlayerPositionY = 0,
        stickValueX,
        stickValueY,
        playerPlatformY = 0,
        frameCounter = 0;

    unsigned int jumpCurrentValue = 0,
                 jumpMaxTime = 8;

    short gravity = 5,
          jumpSpeed = 2,
          playerSpeed = 2,
          playerHeight,
          playerWidth;

    short lastInputValueX = 1,
          changeSpriteAfterFrames = 4;

    bool isGrounded = false, isJumping = false,
         playerLeft = false, playerRight = false, playerUp = false, playerDown = false;

    TFT_eSprite marioIdleLeftSprite = TFT_eSprite(display.getTft());
    TFT_eSprite marioIdleRightSprite = TFT_eSprite(display.getTft());
    TFT_eSprite marioWalkLeftSprite = TFT_eSprite(display.getTft());
    TFT_eSprite marioWalkRightSprite = TFT_eSprite(display.getTft());
    TFT_eSprite marioJumpLeftSprite = TFT_eSprite(display.getTft());
    TFT_eSprite marioJumpRightSprite = TFT_eSprite(display.getTft());

    SpriteImage *currentSpriteImage;

    SpriteImage marioIdleRightSpriteImage,
        marioIdleLeftSpriteImage,
        marioWalkLeftSpriteImage,
        marioWalkRightSpriteImage,
        marioJumpLeftSpriteImage,
        marioJumpRightSpriteImage;

    DK_PlayerPlatform playerPlatform;
};

#endif