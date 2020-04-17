#include "debug.h"
#include "definitions.h"
#include <usb_keyboard.h>

bool DEBUG = false;
void debugHandler(int keyNumber, bool pressedState, KeyEventFN eventStatus){
  if (!DEBUG) return;
  int colIndex = KeyCol(keyNumber);
  int rowIndex = KeyRow(keyNumber);

  Keyboard.print(String(keyNumber) + "::" + String(colIndex) + ":" + String(rowIndex));
  return;
}
