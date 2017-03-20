/*
 * Keymap class
 * @author Simon Lövgren
 * @file Keymap.h
 */

typedef unsigned char switchmode;
#define MODE_HOLD 0
#define MODE_CLICK 1

class Keymap {
   public:
     unsigned short _pin;
     unsigned char _keycodeDown;
     unsigned char _keycodeUp;
     switchmode _mode;
     boolean _state; 
   
     Keymap(unsigned short pin, unsigned char keycodeDown, unsigned char keycodeUp, switchmode mode, boolean state);
   private:
}

