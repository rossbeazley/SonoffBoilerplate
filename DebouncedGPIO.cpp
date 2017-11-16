#include "DebouncedGPIO.h"

DebouncedGPIO::DebouncedGPIO(LightSwitch & ls) : lightSwitch{ls}
{
  
}

void DebouncedGPIO::high(unsigned long uptime)
{
  this->interactionTime = uptime;
}

void DebouncedGPIO::low(unsigned long uptime)
{
    
}

void DebouncedGPIO::loop(unsigned long uptime)
{
  if(uptime - this->interactionTime > 100) {
    this->lightSwitch.externalToggle();  
  }
  
}

