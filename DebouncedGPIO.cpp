#include "DebouncedGPIO.h"

DebouncedGPIO::DebouncedGPIO(LightSwitch & ls) : lightSwitch{ls}
{
  
}

void DebouncedGPIO::high()
{

}

void DebouncedGPIO::low()
{
    
}

void DebouncedGPIO::loop()
{
  this->lightSwitch.externalToggle();  
}

