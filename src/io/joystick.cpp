#include <Arduino.h>
#include "io/joystick.h"

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

int *Joystick::getStickValueX()
{
    return &stickValueX;
}

int *Joystick::getStickValueY()
{
    return &stickValueY;
}

int *Joystick::getButtonState()
{
    return &stickBtnState;
}