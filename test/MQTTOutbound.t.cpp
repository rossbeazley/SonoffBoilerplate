#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <Arduino.h>

#include "../src/mqtt/MQTTOutbound.h"
#include "../src/RelayLightSwitch.h"


class CapturingPublishChannel : public PublishChannel
{
	public:
		CapturingPublishChannel(){};
		void publish(const char * topic, const char * payload){
			publishedTopic = const_cast<char*>(topic);
			publishedPayload = const_cast<char*>(payload);
		};
		char * publishedTopic = const_cast<char*>("unset");
		char * publishedPayload = const_cast<char*>("unset");
};

TEST_CASE("Transmits state", "[MQTTOutbound]" ) {

	char* randomTopic = const_cast<char*>("random");
	CapturingPublishChannel channel{};
	MQTTOutbound outbound{randomTopic, channel};

	SECTION("On Message to topic without hostname") {

		REQUIRE( channel.publishedPayload == "on");
	}

	SECTION("Off Message to topic without hostname") {

		REQUIRE( channel.publishedPayload == "off");
	}

	SECTION("Toggle Message to topic without hostname") {

		REQUIRE( channel.publishedTopic == randomTopic);
	}

}

