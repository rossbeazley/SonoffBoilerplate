#pragma once

#include "MQTTConnection.h"
#include "../RelayLightSwitch.h"

class MQTTOutbound : public RelayLightSwitchObserver
{
  public:
     MQTTOutbound(char *mqttTopic, PublishChannel& connection);
     void updateMQTT(int channel = 0, const char*  stateString = "on");
     void ON();
      void OFF();
    
  private:
    const char * _mqttTopic;
    PublishChannel& mqttConnection;
};
 

