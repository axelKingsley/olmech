#include "definitions.h"
#include "devices.h"
#include "keyboard.h"
#include "debug.h"
#include "rotary.h"

void setup() {
  initializeDevices();
}

void evaluateEvent(int keyNumber) {
    if ( ! hasChanged(keyNumber) ) return;

    bool pressedState = knownState(keyNumber);

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

    //historyHandler(keyNumber, pressedState, eventStatus);
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
    evaluateEvent(i);
  }

  evaluateRotary();

}
