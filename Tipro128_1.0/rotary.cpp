#include "definitions.h"
#include "rotary.h"
#include <usb_keyboard.h>

int SENSITIVITY = 4;
int DETECTED = 0;
void rotaryPositionHandler(int position) {
  DETECTED += position;
  if (position == 0) return;
  if (DETECTED <= -1 * SENSITIVITY){
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
     DETECTED = 0;
  }
  if (DETECTED >= SENSITIVITY){
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
     DETECTED = 0;
  }
}

void rotaryClickHandler(int rotaryClickKnownState) {
  if (rotaryClickKnownState == PRESS) {
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
    Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
    }

}
