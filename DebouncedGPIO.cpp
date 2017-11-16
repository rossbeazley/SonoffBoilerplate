#include "DebouncedGPIO.h"

DebouncedGPIO::DebouncedGPIO(LightSwitch & ls) : lightSwitch{ls}
{
  this->lastState=-1;
  this->lastSignal=-1;
}

void DebouncedGPIO::high(unsigned long uptime)
{
  this->lastInteractionTime = uptime;
  this->lastSignal = 0;
}

void DebouncedGPIO::low(unsigned long uptime)
{
    this->lastInteractionTime = uptime;
    this->lastSignal = 1;
}

void DebouncedGPIO::loop(unsigned long uptime)
{
  if(uptime - this->lastInteractionTime > 100) {
    if(this->lastState != this->lastSignal) {
      this->lightSwitch.externalToggle();        
    } 

    this->lastState = this->lastSignal;
  }
  
}

