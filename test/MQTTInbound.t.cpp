#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/mqtt/MQTTInbound.h"
#include "../src/RelayLightSwitch.h"


const int UNSET = 0;
const int ON = 1;
const int OFF = 2;
const int TOGGLE = 3;

class CapturingLightSwitch : public LightSwitch
{ 
	public:
		int state = UNSET;
		CapturingLightSwitch() { };
		void externalOn()
		{
			state=ON;
		};
		void externalOff()
		{
			state=OFF;
		};
		void externalToggle()
		{
			state=TOGGLE;
		};

};

TEST_CASE("Legacy", "[MQTTInbound]") {
	CapturingLightSwitch cls{};
	const char * topicString = const_cast<char *>("topic");	
	MQTTInbound mqttInbound{topicString, &cls};

	SECTION("Preconditions") {
		REQUIRE( cls.state == UNSET);
	}
	
	

	SECTION("On Message to topic with channel") {
		mqttInbound.message("topic/channel-0","on");

		REQUIRE( cls.state == ON);
	}

}

TEST_CASE("Broadcasts", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};
	const char * topicString = const_cast<char *>("topic");	
	MQTTInbound mqttInbound{topicString, &cls};

	SECTION("Preconditions") {
		REQUIRE( cls.state == UNSET);
	}
	
	

	SECTION("On Message to topic without hostname") {
		mqttInbound.message("topic","on");
		REQUIRE( cls.state == ON);
	}

	SECTION("Off Message to topic without hostname") {
		mqttInbound.message("topic","off");
		REQUIRE( cls.state == OFF);
	}

	SECTION("Toggle Message to topic without hostname") {
		mqttInbound.message("topic","toggle");
		REQUIRE( cls.state == TOGGLE);
	}

}

/*
TEST_CASE("Messages for our hostname", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};	
	SECTION("Preconditions") {
		REQUIRE( cls.state == UNSET);
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
*/