#pragma once

#include "setup/EEPROMSettings.h"

#include "setup/SonoffWifi.h"
#include "GPIORelay.h"
#include "buttons/SonoffInternalButton.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "mqtt/MQTTOutbound.h"
#include "mqtt/MQTTInbound.h"
#include "mqtt/MQTTConnection.h"
#include "mqtt/MQTTPubSubClientConnection.h"

#include "buttons/DebouncedGPIO.h"

#include <OTAUpdate.h>

#include "debug/SerialLog.h"

class StateDebug : public RelayLightSwitchObserver
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
    
    SerialLog log{};

    EEPROMSettings sonoffSettings{};
    
    OTAUpdate otaUpdate{sonoffSettings.sonoffHostname(), sonoffSettings.mqttClientID()};
    
    SonoffWifi wifi{sonoffSettings, log};
    
    GPIORelay relay{12};
    
    RelayLightSwitch myCore{relay, sonoffSettings.bootState() };
    
    SonoffInternalButton internalButton{&myCore};
    
    MQTTInbound inbound{sonoffSettings.mqttTopic(), &myCore, sonoffSettings.sonoffHostname()};
    
    MQTTConnection mttConnection{sonoffSettings.mqttServer(), atoi(sonoffSettings.mqttPort()), sonoffSettings.mqttClientID(),sonoffSettings.mqttTopic(), &inbound};
    MQTTOutbound outbound{sonoffSettings.mqttTopic(), sonoffSettings.sonoffHostname(), mttConnection}; //NEED TO WIRE THIS UP AS AN OBSERVER
    
    DebouncedGPIO debouncedButton{myCore};
    InteruptGPIOButton interuptButton{debouncedButton};
};


