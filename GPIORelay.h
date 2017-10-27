#pragma once
#include "SonoffApplicationCore.h"
#include <Arduino.h>

class GPIORelay : public Relay
{
 public:
	 GPIORelay(int gpioPin);
   ~GPIORelay();
	 void open();
	 void close();
	 void addObserver(RelayObserver*);
 private:
	 RelayObserver* obs;
	 int gpioPin;
};


