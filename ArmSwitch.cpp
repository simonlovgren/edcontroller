#include "ArmSwitch.h"

ArmSwitch::ArmSwitch(unsigned short pin, unsigned short led_pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode)
:ToggleSwitch(pin, keycodeDown, keycodeUp, mode)
{
  _led = led_pin;
  _led_state = 0;
  pinMode(_led, OUTPUT);
  digitalWrite(_led, LOW);
}

void ArmSwitch::led_on() {
    _led_state = 1;
    digitalWrite(_led, HIGH);
}
void ArmSwitch::led_off() {
    _led_state = 0;
    digitalWrite(_led, LOW);
}
void ArmSwitch::led_toggle() {
  if(_led_state) {
    led_off();
  } else {
    led_on();
  }
}

