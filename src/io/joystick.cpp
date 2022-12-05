#include <Arduino.h>
#include "io/joystick.h"

// Public Variables

int stickValueX = 0;
int stickValueY = 0;

// Private Variables

int VRxPin = A0;
int VRyPin = A1;
int SW_Pin = 9;

int stickPositionX = 0;
int stickPositionY = 0;
int stickBtnState = 0;

void Joystick::initJoystick()
{
    pinMode(VRxPin, INPUT);
    pinMode(VRyPin, INPUT);
    pinMode(SW_Pin, INPUT_PULLUP);
}

void Joystick::setJoystickValues()
{
    stickPositionX = analogRead(VRxPin);

    // Serial.print("Stick Postition X: ");
    // Serial.println(stickPositionX);

    stickPositionY = analogRead(VRyPin);
    stickBtnState = digitalRead(SW_Pin);

    stickValueX = map(stickPositionX, 0, 4095, -1, 0);
    stickValueY = map(stickPositionY, 0, 4095, -1, 0);

    // Serial.print("X: ");
    // Serial.print(stickValueX);
    // Serial.print(" | Y: ");
    // Serial.print(stickValueY);
    // Serial.print(" | Button: ");
    // Serial.println(stickBtnState);
}
