#include "donkeyKong/dkPlayer.h"

int playerPositionX = 0,
    playerPositionY = 0;
short gravity = 5,
      jumpSpeed = 4,
      playerSpeed = 2;
bool isGrounded = false,
     isJumping = false;
unsigned int jumpCurrentValue = 0,
             jumpMaxTime = 8;
short lastInputValueX = 1,
      frameCounter = 0,
      changeSpriteAfterFrames = 4;

TFT_eSprite marioIdleRightSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioIdleLeftSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioJumpLeftSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioJumpRightSprite = TFT_eSprite(display.getTft());

SpriteImage marioIdleRightSpriteImage,
    marioIdleLeftSpriteImage,
    marioJumpLeftSpriteImage,
    marioJumpRightSpriteImage;

void DK_Player::init()
{
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Idle_Right", &marioIdleRightSprite, &marioIdleRightSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Idle_Left", &marioIdleLeftSprite, &marioIdleLeftSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Jump_Left", &marioJumpLeftSprite, &marioJumpLeftSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Jump_Right", &marioJumpRightSprite, &marioJumpRightSpriteImage);
}

void DK_Player::movement(int *stickValueX, int *stickValueY)
{
    if (lastInputValueX != *stickValueX && *stickValueX != 0)
        lastInputValueX = *stickValueX;

    movementHorizontally(stickValueX);
    movementJump(stickValueY);
    enableGravity();

    frameCounter++;

    if (frameCounter > changeSpriteAfterFrames * 2)
        frameCounter = 0;

    // Right
    if (lastInputValueX > 0)
    {
        if (frameCounter > changeSpriteAfterFrames &&
            frameCounter < (changeSpriteAfterFrames * 2) && *stickValueX != 0)
        {
            display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioJumpRightSprite, &marioJumpRightSpriteImage);
        }
        else
        {
            display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleRightSprite, &marioIdleRightSpriteImage);
        }
    }
    // Left
    else if (lastInputValueX < 0)
    {
        if (frameCounter > changeSpriteAfterFrames &&
            frameCounter < (changeSpriteAfterFrames * 2) && *stickValueX != 0)
        {
            display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioJumpLeftSprite, &marioJumpLeftSpriteImage);
        }
        else
        {
            display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleLeftSprite, &marioIdleLeftSpriteImage);
        }
    }
}

void DK_Player::movementHorizontally(int *stickValueX)
{
    // Right
    if (*stickValueX > 0 && playerPositionX < SCREEN_WIDTH - 24)
    {
        playerPositionX = playerPositionX + playerSpeed;
    }
    // Left
    else if (*stickValueX < 0 && playerPositionX > 0)
    {
        playerPositionX = playerPositionX - playerSpeed;
    }
}

void DK_Player::movementJump(int *stickValueY)
{
    if (isJumping)
    {
        timeInAirDelay();
    }

    if (*stickValueY < 0 && isGrounded && !isJumping)
    {
        isJumping = true;
    }

    if (!isGrounded)
    {
        // Reset ground position.
        if (playerPositionY >= SCREEN_HEIGHT - 32)
        {
            isGrounded = true;
            playerPositionY = SCREEN_HEIGHT - 32;
        }
    }
}

void DK_Player::enableGravity()
{
    if (!isGrounded)
    {
        if (playerPositionY < SCREEN_HEIGHT - 32)
        {
            playerPositionY = playerPositionY + gravity;
        }
    }
}

void DK_Player::timeInAirDelay()
{
    playerPositionY = playerPositionY - jumpSpeed;

    if (jumpCurrentValue++ >= jumpMaxTime)
    {
        isGrounded = false;
        isJumping = false;
        jumpCurrentValue = 0;
    }
}