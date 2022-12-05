#include <Arduino.h>

#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

class Joystick
{
public:
    void initJoystick();
    void setJoystickValues();
    int stickValueX;
    int stickValueY;
};

#endif