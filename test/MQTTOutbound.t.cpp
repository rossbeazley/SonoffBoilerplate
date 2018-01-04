#include <Arduino.h>

#include "../src/mqtt/MQTTOutbound.h"
#include "../src/RelayLightSwitch.h"

std::ostream &operator<<(std::ostream &os, String const &value)
{
	os << (value.pString);
	return os;
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class CapturingPublishChannel : public PublishChannel
{
  public:
	CapturingPublishChannel(){};
	void publish(String topic, String payload)
	{
		publishedTopic = topic;
		publishedPayload = payload;
	};
	String publishedTopic = "unset";
	String publishedPayload = "unset";
};

SCENARIO("MQTTOutbound publishes system state", "[MQTTOutbound]")
{

	char *randomTopic = const_cast<char *>("random");
	char *randomHostname = const_cast<char *>("hostname");
	String topic = "random/hostname/status";

	GIVEN("An outbound channel publishing to random/hostname/status")
	{
		CapturingPublishChannel channel{};
		MQTTOutbound outbound{randomTopic, randomHostname, channel};

		WHEN("system state goes ON")
		{
			outbound.ON();
			THEN("The message payload reflects this")
			{
				REQUIRE(channel.publishedPayload == "on");
			}
		}

		WHEN("system state goes ON")
		{
			outbound.OFF();
			THEN("The message payload reflects this")
			{
				REQUIRE(channel.publishedPayload == "off");
			}
		}

		WHEN("system state changes")
		{
			outbound.ON();
			THEN("the message is published to the configured topic")
			{
				REQUIRE(channel.publishedTopic == topic);
			}
		}
	}
}
