#include "Keymap.h"

/*
     unsigned short _pin;
     unsigned char _keycodeDown;
     unsigned char _keycodeUp;
     switchmode _mode;
     boolean _state;
*/

Keymap::Keymap(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode, boolean state) {
  _pin = pin;
  _keycodeDown = keycodeDown;
  _keycodeUp = keycodeUp;
  _mode = mode;
  _state = state;
}

