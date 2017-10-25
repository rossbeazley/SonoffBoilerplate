
#include <ESP8266WiFi.h>

#include "SonoffApplicationCore.h"
#include "GPIORelay.h"
#include "EEPROMSettings.h"
#include "MQTTOutbound.h"
#include "MQTTInbound.h"
#include "SonoffApplicationShell.h"
#include "SonoffInternalButton.h"


#include <PubSubClient.h>        //https://github.com/Imroy/pubsubclient
WiFiClient wclient;
PubSubClient mqttClient(wclient);

MQTTOutbound * mqttOutbound = nullptr;
MQTTInbound * mqttInbound = nullptr;
GPIORelay gpioRelay(12);
SonoffApplicationCore* appCore = nullptr;
SonoffApplicationShell * appShell = nullptr;
EEPROMSettings sonoffSettings{};
SonoffInternalButton* internalButton;

static bool MQTT_ENABLED              = true;

void setup()
{
  Serial.begin(115200);

  SonoffApplicationCore myCore(&gpioRelay, (strcmp(sonoffSettings.bootState(), "on") == 0) );
  appCore = &myCore;
  
  SonoffApplicationShell ashell{};
  appShell = &ashell;

  SonoffInternalButton myInternalButton{appCore};
  internalButton = &myInternalButton;

  //config mqtt
  if (strlen(sonoffSettings.mqttHostname()) == 0) {
    MQTT_ENABLED = false;
  }
  if (MQTT_ENABLED) {
    mqttClient.set_server(sonoffSettings.mqttHostname(), atoi(sonoffSettings.mqttPort()));
  }

// setup external button
//  #define   SONOFF_INPUT              14
//  pinMode(SONOFF_INPUT, INPUT_PULLUP);
//  attachInterrupt(SONOFF_INPUT, toggleInputState, CHANGE);

  MQTTOutbound mob{&mqttClient,sonoffSettings.mqttTopic()};
  mqttOutbound = &mob;

  MQTTInbound inbound{&mqttClient,sonoffSettings.mqttClientID(),sonoffSettings.mqttTopic(), appCore};
  mqttInbound = &inbound;

  Serial.println("done setup");
}


void loop()
{

  //mqtt loop
  if (MQTT_ENABLED) {
    if (!mqttClient.connected()) {
      mqttInbound->connectToMQTT();
    } else {
      mqttClient.loop();
    }
  }
  
  internalButton->loop();

}




