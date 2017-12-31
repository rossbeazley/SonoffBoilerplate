#include "MQTTInboundCommand.h"
#include <Arduino.h>


MQTTInboundCommand::MQTTInboundCommand(LightSwitch * appcore) :
  appCore{appcore}
{

}


// should really move this to its own class
void MQTTInboundCommand::processCommand(String payload)
{
  if (payload == "on") {
      this->appCore->externalOn();
    }
    else if (payload == "off") {
      this->appCore->externalOff();
    }
    else if (payload == "toggle") {
      this->appCore->externalToggle();
    }
}
