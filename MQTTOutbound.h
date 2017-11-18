#pragma once

#include <ESP8266WiFi.h>
#include <PubSubClient.h> 
#include "MQTTConnection.h"

class MQTTOutbound
{
  public:
     MQTTOutbound(char *mqttTopic, MQTTConnection& connection);
     void updateMQTT(int channel = 0, int state = 0);
  private:
    WiFiClient wificlient;
    PubSubClient _mqttClient{wificlient};
    const char * _mqttTopic;
    MQTTConnection& mqttConnection;
};
 

