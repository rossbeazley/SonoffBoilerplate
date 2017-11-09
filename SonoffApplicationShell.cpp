#include "SonoffApplicationShell.h"
#include <Arduino.h>


SonoffApplicationShell::SonoffApplicationShell()
{
  Serial.println("Constructing app shell");
//  SonoffWifi wifi{sonoffSettings};
//  GPIORelay relay(12);                                       //todo introduce boolean return type
//  SonoffApplicationCore myCore(&relay, (strcmp(sonoffSettings.bootState(), "on") == 0) );
//  SonoffInternalButton internalButton{&myCore};  
  Serial.print("Core mem location ");
  Serial.println((long int)&myCore);
  // New External button
  // New outbound mqtt
  // New inbound mqtt
  // New internal button
  
  // New OTA
  
  Serial.println("Constructed app shell");
}

void SonoffApplicationShell::loop()
{
  // loop MQTT
  
  //Serial.println("APP loop");
  
  internalButton.loop();

  //Serial.println("APP loop done");
  
  
}

void SonoffApplicationShell::debugDump()
{
  sonoffSettings.debugDump();
}

