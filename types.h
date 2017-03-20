/* 
 *  Types of switch-modes
 */
typedef unsigned char switchmode;
#define MODE_HOLD 0
#define MODE_CLICK 1

/* 
 *  Keybinding struct
 */
typedef struct {
  unsigned short pin;
  unsigned char keycodeDown;
  unsigned char keycodeUp;
  switchmode mode;
  boolean state;
} keybinding;

/* 
 *  Safety switches (Arm-switches) with builtin LED
 */
typedef struct {
  unsigned short ledPin;
  keybinding keymap;
} armswitch;
