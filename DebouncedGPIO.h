#pragma once
#include "InteruptGPIOButton.h"
#include "SonoffApplicationCore.h"

class DebouncedGPIO : public AbstractButton
{
  public:
    DebouncedGPIO(LightSwitch&);
    void high();
    void low();
    void loop();
  private:
    LightSwitch & lightSwitch;
    
};

