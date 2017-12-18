#pragma once
#include <Arduino.h>
#include "../RelayLightSwitch.h"

class MQTTInbound
{
  public:
    MQTTInbound(char * topic, LightSwitch * appcore);
    void message(String topic, String payload);

  private:
    char * mqttTopic;
    LightSwitch* appCore;

};

