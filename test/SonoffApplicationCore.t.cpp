#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../SonoffApplicationCore.h"

const int OPEN=1;
const int CLOSED=2;

class CapturingRelay : public Relay
{
 public:
	 int state = -1;
	 void open()
	 {
		 this->state=OPEN;
	 };

	 void close()
	 {
		 this->state=CLOSED;
	 };
};

TEST_CASE("TODO", "[SonoffApplicationCore]" ) {
	
	SECTION("Turning on will close the relay") {
		CapturingRelay relay{};
		SonoffApplicationCore app{&relay};
		app.externalOn();

		REQUIRE( relay.state==CLOSED );

	}

	SECTION("Turning off will open the relay") {
		CapturingRelay relay{};
                SonoffApplicationCore app{&relay};
	        app.externalOff();

                REQUIRE( relay.state==OPEN );


	}

	SECTION("When the relay closes we tell the world we are ON") {

	}

	SECTION("When the relay opens we tell the world we are OFF") {

        }
}
