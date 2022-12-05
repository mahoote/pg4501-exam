#include <Arduino.h>
#include "io/spriteImage.h"

#ifndef __MEMORY_H__
#define __MEMORY_H__

#define SD_CS 4 // SD card select pin

class Memory
{
public:
    Memory(String sdSpriteCurrentGamePath);
    void initSD();
    void initSprite(String localGamePath, TFT_eSprite *sprite, SpriteImage *spriteImage);
    String *getSdSpriteGamePath();

private:
    void loadBitmapImage(String *localGamePath, SpriteImage *spriteImage);
    void setImageBytes(TFT_eSprite *sprite, SpriteImage *spriteImage);
    int getImageCanvasFormat(Adafruit_Image *image);
    void setSdSpriteGamePath(String path);
    String sdSpriteGamePath;
};

#endif