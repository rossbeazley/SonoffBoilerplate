#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "RelayLightSwitch.h"

class MQTTInbound
{
  public:
    MQTTInbound(char * topic, RelayLightSwitch * appcore);
    void message(String topic, String payload);

  private:
    char * mqttTopic;
    RelayLightSwitch* appCore;
};

