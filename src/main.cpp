#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Adafruit_EPD.h"
#include "Adafruit_SPIFlash.h"

#include "main.h"

#include "io/memory.h"
#include "io/joystick.h"
#include "donkeyKong/donkeyKongGame.h"

Memory memory("/pg4501_exam/Sprites");
Display display;
Joystick joystick;
DonkeyKongGame donkeyKongGame;

void setup()
{
  Serial.begin(115200);

  display.initTft();
  joystick.initJoystick();
  donkeyKongGame.init(&memory);
}

void loop()
{
  donkeyKongGame.play(&joystick);
}
