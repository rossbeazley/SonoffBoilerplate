#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../SonoffApplicationCore.h"

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

GPIORelay::GPIORelay(int gpioPin)
{
	this->gpioPin = gpioPin;
	pinMode(gpioPin, OUTPUT);
}

void GPIORelay::open() {

};

void GPIORelay::close() {

};

void GPIORelay::addObserver(RelayObserver* obs) {

}



TEST_CASE("GPIO Relay opens and closes", "[GPIORelay]" ) {
	for (int i = 0; i < 12; i++) {
		spyPinMode[i] = 0;
		spyPinState[i] = 0;
	}
			
	SECTION("Relay setup") { 
		GPIORelay relay{12};

	REQUIRE( spyPinMode[12] == OUTPUT );
    	}

	SECTION("Announces state change") {
											//REQUIRE( c.cState == LOW);
											}

}

