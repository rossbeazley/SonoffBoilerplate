#pragma once

#include <PubSubClient.h> 

class MQTTOutbound
{
  public:
     MQTTOutbound(PubSubClient & psC, char *mqttTopic);
     void updateMQTT(int channel = 0, int state = 0);
  private:
    const PubSubClient & _mqttClient;
    const char * _mqttTopic;
};
 
