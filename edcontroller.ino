#include <Keyboard.h>
#include "Keymap.h"
#include "ToggleSwitch.h"
#include "ArmSwitch.h"

/* 
 *  SwitchArray (simple toggle switches)
 */
const short switches_len = 6; // Length of array
ToggleSwitch switches[switches_len] = {
  ToggleSwitch(2, '}', '}', MODE_CLICK),
  ToggleSwitch(3, '{', '{', MODE_CLICK),
  ToggleSwitch(4, 'z', 'z', MODE_HOLD),
  ToggleSwitch(5, '@', '@', MODE_CLICK),
  ToggleSwitch(6, '%', '%', MODE_CLICK),
  ToggleSwitch(7, '^', '^', MODE_CLICK)
};

/* 
 *  Safety switches (Arm-switches) with builtin LED
 */
const short armswitches_len = 1;
ArmSwitch armswitches[armswitches_len] = {
  ArmSwitch(8,10,'*','*', MODE_CLICK)  
};

/*
 * Prototypes
 */
void keyEvent(Keymap *km);


void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readSwitches();
  readArmSwitches();
}

void readArmSwitches() {
  boolean state;
  for(int i = 0; i < armswitches_len; ++i) {
    state = digitalRead(armswitches[i]._pin);
    if(state != armswitches[i]._state) {
      armswitches[i]._state = state;
      keyEvent(&armswitches[i]);
      armswitches[i].led_toggle();
    }
  }
}

void readSwitches() {
  boolean state;
  for(int i = 0; i < switches_len; ++i) {
    state = digitalRead(switches[i]._pin);
    if(state != switches[i]._state) {
      switches[i]._state = state;
      keyEvent(&switches[i]);
    }
  }
}

#define CLICK_DELAY 50
void keyEvent(Keymap *km) {
  Keyboard.begin();
  if(km->_mode == MODE_HOLD) {
    if(km->_state) {
      Keyboard.press(km->_keycodeDown);
    } else {
      Keyboard.release(km->_keycodeDown);
    }
  } else if (km->_mode == MODE_CLICK) {
    if(km->_state) {
      Keyboard.press(km->_keycodeDown);
      delay(CLICK_DELAY);
      Keyboard.release(km->_keycodeDown);
    } else {
      Keyboard.press(km->_keycodeUp);
      delay(CLICK_DELAY);
      Keyboard.release(km->_keycodeUp);
    } 
  }
  Keyboard.end();
}

