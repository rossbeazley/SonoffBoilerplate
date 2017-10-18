#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../SonoffRelay.h"

TEST_CASE("Relay pin mode set to OUTPUT", "[SonoffRelay]" ) {
	for (int i = 0; i < 12; i++) {
		spyPinMode[i] = 0;
		spyPinState[i] = 0;
	}
	
	SECTION("Relay setup") { 
		SonoffRelay relay{0};

	    REQUIRE( spyPinMode[12] == OUTPUT );
	}

	SECTION("Relay initial state") {
		SonoffRelay relay{0};

    	REQUIRE( spyPinState[12] == HIGH );
	}
}
