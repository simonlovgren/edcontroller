#include "Profile.h"

Profile::Profile(unsigned int toggleSwitches, unsigned int armSwitches) {
  _toggleSwitchesLen = toggleSwitches;
  _toggleSwitches = (ToggleSwitch**)malloc(sizeof(ToggleSwitch *) * toggleSwitches);
  _armSwitchesLen = armSwitches;
  _armSwitches =(ArmSwitch**) malloc(sizeof(ArmSwitch *) * armSwitches);
}

Profile::~Profile() {
  if(_toggleSwitches != NULL)
    free(_toggleSwitches);
  if(_armSwitches != NULL)
    free(_armSwitches);
}


boolean Profile::add_toggle_switch(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode){
  if(_toggleSwitchCount < _toggleSwitchesLen) {
    _toggleSwitches[_toggleSwitchCount] = new ToggleSwitch(pin, keycodeDown, keycodeUp, mode);
    return true;
  }
  return false;
}
boolean Profile::add_arm_switch(unsigned short pin, unsigned short led_pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode){
  if(_armSwitchCount < _armSwitchesLen) {
    _armSwitches[_armSwitchCount] = new ArmSwitch(pin, led_pin, keycodeDown, keycodeUp, mode);
    return true;
  }
  return false;
}

