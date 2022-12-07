#include "donkeyKong/dkBoss.h"

void DK_Boss::init()
{
    bossPositionX = 5;
    bossPositionY = 46;

    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong/Donkey_Kong_Idle", &bossSprite, &bossSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong/Donkey_Kong_Right_Arm", &bossRightArmSprite, &bossRightArmSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong/Donkey_Kong_Left_Arm", &bossLeftArmSprite, &bossLeftArmSpriteImage);

    changeImageFrame = random(100);
}

void DK_Boss::drawBoss()
{
    static int randomImage;

    frameCounter++;

    if (frameCounter < changeImageFrame)
    {
        randomImage = random(2);
        display.drawImageToScreen(&bossPositionX, &bossPositionY, &bossSprite, &bossSpriteImage);
    }
    else
    {
        if (randomImage == 0)
            display.drawImageToScreen(&bossPositionX, &bossPositionY, &bossRightArmSprite, &bossRightArmSpriteImage);
        if (randomImage == 1)
            display.drawImageToScreen(&bossPositionX, &bossPositionY, &bossLeftArmSprite, &bossLeftArmSpriteImage);

        if (frameCounter > changeImageFrame + 20)
            frameCounter = 0;
    }
}