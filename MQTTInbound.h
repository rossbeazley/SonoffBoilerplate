#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "SonoffApplicationCore.h"

class MQTTInbound
{
public:
          //would a copy constructor be invoked?
MQTTInbound(char * clientID, char * topic, SonoffApplicationCore * appcore);
void connectToMQTT();
void loop();

private:
  char * mqttClientID;
  char * mqttTopic;
  WiFiClient wificlient;
  PubSubClient mqttClient{wificlient};
  void mqttCallback(const MQTT::Publish& );
  SonoffApplicationCore* appCore;
  void message(String topic, String payload);
};

