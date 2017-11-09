#pragma once
#include <Arduino.h>
#include "SonoffApplicationCore.h"

const int CMD_WAIT = 0;
const int CMD_BUTTON_CHANGE = 1;

class SonoffInternalButton
{
  public:
    SonoffInternalButton(SonoffApplicationCore*);
    void loop();
    void toggleState();
    void restart();
    void reset();
  private:
    SonoffApplicationCore * core;
    int buttonState = HIGH;
    long startPress = 0;
    int cmd = CMD_WAIT;

};


