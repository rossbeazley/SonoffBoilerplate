#pragma once
#include <Arduino.h>
#include "../RelayLightSwitch.h"
#include "MQTTInboundCommand.h"
class MQTTInbound
{
  public:
    MQTTInbound(const char * topic, LightSwitch * appcore, const char * hostname);
    void message(String topic, String payload);

  private:
    const char * mqttTopic;
    const char * hostname;
    MQTTInboundCommand * commandProcessor = nullptr;
    void processCommand(String payload);

};

