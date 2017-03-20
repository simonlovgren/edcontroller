#include "ToggleSwitch.h"

ToggleSwitch::ToggleSwitch(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode)
:Keymap(keycodeDown, keycodeUp, mode)
{
  _pin = pin;
  pinMode(_pin, INPUT);
  _state = digitalRead(_pin);
}
