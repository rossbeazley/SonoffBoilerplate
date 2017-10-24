/*
   1MB flash sizee

   sonoff header
   1 - vcc 3v3
   2 - rx
   3 - tx
   4 - gnd
   5 - gpio 14

   esp8266 connections
   gpio  0 - button
   gpio 12 - relay
   gpio 13 - green led - active low
   gpio 14 - pin 5 on header

*/

#define   SONOFF_BUTTON             0
#define   SONOFF_INPUT              14
#define   SONOFF_AVAILABLE_CHANNELS 1
//if this is false, led is used to signal startup state, then always on
//if it s true, it is used to signal startup state, then mirrors relay state
//S20 Smart Socket works better with it false
#define SONOFF_LED_RELAY_STATE      false


//comment out to completly disable respective technology
#define INCLUDE_MQTT_SUPPORT


/********************************************
   Should not need to edit below this line *
 * *****************************************/
#include <ESP8266WiFi.h>



#include "SonoffApplicationCore.h"
#include "GPIORelay.h"


#include <PubSubClient.h>        //https://github.com/Imroy/pubsubclient

WiFiClient wclient;
PubSubClient mqttClient(wclient);

#include "MQTTInbound.h"
MQTTInbound * mqttInbound = nullptr;


static bool MQTT_ENABLED              = true;

#include "EEPROMSettings.h"

#include "MQTTOutbound.h"
MQTTOutbound * mqttOutbound = nullptr;

#include <ArduinoOTA.h>


const int CMD_WAIT = 0;
const int CMD_BUTTON_CHANGE = 1;
const int CMD_INPUT_CHANGE = 2;

int cmd = CMD_WAIT;
//int relayState = HIGH;

//inverted button state
int buttonState = HIGH;
int inputStateCount = 5;

static long startPress = 0;

//SonoffRelay relay(12);
GPIORelay gpioRelay(12);
SonoffApplicationCore appCore(&gpioRelay);




void toggleState() {
  cmd = CMD_BUTTON_CHANGE;
}

void toggleInputState() {
  cmd = CMD_INPUT_CHANGE;
}



void restart() {
  //TODO turn off relays before restarting
  ESP.reset();
  delay(1000);
}

void reset() {
  //reset settings to defaults
  //TODO turn off relays before restarting
  /*
     defaults;
    settings = defaults;
    EEPROM.begin(512);
    EEPROM.put(0, settings);
    EEPROM.end();
  */
  //reset wifi credentials
  WiFi.disconnect();
  delay(1000);
  ESP.reset();
  delay(1000);
}


#include "SonoffApplicationShell.h"

SonoffApplicationShell * appShell = nullptr;
EEPROMSettings sonoffSettings;

void setup()
{
  Serial.begin(115200);

  SonoffApplicationShell ashell{};
  appShell = &ashell;

  


  //config mqtt
  if (strlen(sonoffSettings.mqttHostname()) == 0) {
    MQTT_ENABLED = false;
  }
  if (MQTT_ENABLED) {
    mqttClient.set_server(sonoffSettings.mqttHostname(), atoi(sonoffSettings.mqttPort()));
  }

  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

  //setup button
  pinMode(SONOFF_BUTTON, INPUT);
  attachInterrupt(SONOFF_BUTTON, toggleState, CHANGE);

  //setup input
  pinMode(SONOFF_INPUT, INPUT_PULLUP);
  attachInterrupt(SONOFF_INPUT, toggleInputState, CHANGE);

  //setup relay
  //TODO multiple relays
  
  
  //relay.relayInit();
  
  MQTTOutbound mob{&mqttClient,sonoffSettings.mqttTopic()};
  mqttOutbound = &mob;

  MQTTInbound inbound{&mqttClient,sonoffSettings.mqttClientID(),sonoffSettings.mqttTopic(), &appCore};
  mqttInbound = &inbound;

   //TODO this should move to last state maybe
   //TODO multi channel support
  if (strcmp(sonoffSettings.bootState(), "on") == 0) {
    appCore.externalOn();
  } else {
    appCore.externalOff();
  }

//  //setup led
//  if (!SONOFF_LED_RELAY_STATE) {
//    digitalWrite(SONOFF_LED, LOW);
//  }

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


  //delay(200);
  //Serial.println(digitalRead(SONOFF_BUTTON));
  switch (cmd) {
    case CMD_WAIT:
      break;
    case CMD_BUTTON_CHANGE: 
    {
        int currentState = digitalRead(SONOFF_BUTTON);
        if (currentState != buttonState) {
          if (buttonState == LOW && currentState == HIGH) {
            long duration = millis() - startPress;
            if (duration < 1000) {
              Serial.println("short press - toggle relay");
              appCore.externalToggle();
            } else if (duration < 5000) {
              Serial.println("medium press - reset");
              restart();
            } else if (duration < 60000) {
              Serial.println("long press - reset settings");
              reset();
            }
          } else if (buttonState == HIGH && currentState == LOW) {
            startPress = millis();
          }
          buttonState = currentState;
        }
    }
    break;
  
  }


}




