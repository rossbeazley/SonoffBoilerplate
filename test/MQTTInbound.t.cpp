#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/mqtt/MQTTInbound.h"
#include "../src/RelayLightSwitch.h"

class CapturingLightSwitch : public LightSwitch
{ 
	public:
		int state = 0;
		CapturingLightSwitch() { };
		void externalOn()
		{
			state=1;
		};
		void externalOff()
		{
			state=2;
		};
		void externalToggle()
		{
			state=4;
		};

};

TEST_CASE("Broadcasts", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};
	const char * topicString = const_cast<char *>("topic");	
	MQTTInbound mqttInbound{topicString, &cls};

	SECTION("Preconditions") {
		REQUIRE( cls.state == 0);
	}
	
	

	SECTION("On Message to topic without hostname") {

		REQUIRE( cls.state == 1);
	}

	SECTION("Off Message to topic without hostname") {

		REQUIRE( cls.state == 2);
	}

	SECTION("Toggle Message to topic without hostname") {

		REQUIRE( cls.state == 4);
	}

}


TEST_CASE("Messages for our hostname", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};	
	SECTION("Preconditions") {
		REQUIRE( cls.state == 0);
	}

	
	SECTION("On Message to topic for our hostname") {

		REQUIRE( cls.state == 1);
	}

	SECTION("Off Message to topic for our hostname") {

		REQUIRE( cls.state == 2);
	}

	SECTION("Toggle Message to topic for our hostname") {

		REQUIRE( cls.state == 4);
	}

	
}


TEST_CASE("Messages for other hostnames", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};	
	SECTION("Preconditions") {
		REQUIRE( cls.state == 0);
	}
	
	SECTION("On Message to topic for other hostname") {

		REQUIRE( cls.state == 1);
	}

	SECTION("Off Message to topic for other hostname") {

		REQUIRE( cls.state == 2);
	}

	SECTION("Toggle Message to topic for other hostname") {

		REQUIRE( cls.state == 4);
	}
}
