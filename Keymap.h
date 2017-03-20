/*
 * Keymap class
 * @author Simon Lövgren
 * @file Keymap.h
 */

#ifndef ED_KEYMAP
#define ED_KEYMAP

#include <Arduino.h>
#include "edc.h"

using namespace EDC;

typedef unsigned char switchmode;
#define MODE_HOLD 0
#define MODE_CLICK 1

class Keymap {
   public:
     unsigned char _keycodeDown;
     unsigned char _keycodeUp;
     switchmode _mode;
     boolean _state; 
   
     Keymap(unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode);
};

#endif
