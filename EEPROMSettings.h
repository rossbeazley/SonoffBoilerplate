#pragma once


#define HOSTNAME "dev"
#define EEPROM_SALT 12661
typedef struct {
  char  bootState[4]      = "on";
  char  mqttHostname[33]  = "192.168.10.2";
  char  mqttPort[6]       = "1883";
  char  mqttClientID[24]  = "";
  char  mqttTopic[33]     = HOSTNAME;
  int   salt              = EEPROM_SALT;
} WMSettings;


class EEPROMSettings
{
  public:
    EEPROMSettings();
    void save(WMSettings);
    WMSettings load();
    void debugDump();
    
    char* mqttTopic();
    char*  bootState();
    char* mqttHostname();
    char*  mqttPort();
    char* mqttClientID();
  private:
      WMSettings * settings;
};

