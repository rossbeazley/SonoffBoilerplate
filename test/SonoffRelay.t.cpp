#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../src/SonoffRelay.h"

class CapturingObserver : public RelayObserver
{ public:
	int cState = -1;
   void state(int state) {
	cState = state;
   }
};

TEST_CASE("Relay pin mode set to OUTPUT", "[SonoffRelay]" ) {
	for (int i = 0; i < 12; i++) {
		spyPinMode[i] = 0;
		spyPinState[i] = 0;
	}
	
	SECTION("Relay setup") { 
		SonoffRelay relay{0};

	    REQUIRE( spyPinMode[12] == OUTPUT );
	}

	SECTION("Announces state change") {
		SonoffRelay relay{0};
		CapturingObserver c{};
		relay.attachObserver(&c);
		relay.turnOff();

	REQUIRE( c.cState == LOW);
	}

}
