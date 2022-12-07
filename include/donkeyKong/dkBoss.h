#include <Arduino.h>
#include "main.h"

#ifndef __DK_BOSS_H__
#define __DK_BOSS_H__

class DK_Boss
{
public:
    void init();
    void drawBoss();

private:
    TFT_eSprite bossSprite = TFT_eSprite(display.getTft());
    TFT_eSprite bossRightArmSprite = TFT_eSprite(display.getTft());
    TFT_eSprite bossLeftArmSprite = TFT_eSprite(display.getTft());
    SpriteImage bossSpriteImage, bossRightArmSpriteImage, bossLeftArmSpriteImage;

    int bossPositionX, bossPositionY;
    int frameCounter, changeImageFrame;
};

#endif