#pragma once
#include <PubSubClient.h>
#include "SonoffApplicationCore.h"

class MQTTInbound
{
public:
          // if i just use PubSubClient mqttClient, would a copy constructor be invoked?
MQTTInbound(PubSubClient * psC,char * clientID, char * topic, SonoffApplicationCore * appcore);
void connectToMQTT();

private:
  char * mqttClientID;
  char * mqttTopic;
  PubSubClient * mqttClient;
  void mqttCallback(const MQTT::Publish& );
  SonoffApplicationCore* appCore;
};
