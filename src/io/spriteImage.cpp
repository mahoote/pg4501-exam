#include <Arduino.h>
#include "io/spriteImage.h"

int *SpriteImage::getFileSize()
{
  return &fileSize;
}

void SpriteImage::setFileSize(int size)
{
  fileSize = size;
}

int16_t *SpriteImage::getWidth()
{
  return &width;
}

void SpriteImage::setWidth(int16_t w)
{
  width = w;
}

int16_t *SpriteImage::getHeight()
{
  return &height;
}

void SpriteImage::setHeight(int16_t h)
{
  height = h;
}

uint16_t **SpriteImage::getBuffer()
{
  return &buffer;
}

bool SpriteImage::setBuffer(uint16_t *b)
{
  if (*getFileSize() > 0)
  {
    *getBuffer() = (uint16_t *)malloc(*getFileSize());
    *getBuffer() = b;
    return true;
  }
  return false;
}

void SpriteImage::freeBuffer()
{
  free(*getBuffer());
}

Adafruit_Image *SpriteImage::getImage()
{
  return &image;
}