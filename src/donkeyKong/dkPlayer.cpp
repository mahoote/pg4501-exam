#include "donkeyKong/dkPlayer.h"

int playerPositionX = 0,
    playerPositionY = 0,
    stickValueX,
    stickValueY;
short gravity = 5,
      jumpSpeed = 4,
      playerSpeed = 2,
      playerHeight,
      playerWidth;
bool isGrounded = false,
     isJumping = false;
unsigned int jumpCurrentValue = 0,
             jumpMaxTime = 8;
short lastInputValueX = 1,
      frameCounter = 0,
      changeSpriteAfterFrames = 4;

TFT_eSprite marioIdleLeftSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioIdleRightSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioWalkLeftSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioWalkRightSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioJumpLeftSprite = TFT_eSprite(display.getTft());
TFT_eSprite marioJumpRightSprite = TFT_eSprite(display.getTft());

SpriteImage marioIdleRightSpriteImage,
    marioIdleLeftSpriteImage,
    marioWalkLeftSpriteImage,
    marioWalkRightSpriteImage,
    marioJumpLeftSpriteImage,
    marioJumpRightSpriteImage;

void DK_Player::init()
{
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Idle_Right", &marioIdleRightSprite, &marioIdleRightSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Idle_Left", &marioIdleLeftSprite, &marioIdleLeftSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Walk_Right", &marioWalkRightSprite, &marioWalkRightSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Walk_Left", &marioWalkLeftSprite, &marioWalkLeftSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Jump_Left", &marioJumpLeftSprite, &marioJumpLeftSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Mario/Mario_Jump_Right", &marioJumpRightSprite, &marioJumpRightSpriteImage);
}

void DK_Player::movement()
{
    stickValueX = *joystick.getStickValueX();
    stickValueY = *joystick.getStickValueY();

    if (lastInputValueX != stickValueX && stickValueX != 0)
        lastInputValueX = stickValueX;

    movementHorizontally();
    movementJump();
    enableGravity();

    renderSprites();
}

void DK_Player::renderSprites()
{
    SpriteImage *currentSpriteImage;

    frameCounter++;

    if (frameCounter > changeSpriteAfterFrames * 2)
        frameCounter = 0;

    // Right
    if (lastInputValueX > 0)
    {
        if (!isGrounded || isJumping)
        {
            currentSpriteImage = &marioJumpRightSpriteImage;
            display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioJumpRightSprite, &marioJumpRightSpriteImage);
        }
        else
        {
            if (frameCounter > changeSpriteAfterFrames &&
                frameCounter < (changeSpriteAfterFrames * 2) && stickValueX != 0)
            {
                currentSpriteImage = &marioJumpRightSpriteImage;
                display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioWalkRightSprite, &marioWalkRightSpriteImage);
            }
            else
            {
                currentSpriteImage = &marioIdleRightSpriteImage;
                display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleRightSprite, &marioIdleRightSpriteImage);
            }
        }
    }
    // Left
    else if (lastInputValueX < 0)
    {
        if (!isGrounded || isJumping)
        {
            currentSpriteImage = &marioJumpLeftSpriteImage;
            display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioJumpLeftSprite, &marioJumpLeftSpriteImage);
        }
        else
        {
            if (frameCounter > changeSpriteAfterFrames &&
                frameCounter < (changeSpriteAfterFrames * 2) && stickValueX != 0)
            {
                currentSpriteImage = &marioJumpLeftSpriteImage;
                display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioWalkLeftSprite, &marioWalkLeftSpriteImage);
            }
            else
            {
                currentSpriteImage = &marioIdleLeftSpriteImage;
                display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleLeftSprite, &marioIdleLeftSpriteImage);
            }
        }
    }
    // Something is wrong
    else
    {
        currentSpriteImage = &marioIdleRightSpriteImage;
        display.drawImageToScreen(&playerPositionX, &playerPositionY, &marioIdleRightSprite, &marioIdleRightSpriteImage);
    }

    playerWidth = *currentSpriteImage->getWidth();
    playerHeight = *currentSpriteImage->getHeight();
}

void DK_Player::movementHorizontally()
{
    // Right
    if (stickValueX > 0 && playerPositionX < SCREEN_WIDTH - playerWidth)
    {
        playerPositionX = playerPositionX + playerSpeed;
    }
    // Left
    else if (stickValueX < 0 && playerPositionX > 0)
    {
        playerPositionX = playerPositionX - playerSpeed;
    }
}

void DK_Player::movementJump()
{
    if (isJumping)
    {
        timeInAirDelay();
    }

    if (stickValueY < 0 && isGrounded && !isJumping)
    {
        isJumping = true;
    }

    if (!isGrounded)
    {
        // Reset ground position.
        if (playerPositionY >= SCREEN_HEIGHT - playerHeight - 8)
        {
            isGrounded = true;
            playerPositionY = SCREEN_HEIGHT - playerHeight - 8;
        }
    }
}

void DK_Player::enableGravity()
{
    if (!isGrounded)
    {
        if (playerPositionY < SCREEN_HEIGHT - playerHeight)
        {
            playerPositionY = playerPositionY + gravity;
        }
    }
}

void DK_Player::timeInAirDelay()
{
    // Move player up
    playerPositionY = playerPositionY - jumpSpeed;

    if (jumpCurrentValue++ >= jumpMaxTime)
    {
        isGrounded = false;
        isJumping = false;
        jumpCurrentValue = 0;
    }
}