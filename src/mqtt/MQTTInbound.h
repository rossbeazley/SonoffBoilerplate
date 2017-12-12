#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "RelayLightSwitch.h"

class MQTTInbound
{
  public:
    MQTTInbound(char * topic, LightSwitch * appcore);
    void message(String topic, String payload);

  private:
    char * mqttTopic;
    LightSwitch* appCore;
    
};

