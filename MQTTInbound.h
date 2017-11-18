#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "SonoffApplicationCore.h"

class MQTTInbound
{
  public:
    MQTTInbound(char * topic, SonoffApplicationCore * appcore);
    void message(String topic, String payload);

  private:
    char * mqttTopic;
    SonoffApplicationCore* appCore;
};

