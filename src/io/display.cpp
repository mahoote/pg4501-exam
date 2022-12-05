#include "io/display.h"

Display::Display()
{
}

void Display::initTft()
{
    TFT_eSPI *tft = getTft();
    TFT_eSprite *screenSprite = getScreenSprite();

    tft->init();
    tft->setSwapBytes(true);
    tft->fillScreen(TFT_WHITE);

    screenSprite->createSprite(screenSizeWidth, screenSizeHeight);
}

TFT_eSPI *Display::getTft()
{
    return &tft;
}

TFT_eSprite *Display::getScreenSprite()
{
    return &screenSprite;
}

void Display::drawImageToScreen(int32_t *posX, int32_t *posY, TFT_eSprite *sprite, SpriteImage *spriteImage)
{
    sprite->pushImage(0, 0, *spriteImage->getWidth(), *spriteImage->getHeight(), *spriteImage->getBuffer());
    sprite->pushToSprite(getScreenSprite(), *posX, *posY, TFT_BLACK);
}
