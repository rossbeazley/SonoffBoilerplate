#include "DebouncedGPIO.h"

DebouncedGPIO::DebouncedGPIO(LightSwitch & ls) : lightSwitch{ls}
{
  
}

void DebouncedGPIO::high()
{
  this->lightSwitch.externalToggle();
}

void DebouncedGPIO::low()
{
    
}

