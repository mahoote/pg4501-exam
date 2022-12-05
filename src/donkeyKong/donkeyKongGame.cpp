#include <Arduino.h>

#include "io/display.h"
#include "io/joystick.h"
#include "donkeyKong/donkeyKongGame.h"
#include "donkeyKong/donkeyKongSprites.h"

#include <TFT_eSPI.h>

int playerPositionX = 1;
int playerPositionY = 0;

short gravity = 7;
short jumpSpeed = 4;
short playerSpeed = 2;

bool isGrounded = false;
bool isJumping = false;

unsigned int jumpCurrentValue = 0;
unsigned int jumpMaxTime = 8;

DonkeyKongSprites donkeyKongSprites;

// TODO: screenSizeHeight - MARIO_SIZE_Y make variable

void DonkeyKongGame::initDisplay(TFT_eSPI *tft)
{
    Serial.println("Init display");

    tft->init();
    tft->setSwapBytes(true);
    tft->fillScreen(TFT_WHITE);
}

void DonkeyKongGame::play(TFT_eSprite *screenSprite, Joystick *joystick)
{
    int *stickValueX = &joystick->stickValueX;
    int *stickValueY = &joystick->stickValueY;
    joystick->setJoystickValues();

    movement(stickValueX, stickValueY);

    // Background.
    screenSprite->createSprite(screenSizeWidth, screenSizeHeight);
    screenSprite->setSwapBytes(true);
    screenSprite->fillScreen(TFT_WHITE);

    // Player / Mario.
    screenSprite->pushImage(playerPositionX, playerPositionY, MARIO_SIZE_X, MARIO_SIZE_Y, donkeyKongSprites.mario_standing_01);

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