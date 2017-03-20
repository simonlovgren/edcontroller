/*
 * Profile class
 * @author Simon Lövgren
 * @file Keymap.h
 */

#ifndef ED_PROFILE
#define ED_PROFILE

#include <Arduino.h>
#include "edc.h"
#include "ToggleSwitch.h"
#include "ArmSwitch.h"

using namespace EDC;

class Profile {
   public:
     unsigned int _toggleSwitchesLen;
     ToggleSwitch **_toggleSwitches;
     unsigned int _armSwitchesLen;
     ArmSwitch **_armSwitches;
     
     Profile(unsigned int toggleSwitches, unsigned int armSwitches);
     ~Profile();
     boolean add_toggle_switch(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode);
     boolean add_arm_switch(unsigned short pin, unsigned short led_pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode);
     
   private:
    unsigned int _toggleSwitchCount = 0;
    unsigned int _armSwitchCount = 0;
};

#endif
