#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Arduino.h>
#include "../SonoffApplicationCore.h"

const int OPEN=1;
const int CLOSED=2;

const int RON=1;
const int ROFF=2;

class CapturingRelay : public Relay
{
 public:
	 CapturingRelay() {};
	 RelayObserver * obs;
	 int state = -1;
	 
	 void announceClose()
	 {
		 this->obs->CLOSED();
	 };
	 void announceOpen()
	 {
		 this->obs->OPEN();
	 };

	 void addObserver(RelayObserver* obs)
	 {
		 this->obs = obs;
	 };


	 void open()
	 {
		 this->state=OPEN;
		 this->announceOpen();
	 };

	 void close()
	 {
		 this->state=CLOSED;
		 this->announceClose();
	 };
};

		class AppObserver : public SonoffApplicationCoreObserver
		{
			public:
				int state = -1;
				void ON() {
					this->state=RON;
				};
				void OFF() {
					this->state=ROFF;
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
		AppObserver appObserver{};
		
		CapturingRelay relay{};
		SonoffApplicationCore app{&relay};
		app.addObserver(&appObserver);

		relay.announceClose();

		REQUIRE( appObserver.state==RON );
	}

	SECTION("When the relay opens we tell the world we are OFF") {
		AppObserver appObserver{};
		
		CapturingRelay relay{};
		SonoffApplicationCore app{&relay};
		app.addObserver(&appObserver);

		relay.announceOpen();

		REQUIRE( appObserver.state==ROFF );
        }

	SECTION("Toggelling when off will turn on") {

		AppObserver appObserver{};
		
		CapturingRelay relay{};
		SonoffApplicationCore app{&relay};
		app.addObserver(&appObserver);
		app.externalOff();
		app.externalToggle();

		REQUIRE( appObserver.state==RON );
	}

	SECTION("Toggelling when on will turn on") {

		AppObserver appObserver{};
		
		CapturingRelay relay{};
		SonoffApplicationCore app{&relay};
		app.addObserver(&appObserver);
		app.externalOn();
		app.externalToggle();
		REQUIRE( appObserver.state==ROFF );
	}

}
