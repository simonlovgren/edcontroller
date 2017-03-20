#include <Keyboard.h>
#include "types.h"

/* 
 *  SwitchArray (simple toggle switches)
 */
const short switches_len = 6; // Length of array
keybinding switches[6]; // Keybindings for switches

// Switch array setup
switches[0].pin = 2;
switches[0].keycodeDown = 'a';
switches[0].keycodeUp = 'a';
switches[0].mode = MODE_CLICK;
switches[0].state = 0;

switches[1].pin = 3;
switches[1].keycodeDown = 'b';
switches[1].keycodeUp = 'c';
switches[1].mode = MODE_CLICK;
switches[1].state = 0;

switches[2].pin = 4;
switches[2].keycodeDown = 'd';
switches[2].keycodeUp = 'd';
switches[2].mode = MODE_CLICK;
switches[2].state = 0;

switches[3].pin = 5;
switches[3].keycodeDown = 'e';
switches[3].keycodeUp = 'e';
switches[3].mode = MODE_CLICK;
switches[3].state = 0;

switches[4].pin = 6;
switches[4].keycodeDown = 'f';
switches[4].keycodeUp = 'f';
switches[4].mode = MODE_CLICK;
switches[4].state = 0;

switches[5].pin = 7;
switches[5].keycodeDown = 'g';
switches[5].keycodeUp = 'g';
switches[5].mode = MODE_HOLD;
switches[5].state = 0;

/* 
 *  Safety switches (Arm-switches) with builtin LED
 */
const short armswitches_len = 1;
armswitch armswitches[armswitches_len];

/*
 * Arm-switches setup
 */
armswitches[0] = (armswitch){9, {6, 'h', 'h', CLICK, 0}};

/*
 * Prototypes
 */
void keyChange(keybinding *kb, short state);


void setup() {
  // Initiate all switches in switch array
  for(int i = 0; i < switches_len; ++i) {
    pinMode(switches[i].pin, INPUT);
    switches[i].state = digitalRead(switches[i].pin);
  }

  // Initiate all arm switches
  for(int i = 0; i < armswitches_len; ++i) {
    pinMode(armswitches[i].keymap.pin, INPUT);
    armswitches[i].keymap.state = digitalRead(armswitches[i].keymap.pin);
    pinMode(armswitches[i].ledpin, OUTPUT);
    digitalWrite(armswitches[i].ledpin, LOW);
  }
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readSwitches();
  readArmSwitches();
  delay(100);
}

void readArmSwitches() {
  boolean state;
  for(int i = 0; i < armswitches_len; ++i) {
    state = digitalRead(armswitches[i].keymap.pin);
    if(state != armswitches[i].keymap.state) {
      keyChange(&armswitches[i].keymap, state);
      armswitches[i].keymap.state = state;
      digitalWrite(armswitches[i].ledpin, state);
    }
  }
}

void readSwitches() {
  boolean state;
  for(int i = 0; i < switches_len; ++i) {
    state = digitalRead(switches[i].pin);
    if(state != switches[i].state) {
      keyChange(&switches[i], state);
      switches[i].state = state;
    }
  }
}

void keyChange(keybinding *kb, boolean state) {
  Keyboard.begin();
  if(kb->mode == MODE_HOLD) {
    if(state) {
      Keyboard.press(kb->keycodeDown);
    } else {
      Keyboard.release(kb->keycodeDown);
    }
  } else if (kb->mode == MODE_CLICK) {
    if(state) {
      Keyboard.press(kb->keycodeDown);
      delay(2);
      Keyboard.release(kb->keycodeDown);
    } else {
      Keyboard.press(kb->keycodeUp);
      delay(2);
      Keyboard.release(kb->keycodeUp);
    } 
  }
  Keyboard.end();
}

