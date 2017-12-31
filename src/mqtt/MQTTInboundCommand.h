#pragma once
#include <Arduino.h>
#include "../RelayLightSwitch.h"

class MQTTInboundCommand
{
  public:
    MQTTInboundCommand(LightSwitch * appcore);
    void processCommand(String payload);

  private:
    LightSwitch* appCore;

};

