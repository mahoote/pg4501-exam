#include "io/memory.h"

SdFat sd;                        // SD card filesystem
Adafruit_ImageReader reader(sd); // Image-reader object, pass in SD filesys

Memory::Memory(String sdSpriteCurrentGamePath)
{
    setSdSpriteGamePath(sdSpriteCurrentGamePath);
}

void Memory::initSD()
{
    Serial.print(F("Initializing filesystem..."));

    if (!sd.begin(SD_CS, SD_SCK_MHZ(10)))
    { // Breakouts require 10 MHz limit due to longer wires
        Serial.println(F("SD begin() failed"));
        for (;;)
            ; // Fatal error, do not continue
    }

    Serial.println(F("SD OK!"));
}

void Memory::initSprite(String localGamePath, TFT_eSprite *sprite, SpriteImage *spriteImage)
{
    if (*spriteImage->getFileSize() <= 0)
    {
        loadBitmapImage(&localGamePath, spriteImage);
        setImageBytes(sprite, spriteImage);
    }
    else
    {
        Serial.println(F("Sprite image already initialized!"));
    }
}

void Memory::loadBitmapImage(String *localGamePath, SpriteImage *spriteImage)
{
    String fileType = ".bmp";
    String imagePath = sdSpriteGamePath + *localGamePath + fileType;

    int imagePathLength = imagePath.length() + 1;
    char pszImagePath[imagePathLength];

    imagePath.toCharArray(pszImagePath, imagePathLength);
    reader.loadBMP(pszImagePath, *spriteImage->getImage());

    // Set file size.
    File32 imageFile = sd.open(pszImagePath, O_READ);
    if (imageFile)
    {
        spriteImage->setFileSize(imageFile.fileSize());
        imageFile.close();
    }
    else
    {
        Serial.println(F("SD Card: error on opening file"));
    }
}

// -------------------------------------------------------------------------
//   Retrieves the image canvas from the Adafruit_Image and
//   sets the image buffer. to the unsigned char array.
//   Returns: ImageSize (int).
// -------------------------------------------------------------------------
void Memory::setImageBytes(TFT_eSprite *sprite, SpriteImage *spriteImage)
{
    if (spriteImage->getFileSize() > 0)
    {
        Adafruit_Image *image = spriteImage->getImage();
        spriteImage->setWidth(image->width());
        spriteImage->setHeight(image->height());

        sprite->createSprite(*spriteImage->getWidth(), *spriteImage->getHeight());

        if (getImageCanvasFormat(image) == 3)
        {
            GFXcanvas16 *canvas = (GFXcanvas16 *)image->getCanvas();
            spriteImage->setBuffer(canvas->getBuffer());
        }
    }
}

int Memory::getImageCanvasFormat(Adafruit_Image *image)
{
    // Returns the enum index.
    return image->getFormat();
}

String *Memory::getSdSpriteGamePath()
{
    return &sdSpriteGamePath;
}

void Memory::setSdSpriteGamePath(String path)
{
    sdSpriteGamePath = path;
}

File32 Memory::readFile(String filePath)
{
    return sd.open(filePath, O_READ);
}

File32 Memory::writeFile(String filePath)
{
    return sd.open(filePath, O_RDWR | O_CREAT | O_AT_END);
}
bool Memory::fileExists(String filePath)
{
    return sd.exists(filePath);
}