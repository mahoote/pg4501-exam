/* TODO: screenSizeHeight - MARIO_SIZE_Y make variable */

#include <Arduino.h>

#include "io/display.h"
#include "donkeyKong/donkeyKongGame.h"

#include <TFT_eSPI.h>

int playerPositionX = 0;
int playerPositionY = 0;

short gravity = 7;
short jumpSpeed = 4;
short playerSpeed = 2;

bool isGrounded = false;
bool isJumping = false;

unsigned int jumpCurrentValue = 0;
unsigned int jumpMaxTime = 8;

short lastInputValueX = 1;

Display display;

TFT_eSprite marioIdleRightSprite = TFT_eSprite(display.getTft());
SpriteImage marioIdleRightSpriteImage;

TFT_eSprite marioIdleLeftSprite = TFT_eSprite(display.getTft());
SpriteImage marioIdleLeftSpriteImage;

void DonkeyKongGame::init(Memory *memory)
{
    display.initTft();
    memory->initSD();
    memory->initSprite("/Donkey_Kong_Game/Mario/Mario_Idle_Right", &marioIdleRightSprite, &marioIdleRightSpriteImage);
    memory->initSprite("/Donkey_Kong_Game/Mario/Mario_Idle_Left", &marioIdleLeftSprite, &marioIdleLeftSpriteImage);
}

void DonkeyKongGame::play(Joystick *joystick)
{
    TFT_eSprite *screenSprite = display.getScreenSprite();

    joystick->setJoystickValues();
    int *stickValueX = &joystick->stickValueX;
    int *stickValueY = &joystick->stickValueY;

    if (lastInputValueX != *stickValueX && *stickValueX != 0)
        lastInputValueX = *stickValueX;

    movement(stickValueX, stickValueY);

    // Background.
    screenSprite->fillScreen(TFT_WHITE);

    // Player / Mario.
    if (lastInputValueX > 0)
        display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleRightSprite, &marioIdleRightSpriteImage);
    else if (lastInputValueX < 0)
        display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleLeftSprite, &marioIdleLeftSpriteImage);

    screenSprite->pushSprite(0, 0);
}

void DonkeyKongGame::movement(int *stickValueX, int *stickValueY)
{
    movementHorizontally(stickValueX);
    movementJump(stickValueY);
    enableGravity();
}

void DonkeyKongGame::movementHorizontally(int *stickValueX)
{
    // Right
    if (*stickValueX > 0 && playerPositionX < screenSizeWidth - MARIO_SIZE_X)
    {
        playerPositionX = playerPositionX + playerSpeed;
    }
    // Left
    else if (*stickValueX < 0 && playerPositionX > 0)
    {
        playerPositionX = playerPositionX - playerSpeed;
    }
}

void DonkeyKongGame::movementJump(int *stickValueY)
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
        if (playerPositionY >= screenSizeHeight - MARIO_SIZE_Y)
        {
            isGrounded = true;
            playerPositionY = screenSizeHeight - MARIO_SIZE_Y;
        }
    }
}

void DonkeyKongGame::enableGravity()
{
    if (!isGrounded)
    {
        if (playerPositionY < screenSizeHeight - MARIO_SIZE_Y)
        {
            playerPositionY = playerPositionY + gravity;
        }
    }
}

void DonkeyKongGame::timeInAirDelay()
{
    playerPositionY = playerPositionY - jumpSpeed;

    if (jumpCurrentValue++ >= jumpMaxTime)
    {
        isGrounded = false;
        isJumping = false;
        jumpCurrentValue = 0;
    }
}