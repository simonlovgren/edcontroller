/*
 * ArmSwitch class
 * @author Simon Lövgren
 * @file Keymap.h
 */


#ifndef ED_ARM_SWITCH
#define ED_ARM_SWITCH

#include <Arduino.h>
#include "edc.h"
#include "ToggleSwitch.h"

using namespace EDC;

class ArmSwitch: public ToggleSwitch {
   public:
     unsigned short _led;
     boolean _led_state;
     ArmSwitch(unsigned short pin, unsigned short led_pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode);

     // LED handlers
     void led_on();
     void led_off();
     void led_toggle();
};

#endif
