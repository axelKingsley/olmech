#define ROW_COUNT 8
#define COL_COUNT 16
#define KEY_COUNT 128

#define PRESS false
#define RELEASE true

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef void (*KeyEventFN) (int colIndex, int rowIndex, bool currentState);

void START(int colIndex, int rowIndex, bool currentState);
void STOP(int colIndex, int rowIndex, bool currentState);

KeyEventFN getGlobalContext();
void resetGlobalContext();
void setGlobalContext(KeyEventFN newContext);

int KeyIndex(int colIndex, int rowIndex);
int KeyRow(int keyIndex);
int KeyCol(int keyIndex);

#endif
