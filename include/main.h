#include <Arduino.h>
#include "io/display.h"
#include "io/memory.h"
#include "io/joystick.h"
#include "fps.h"

#ifndef __MAIN_H__
#define __MAIN_H__

extern Memory memory;
extern Display display;
extern Joystick joystick;
extern FPS fps;

#endif