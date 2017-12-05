#pragma once


#define HOSTNAME "sonoff"
#define EEPROM_SALT 12665
typedef struct {
  char  bootState[4]      = "off";
  char  mqttServer[33]  = "192.168.10.2";
  char  mqttPort[6]       = "1883";
  char  mqttClientID[24]  = "";
  char  mqttTopic[33]     = HOSTNAME;
  char  sonoffHostname[10] = "sonoff";
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
    bool  bootState();
    char* mqttServer();
    char*  mqttPort();
    char* mqttClientID();
    char* sonoffHostname();
  private:
      WMSettings settings;
};


