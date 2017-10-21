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
	this->obs->OPEN();
};

void GPIORelay::close() {

};

void GPIORelay::addObserver(RelayObserver* obs) {
	this->obs=obs;
}

class CapturingRelayObserver : public RelayObserver
{
	public:
		void OPEN()
		{ this->state = sOPEN;
		};
		void CLOSED()
		{ this->state = sCLOSED;
		};
		static int sOPEN;
		static int sCLOSED;
		int state=-1;
};

int CapturingRelayObserver::sOPEN=1;
int CapturingRelayObserver::sCLOSED=1;


TEST_CASE("GPIO Relay opens and closes", "[GPIORelay]" ) {
	for (int i = 0; i < 12; i++) {
		spyPinMode[i] = 0;
		spyPinState[i] = 0;
	}
			
	SECTION("Relay setup") { 
		const int pinno=12;

		GPIORelay relay{pinno};

	REQUIRE( spyPinMode[pinno] == OUTPUT );
    	}

	SECTION("Opening announces state change") {
			
		CapturingRelayObserver capturingObserver{};

		const int pinno=12;
		GPIORelay relay{pinno};
		relay.addObserver(&capturingObserver);
		relay.open();
		REQUIRE( capturingObserver.state == CapturingRelayObserver::sOPEN);
											}

}

