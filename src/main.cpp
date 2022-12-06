#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Adafruit_EPD.h"
#include "Adafruit_SPIFlash.h"

#include "main.h"
#include "donkeyKong/donkeyKongGame.h"

Memory memory("/pg4501_exam/Sprites");
Display display;
Joystick joystick;
FPS fps;

DonkeyKongGame donkeyKongGame;

void setup()
{
  Serial.begin(115200);

  fps.initFPS(30.0f);

  display.initTft();
  joystick.initJoystick();
  donkeyKongGame.init();
}

void loop()
{
  // Used for frame time measuring
  float startMillis = millis();

  fps.calculateFPS();
  // fps.debugFPS();

  donkeyKongGame.play();

  fps.limitFPS(&startMillis);
}
