
#include <Arduino.h>
#include <ESP8266WiFi.h>


static bool MQTT_ENABLED              = true;

#include "SonoffApplicationShell.h"
SonoffApplicationShell * appShell = nullptr;

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("start setup");

  delay(1000);

  

//  //config mqtt
//  if (strlen(sonoffSettings.mqttHostname()) == 0) {
//    MQTT_ENABLED = false;
//  }
//  if (MQTT_ENABLED) {
//    mqttClient.set_server(sonoffSettings.mqttHostname(), atoi(sonoffSettings.mqttPort()));
//  }
//
//// setup external button
////  #define   SONOFF_INPUT              14
////  pinMode(SONOFF_INPUT, INPUT_PULLUP);
////  attachInterrupt(SONOFF_INPUT, toggleInputState, CHANGE);
//
  
  appShell = new SonoffApplicationShell{};

  Serial.println("done setup");

  //appShell.debugDump();
}


void loop()
{
  
  //Serial.println("loop");
  appShell->loop();
  
  //mqtt loop
//  if (MQTT_ENABLED) {
//    if (!mqttClient.connected()) {
//      mqttInbound->connectToMQTT();
//    } else {
//      mqttClient.loop();
//    }
//  }
//  
//  internalButton->loop();

}





