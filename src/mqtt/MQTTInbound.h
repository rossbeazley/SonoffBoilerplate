#pragma once
#include <Arduino.h>
#include "../RelayLightSwitch.h"

class MQTTInbound
{
  public:
    MQTTInbound(const char * topic, LightSwitch * appcore);
    void message(String topic, String payload);

  private:
    const char * mqttTopic;
    LightSwitch* appCore;

};

