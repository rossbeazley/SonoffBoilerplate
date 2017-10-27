#pragma once

#include <ESP8266WiFi.h>
#include <PubSubClient.h> 

class MQTTOutbound
{
  public:
     MQTTOutbound(char *mqttTopic);
     void updateMQTT(int channel = 0, int state = 0);
  private:
    WiFiClient wificlient;
    PubSubClient _mqttClient{wificlient};
    const char * _mqttTopic;
};
 

