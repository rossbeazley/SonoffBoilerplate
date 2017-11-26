#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../src/InteruptGPIOButton.h"

class CapturingButton : public AbstractButton
{ 
	public:
		int state = 0;
		unsigned long mockTimeMillis = -1;
		CapturingButton() { };
		void high(unsigned long uptime)
		{
			state=1;
			mockTimeMillis = uptime;
		};
		void low(unsigned long uptime)
		{
			state=2;
			mockTimeMillis = uptime;
		};
		void loop(unsigned long uptime)
		{
			//UNUSED, i already know this method shouldnt be here
			mockTimeMillis = uptime;
		};

};

TEST_CASE("Relay pin mode set to OUTPUT", "[SonoffRelay]" ) {
	for (int i = 0; i < 12; i++) {
		spyPinMode[i] = 0;
		spyPinState[i] = 0;
		spyISRs[i] = NULL;
	}
	
	CapturingButton cb{};
	InteruptGPIOButton ig{cb};

	SECTION("Initialised as unknown") {
		REQUIRE( cb.state == 0);
	}

	SECTION("Pin 14 is an input") {
		REQUIRE( spyPinMode[14] == INPUT_PULLUP );
	}

	SECTION("ISR fires, button on") {
		spyPinState[14]=HIGH;
		mockTimeMillis=123;	
		if(spyISRs[14])
		{
			spyISRs[14]();	
		}

		REQUIRE( cb.state == 1);
		REQUIRE( cb.mockTimeMillis == 123);
	}

	SECTION("ISR fires, button off") {
		spyPinState[14]=LOW;
		mockTimeMillis=5431;	
		if(spyISRs[14])
		{
			spyISRs[14]();	
		}

		REQUIRE( cb.state == 2);
		REQUIRE( cb.mockTimeMillis == 5431);
	}

}
