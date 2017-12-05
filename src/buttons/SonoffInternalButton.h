#pragma once
#include <Arduino.h>
#include "RelayLightSwitch.h"

const int CMD_WAIT = 0;
const int CMD_BUTTON_CHANGE = 1;

class SonoffInternalButton
{
  public:
    SonoffInternalButton(RelayLightSwitch*);
    void loop();
    void toggleState();
    void restart();
    void reset();
  private:
    RelayLightSwitch * core;
    int buttonState = HIGH;
    long startPress = 0;
    int cmd = CMD_WAIT;

};


