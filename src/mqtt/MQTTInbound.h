#pragma once
#include <Arduino.h>
#include "../RelayLightSwitch.h"

class MQTTInbound
{
  public:
    MQTTInbound(const char * topic, LightSwitch * appcore, const char * hostname);
    void message(String topic, String payload);

  private:
    const char * mqttTopic;
    const char * hostname;
    LightSwitch* appCore;
    void processCommand(String payload);

};

