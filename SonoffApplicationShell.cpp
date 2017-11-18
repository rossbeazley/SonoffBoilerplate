#include "SonoffApplicationShell.h"
#include <Arduino.h>


SonoffApplicationShell::SonoffApplicationShell()
{
  Serial.println("Constructing app shell");

  // New up the OTA stuff

  //Add a debug observer
  this->myCore.addObserver(&sd);
  
  Serial.println("Constructed app shell");
}

void SonoffApplicationShell::loop()
{
  //Serial.println("APP loop");
  mttConnection.loop();
  internalButton.loop();
  debouncedButton.loop(millis());
}

void SonoffApplicationShell::debugDump()
{
  sonoffSettings.debugDump();
}

