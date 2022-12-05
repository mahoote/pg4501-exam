#include <Arduino.h>

#include <SdFat.h>                // SD card & FAT filesystem library
#include <Adafruit_ImageReader.h> // Image-reading functions
#include <TFT_eSPI.h>

#ifndef __SPRITE_IMAGE_H__
#define __SPRITE_IMAGE_H__

class SpriteImage
{
public:
  int *getFileSize();
  void setFileSize(int size);
  int16_t *getWidth();
  void setWidth(int16_t w);
  int16_t *getHeight();
  void setHeight(int16_t h);
  uint16_t **getBuffer();
  bool setBuffer(uint16_t *b);
  void freeBuffer();
  Adafruit_Image *getImage();

private:
  Adafruit_Image image; // An image loaded into RAM
  int fileSize = 0;
  int16_t width = 0,
          height = 0;
  uint16_t *buffer;
};

#endif