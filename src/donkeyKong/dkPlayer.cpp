#include "donkeyKong/dkPlayer.h"

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
    playerPlatform.getPlayerValues(&playerPositionX, &playerPositionY, &addPlatformYValue,
                                   &isMovingX, &isMovingY, &playerLeft, &playerRight, &playerUp,
                                   &gravityEnabled, &isGrounded, &isJumping);

    stickValueX = *joystick.getStickValueX();
    stickValueY = *joystick.getStickValueY();

    if (lastInputValueX != stickValueX && stickValueX != 0)
        lastInputValueX = stickValueX;

    movementVertically();

    playerPlatform.changePlatformY();

    addPlatformYValue = *playerPlatform.getAddPlatformYValue();
    playerPlatformY = SCREEN_HEIGHT - playerHeight - addPlatformYValue;

    gravityEnabled = *playerPlatform.getGravityEnabled();
    isGrounded = *playerPlatform.getIsGrounded();
    isJumping = *playerPlatform.getIsJumping();

    if (gravityEnabled)
    {
        movementHorizontally();
        movementJump();
        enableGravity();
    }

    isMoving = false;
    isMovingX = false;
    isMovingY = false;

    if (prevPlayerPositionX != playerPositionX || prevPlayerPositionY != playerPositionY)
        isMoving = true;

    if (prevPlayerPositionX != playerPositionX)
        isMovingX = true;

    if (prevPlayerPositionY != playerPositionY)
        isMovingY = true;

    // Must be at the bottom.
    prevPlayerPositionX = playerPositionX;
    prevPlayerPositionY = playerPositionY;

    renderSprites();
}

void DK_Player::renderSprites()
{
    frameCounter++;

    if (frameCounter > changeSpriteAfterFrames * 2)
        frameCounter = 0;

    // Right
    if (lastInputValueX > 0)
    {
        playerRight = true;
        playerLeft = false;

        TFT_eSprite *sprites[] = {&marioIdleRightSprite, &marioWalkRightSprite, &marioJumpRightSprite};
        SpriteImage *spriteImages[] = {&marioIdleRightSpriteImage, &marioWalkRightSpriteImage, &marioJumpRightSpriteImage};

        moveDirectionX(sprites, spriteImages);
    }
    // Left
    else if (lastInputValueX < 0)
    {
        playerLeft = true;
        playerRight = false;

        TFT_eSprite *sprites[] = {&marioIdleLeftSprite, &marioWalkLeftSprite, &marioJumpLeftSprite};
        SpriteImage *spriteImages[] = {&marioIdleLeftSpriteImage, &marioWalkLeftSpriteImage, &marioJumpLeftSpriteImage};

        moveDirectionX(sprites, spriteImages);
    }
    // Something is wrong
    else
    {
        drawSprite(&marioIdleRightSprite, &marioIdleRightSpriteImage);
    }

    playerWidth = *currentSpriteImage->getWidth();
    playerHeight = *currentSpriteImage->getHeight();
}

void DK_Player::moveDirectionX(TFT_eSprite *sprites[], SpriteImage *spriteImage[])
{
    if (!isGrounded || isJumping)
    {
        drawSprite(sprites[2], spriteImage[2]);
    }
    else
    {
        if (frameCounter > changeSpriteAfterFrames &&
            frameCounter < (changeSpriteAfterFrames * 2) && stickValueX != 0)
        {
            drawSprite(sprites[1], spriteImage[1]);
        }
        else
        {
            drawSprite(sprites[0], spriteImage[0]);
        }
    }
}

void DK_Player::drawSprite(TFT_eSprite *sprite, SpriteImage *spriteImage)
{
    currentSpriteImage = spriteImage;
    display.drawImageToScreen(&playerPositionX, &playerPositionY, sprite, spriteImage);
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

void DK_Player::movementVertically()
{
    if (stickValueY < 0)
    {
        playerUp = true;
        playerDown = false;
    }
    else if (stickValueY > 0)
    {
        playerUp = false;
        playerDown = true;
    }
    else
    {
        playerUp = false;
        playerDown = false;
    }

    if (isGrounded && !isJumping)
    {
        // Make sure player is on platform when grounded.
        playerPositionY = playerPlatformY;
    }
}

void DK_Player::movementJump()
{
    if (stickValueY < 0 && isGrounded && !isJumping)
    {
        isJumping = true;
    }

    if (isJumping)
    {
        timeInAirDelay();
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
        // Reset ground position if too far down.
        if (playerPositionY >= playerPlatformY)
        {
            isGrounded = true;
            playerPositionY = playerPlatformY;
        }
    }

    if (prevPlayerPositionY != playerPositionY)
        isMoving = true;
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