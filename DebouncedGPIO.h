#pragma once
#include "InteruptGPIOButton.h"
#include "SonoffApplicationCore.h"

class DebouncedGPIO : public AbstractButton
{
  public:
    DebouncedGPIO(LightSwitch&);
    void high(unsigned long uptime);
    void low(unsigned long uptime);
    void loop(unsigned long uptime);
  private:
    LightSwitch & lightSwitch;
    unsigned long interactionTime;
    
};

