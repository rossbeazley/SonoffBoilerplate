#pragma once
#include "RelayLightSwitch.h"
#include <Arduino.h>

class GPIORelay : public Relay
{
 public:
	 GPIORelay(int gpioPin);
   void open();
	 void close();
	 void addObserver(RelayObserver*);
 private:
	 RelayObserver* obs;
	 int gpioPin;
};


