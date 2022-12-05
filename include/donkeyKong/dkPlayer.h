#include <Arduino.h>
#include "io/joystick.h"
#include "io/memory.h"
#include "main.h"

#ifndef __DK_PLAYER_H__
#define __DK_PLAYER_H__

class DK_Player
{
public:
    void init(Memory *memory);
    void movement(int *stickValueX, int *stickValueY);

private:
    void timeInAirDelay();
    void movementHorizontally(int *stickValueX);
    void movementJump(int *stickValueY);
    void enableGravity();
};

#endif