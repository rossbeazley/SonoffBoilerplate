#pragma once

#include "EEPROMSettings.h"

#include "SonoffWifi.h"
#include "GPIORelay.h"
#include "SonoffInternalButton.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MQTTOutbound.h"
#include "MQTTInbound.h"
#include "MQTTConnection.h"

#include "DebouncedGPIO.h"

#include "OTAUpdate.h"

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
    
    EEPROMSettings sonoffSettings{};
    
    OTAUpdate otaUpdate{sonoffSettings.mqttServer(), sonoffSettings.mqttClientID()};
    
    SonoffWifi wifi{sonoffSettings};
    
    GPIORelay relay{12};
    
    SonoffApplicationCore myCore{relay, sonoffSettings.bootState() };
    
    SonoffInternalButton internalButton{&myCore};
    
    MQTTInbound inbound{sonoffSettings.mqttTopic(), &myCore};
    
    MQTTConnection mttConnection{sonoffSettings.mqttServer(), atoi(sonoffSettings.mqttPort()), sonoffSettings.mqttClientID(),sonoffSettings.mqttTopic(), &inbound};
    MQTTOutbound outbound{sonoffSettings.mqttTopic(), mttConnection};
    
    DebouncedGPIO debouncedButton{myCore};
    InteruptGPIOButton interuptButton{debouncedButton};
};


