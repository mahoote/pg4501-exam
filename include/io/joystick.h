#include <Arduino.h>

#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

class Joystick
{
public:
    void initJoystick();
    void setJoystickValues();
    int *getStickValueX();
    int *getStickValueY();

private:
    int stickValueX = 0;
    int stickValueY = 0;
};

#endif