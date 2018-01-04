#pragma once

#include "MQTTConnection.h"
#include "../RelayLightSwitch.h"

class MQTTOutbound : public RelayLightSwitchObserver
{
  public:
     MQTTOutbound(char *topic, char *hostname, PublishChannel& connection);
     void updateMQTT(int channel = 0, const char*  stateString = "on");
     void ON();
      void OFF();
    
  private:
    const char * _mqttTopic;
    const char * _hostname;
    PublishChannel& mqttConnection;
};
 

