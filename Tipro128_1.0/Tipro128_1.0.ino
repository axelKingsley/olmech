#include "definitions.h"
#include "devices.h"
#include "keyboard.h"
#include "debug.h"
#include "rotary.h"

int hapticDuration = 1000;
ulong hapticMoment = 0;
void setup() {
  initializeDevices();
}

void evaluateEvent(int keyNumber) {

    if ( ! hasChanged(keyNumber) ) return;

    //startHaptics();
    //delay(30);
    //stopHaptics();
    hapticMoment = millis();
    bool pressedState = knownState(keyNumber);
    if (pressedState == PRESS) startHaptics();
    if (pressedState == RELEASE) stopHaptics();
    resetGlobalContext();

    debugHandler(keyNumber, pressedState, NOOP);
    if (getGlobalContext() == STOP) return;

    layer3Handler(keyNumber, pressedState, NOOP);
    if (getGlobalContext() == STOP) return;

    layer2Handler(keyNumber, pressedState, NOOP);
    if (getGlobalContext() == STOP) return;

    layer1Handler(keyNumber, pressedState, NOOP);
    if (getGlobalContext() == STOP) return;

    layer0Handler(keyNumber, pressedState, NOOP);
    if (getGlobalContext() == STOP) return;

}

void evaluateRotary(){
  rotaryPositionHandler(RotaryPositionKnownState());

  if (  RotaryClickHasChanged() ) {
    rotaryClickHandler(RotaryClickKnownState());
  };
}

void loop() {
  updateDevices();

  for (int i = 0; i < KEY_COUNT; i++)  {
    if (millis() > hapticMoment+hapticDuration) stopHaptics();
    evaluateEvent(i);
  }

  evaluateRotary();

}
