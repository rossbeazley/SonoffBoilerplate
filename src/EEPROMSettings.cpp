#include "EEPROMSettings.h"

#include <Arduino.h>
#include <EEPROM.h>

EEPROMSettings::EEPROMSettings()
{
  Serial.println("constructing EEPROMSettings");
  //custom params
  EEPROM.begin(512);
  EEPROM.get(0, this->settings);
  EEPROM.end();

  Serial.println("validating EEPROMSettings");
  
  if (settings.salt != EEPROM_SALT) {
    Serial.println("Invalid settings in EEPROM, trying with defaults");
    WMSettings defaults;
    this->settings = defaults;
  }
  
  Serial.println("constructed EEPROMSettings");
}

void EEPROMSettings::save(WMSettings settings)
{
    EEPROM.begin(512);
    EEPROM.put(0, settings);
    EEPROM.end();
}

void EEPROMSettings::debugDump()
{
  
  Serial.println(settings.bootState);
  Serial.println(this->settings.mqttHostname);
  Serial.println(this->settings.mqttPort);
  Serial.println(this->settings.mqttClientID);
  Serial.println(this->settings.mqttTopic);
}

char* EEPROMSettings::mqttTopic()
{
  return this->settings.mqttTopic;
}

bool  EEPROMSettings::bootState()
{
  return (strcmp(this->settings.bootState , "on") == 0);
}

char*  EEPROMSettings::mqttHostname()
{
  return this->settings.mqttHostname;
}

char*  EEPROMSettings::mqttPort()
{
  return this->settings.mqttPort;
}

char*  EEPROMSettings::mqttClientID()
{
  return this->settings.mqttClientID;
}




