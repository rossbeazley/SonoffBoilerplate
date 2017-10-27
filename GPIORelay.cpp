#include "GPIORelay.h"

GPIORelay::GPIORelay(int gpioPin)
{
  Serial.println("Constructing GPIORelay");
	this->gpioPin = gpioPin;
	pinMode(gpioPin, OUTPUT);
  Serial.println("Constructed GPIORelay");
}

GPIORelay::~GPIORelay()
{
  Serial.println("GPIORELAY DESTRUCT");
}

void GPIORelay::open() {
	digitalWrite(this->gpioPin,LOW);
	this->obs->OPEN();
};

void GPIORelay::close() {
	digitalWrite(this->gpioPin,HIGH);
	this->obs->CLOSED();
};

void GPIORelay::addObserver(RelayObserver* obs) {
	this->obs=obs;
}



