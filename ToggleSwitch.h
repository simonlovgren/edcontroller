/*
 * ToggleSwitch class
 * @author Simon Lövgren
 * @file Keymap.h
 */

#ifndef ED_TOGGLE_SWITCH
#define ED_TOGGLE_SWITCH

#include <Arduino.h>
#include "edc.h"
#include "Keymap.h"

using namespace EDC;

class ToggleSwitch: public Keymap {
   public:
     unsigned short _pin;
     ToggleSwitch(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode);
};

#endif
