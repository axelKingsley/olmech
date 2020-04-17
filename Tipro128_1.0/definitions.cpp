#include "definitions.h"

typedef void (*KeyEventFN) (int colIndex, int rowIndex, bool currentState);

void START(int colIndex, int rowIndex, bool currentState){}
void STOP(int colIndex, int rowIndex, bool currentState){}

KeyEventFN GLOBAL_CONTEXT_FUNCTION = START;
KeyEventFN getGlobalContext() {
  return GLOBAL_CONTEXT_FUNCTION;
}
void resetGlobalContext() {
  GLOBAL_CONTEXT_FUNCTION = START;
}
void setGlobalContext(KeyEventFN newContext) {
  GLOBAL_CONTEXT_FUNCTION = newContext;
}

int KeyIndex(int colIndex, int rowIndex) {
  return colIndex + (COL_COUNT * rowIndex);
}

int KeyRow(int keyIndex) {
  return keyIndex % COL_COUNT;
}

int KeyCol(int keyIndex) {
  return keyIndex / COL_COUNT;
}
