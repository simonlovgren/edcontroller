#ifndef ED_TOGGLE_SWITCH
#define ED_TOGGLE_SWITCH

#include <Arduino.h>
#include "Keymap.h"
/*
 * ToggleSwitch class
 * @author Simon Lövgren
 * @file Keymap.h
 */

class ToggleSwitch: public Keymap {
   public:
     unsigned short _pin;
     ToggleSwitch(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode);
};

#endif
