#pragma once

#include "EEPROMSettings.h"

#include "SonoffWifi.h"
#include "GPIORelay.h"
#include "SonoffInternalButton.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MQTTOutbound.h"
#include "MQTTInbound.h"


class SonoffApplicationShell
{
  public:
    SonoffApplicationShell();
    ~SonoffApplicationShell();
    void loop();
    void debugDump();
  private:
    EEPROMSettings sonoffSettings;
    SonoffWifi wifi{sonoffSettings};
    GPIORelay relay{12};
    SonoffApplicationCore myCore{&relay, sonoffSettings.bootState() };
    SonoffInternalButton internalButton{&myCore};
    MQTTOutbound mob{sonoffSettings.mqttTopic()};
    MQTTInbound inbound{sonoffSettings.mqttClientID(),sonoffSettings.mqttTopic(), &myCore};
};


