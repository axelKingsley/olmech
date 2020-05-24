#include "devices.h"
#include "definitions.h"
#include <Arduino.h>
#include <Encoder.h>

/*//////////////////////////////////////////////////////////////////////////////
HAPTIC DEVICE
//////////////////////////////////////////////////////////////////////////////*/
int HAPTIC1 = 33;
int HAPTIC2 = 39;

void startHaptics(){
  digitalWrite(HAPTIC1, HIGH);
  digitalWrite(HAPTIC2, HIGH);

}

void stopHaptics(){
   digitalWrite(HAPTIC2, LOW);
   digitalWrite(HAPTIC1, LOW);
}

/*//////////////////////////////////////////////////////////////////////////////
ROTARY DEVICE
//////////////////////////////////////////////////////////////////////////////*/

int ROTARY_CLICK = 17;
bool rotaryClickHasChanged = false;
int rotaryClickKnownState = RELEASE;
bool RotaryClickHasChanged() {return rotaryClickHasChanged;}
int  RotaryClickKnownState() {return rotaryClickKnownState;}

Encoder ROTARY(18, 19);
int rotaryPositionKnownState = 0;
int  RotaryPositionKnownState() {return rotaryPositionKnownState;}

void updateRotary(){
    // Package the button press in the same way as a key event
    int currentClickState = digitalRead(ROTARY_CLICK);
    rotaryClickHasChanged = currentClickState != rotaryClickKnownState ? true : false;
    rotaryClickKnownState = currentClickState;

    rotaryPositionKnownState = ROTARY.read();
    ROTARY.write(0);
  }

/*//////////////////////////////////////////////////////////////////////////////
KEY MATRIX DEVICE
//////////////////////////////////////////////////////////////////////////////*/
int colPins[] =
 {20,
  21,
  22,
  23,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12};

int rowPins[] ={
  25,
  26,
  27,
  28,
  32,
  31,
  30,
  29};

bool HasChanged[KEY_COUNT];
bool hasChanged(int keyNumber) {
  return HasChanged[keyNumber];
}

bool KnownState[KEY_COUNT];
bool knownState(int keyNumber) {
  return KnownState[keyNumber];
}


void turnOn(int voltagePin) {
  pinMode(voltagePin, OUTPUT);
  digitalWrite(voltagePin, LOW);
  delay(1);
}

void turnOff(int voltagePin) {
  pinMode(voltagePin, INPUT);
  delay(1);
}

void updateRow(int rowIndex) {
  int rowPin = rowPins[rowIndex];
  turnOn(rowPin);

  for (int colIndex = 0 ; colIndex < 16; colIndex++) {
    int colPin = colPins[colIndex];
    bool currentState = digitalRead(colPin);

    int keyIndex = KeyIndex(colIndex, rowIndex);
    HasChanged[keyIndex] = currentState != KnownState[keyIndex];
    KnownState[keyIndex] = currentState;
  }
  turnOff(rowPin);
}

/*//////////////////////////////////////////////////////////////////////////////
Top Level Functions
//////////////////////////////////////////////////////////////////////////////*/
void updateDevices() {
    for (int row = 0; row < ROW_COUNT; row++) {
      updateRow(row);
    }
    updateRotary();
}

void initializeDevices() {
  // Set input pins
  for (int i = 0; i < COL_COUNT; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
  pinMode(ROTARY_CLICK, INPUT_PULLUP);
  pinMode(HAPTIC1, OUTPUT);
  pinMode(HAPTIC2, OUTPUT);
  // Clear the starting states
  for (int i = 0; i < KEY_COUNT; i++) {
    KnownState[i] = RELEASE;
    HasChanged[i] = false;
  }

}
