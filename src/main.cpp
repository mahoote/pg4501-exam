#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Adafruit_EPD.h"
#include "Adafruit_SPIFlash.h"

#include "io/display.h"
#include "donkeyKong/donkeyKongGame.h"
#include "io/joystick.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite screenSprite = TFT_eSprite(&tft);

Joystick joystick;
DonkeyKongGame donkeyKongGame;

void setup()
{
  Serial.begin(115200);

  Serial.println("Setup");

  joystick.initJoystick();

  donkeyKongGame.initDisplay(&tft);
}

void loop()
{
  donkeyKongGame.play(&screenSprite, &joystick);
}
