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
	MQTTInbound mqttInbound{topicString, &cls, "channel-0"};

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
	MQTTInbound mqttInbound{topicString, &cls, "anyhost"};

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


TEST_CASE("Messages for our hostname", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};	
	const char * topicString = const_cast<char *>("othertopic");	
	MQTTInbound mqttInbound{topicString, &cls, "myhost"};

	SECTION("Preconditions") {
		REQUIRE( cls.state == UNSET);
	}

	
	SECTION("On Message to topic for our hostname") {
		mqttInbound.message("othertopic/myhost","on");
		REQUIRE( cls.state == ON);
	}

	SECTION("Off Message to topic for our hostname") {
		mqttInbound.message("othertopic/myhost","off");
		REQUIRE( cls.state == OFF);
	}

	SECTION("Toggle Message to topic for our hostname") {
		mqttInbound.message("othertopic/myhost","toggle");
		REQUIRE( cls.state == TOGGLE);
	}
/* ive been ignoring the hint from my tests that there are two concerns here "routing" and "command"
   maybe i would have written less tests by having only three routing tests and three command tests
   rather than 9 routed command tests

   i can at least introduce this structure into my final inbound class
   */
	
}

TEST_CASE("Messages for other hostnames", "[MQTTInbound]" ) {

	CapturingLightSwitch cls{};	
	const char * topicString = const_cast<char *>("othertopic");	
	MQTTInbound mqttInbound{topicString, &cls, "noymyhost"};

	SECTION("Preconditions") {
		REQUIRE( cls.state == UNSET);
	}
	
	SECTION("On Message to topic for other hostname") {
		mqttInbound.message("othertopic/myhost","on");
		REQUIRE( cls.state == UNSET);
	}

	SECTION("Off Message to topic for other hostname") {
		mqttInbound.message("othertopic/myhost","off");
		REQUIRE( cls.state == UNSET);
	}

	SECTION("Toggle Message to topic for other hostname") {
		mqttInbound.message("othertopic/myhost","toggle");
		REQUIRE( cls.state == UNSET);
	}
}

TEST_CASE("Broadcast storm","[MQTTInbound]") {

	CapturingLightSwitch cls{};	
	const char * topicString = const_cast<char *>("loungeLights");	
	MQTTInbound mqttInbound{topicString, &cls, "corner"};

	SECTION("Preconditions") {
		REQUIRE( cls.state == UNSET);
	}
	
	SECTION("Status broadcast message is ignored") {
		mqttInbound.message("loungeLights/corner/status","on");
		REQUIRE( cls.state == UNSET);
	}
}
