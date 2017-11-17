#pragma once

#include "EEPROMSettings.h"

#include "SonoffWifi.h"
#include "GPIORelay.h"
#include "SonoffInternalButton.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MQTTOutbound.h"
#include "MQTTInbound.h"

#include "DebouncedGPIO.h"

class StateDebug : public SonoffApplicationCoreObserver
{
  public:
  StateDebug(){};
  void ON() {
    Serial.println("LIGHT ON");
  };
  void OFF() {
    Serial.println("LIGHT OFF");
  }
};

class SonoffApplicationShell
{
  public:
    SonoffApplicationShell();
    void loop();
    void debugDump();
  private:
    StateDebug sd{};
    EEPROMSettings sonoffSettings;
    SonoffWifi wifi{sonoffSettings};
    GPIORelay relay{12};
    SonoffApplicationCore myCore{&relay, sonoffSettings.bootState() };
    SonoffInternalButton internalButton{&myCore};
    MQTTOutbound mob{sonoffSettings.mqttTopic()};
    MQTTInbound inbound{sonoffSettings.mqttClientID(),sonoffSettings.mqttTopic(), &myCore};
    DebouncedGPIO debouncedButton{myCore};
    InteruptGPIOButton interuptButton{debouncedButton};
};


