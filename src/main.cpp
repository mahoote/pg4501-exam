#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Adafruit_EPD.h"
#include "Adafruit_SPIFlash.h"

#include "io/display.h"
#include "donkeyKong/donkeyKongGame.h"
#include "io/joystick.h"

Joystick joystick;
DonkeyKongGame donkeyKongGame;

void setup()
{
  Serial.begin(115200);

  Serial.println("Setup");

  joystick.initJoystick();

  donkeyKongGame.init();
}

void loop()
{
  donkeyKongGame.play(&joystick);
}
