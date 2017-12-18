#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/mqtt/MQTTOutbound.h"
#include "../src/RelayLightSwitch.h"

class CapturingPublishChannel : public PublishChannel
{
	public:
		CapturingPublishChannel();
		void publish(const char * topic, const char * payload);
		char * publishedTopic = "unset";
		char * publishedPayload = "unset";
};

TEST_CASE("Transmits state", "[MQTTOutbound]" ) {

	char* randomTopic = "random";
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

