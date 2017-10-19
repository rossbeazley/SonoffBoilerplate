#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../SonoffApplicationCore.h"

class CapturingRelay : public Relay
{
 public:
	 int state = -1;
	 void open()
	 {
		 this->state=1;
	 };

	 void close()
	 {
		 this->state=2;
	 };
};

TEST_CASE("TODO", "[SonoffApplicationCore]" ) {
	
	SECTION("Turning on will close the relay") {
		CapturingRelay relay{};
		SonoffApplicationCore app{&relay};
		app.externalOn();

		REQUIRE( relay.state==2 );

	}

	SECTION("Turning off will open the relay") {
	
	}

	SECTION("When the relay closes we tell the world we are ON") {

	}

	SECTION("When the relay opens we tell the world we are OFF") {

        }
}
