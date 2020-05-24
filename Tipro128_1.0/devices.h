#include "definitions.h"
#ifndef SIGNALPROCESS_H
#define SIGNALPROCESS_H
void startHaptics();
void stopHaptics();
void turnOn(int voltagePin);
void turnOff(int voltagePin);
void updateRow(int rowIndex);
void updateDevices();
void initializeDevices();
bool hasChanged(int keyNumber);
bool knownState(int keyNumber);
bool RotaryPositionHasChanged()  ;
bool RotaryClickHasChanged()  ;
int  RotaryClickKnownState()  ;
int  RotaryPositionKnownState()  ;
void updateRotary();
void  RotaryPositionClearState();
#endif
