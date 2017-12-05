#include "SonoffWifi.h"
#include <WiFiManager.h> 
#include <Arduino.h>


#define   SONOFF_LED                13

//for LED status
#include <Ticker.h>
Ticker ticker;


void tick()
{
  //toggle state
  int state = digitalRead(SONOFF_LED);  // get the current state of GPIO1 pin
  digitalWrite(SONOFF_LED, !state);     // set pin to the opposite state
}


//gets called when WiFiManager enters configuration mode
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
  //entered config mode, make led toggle faster
  ticker.attach(0.2, tick);
}


//flag for saving data
bool shouldSaveConfig = false;

//callback notifying us of the need to save config
void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

SonoffWifi::SonoffWifi(EEPROMSettings & sonoffSettings)
{

Serial.println("Constructing wifi");
  
    const char *hostname = sonoffSettings.mqttTopic();
  //set led pin as output

  pinMode(SONOFF_LED, OUTPUT);
  // start ticker with 0.5 because we start in AP mode and try to connect

ticker.attach(0.6, tick);


  WiFiManager wifiManager;
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wifiManager.setAPCallback(configModeCallback);

  //timeout - this will quit WiFiManager if it's not configured in 3 minutes, causing a restart
  wifiManager.setConfigPortalTimeout(180);


  WiFiManagerParameter custom_boot_state("boot-state", "on/off on boot", sonoffSettings.bootState()?"on":"off", 33);
  wifiManager.addParameter(&custom_boot_state);

  sonoffSettings.debugDump();
  
  WiFiManagerParameter custom_mqtt_text("<br/>MQTT config. <br/> No url to disable.<br/>");
  wifiManager.addParameter(&custom_mqtt_text);

  WiFiManagerParameter custom_mqtt_hostname("mqtt-hostname", "Hostname", sonoffSettings.mqttServer(), 33);
  wifiManager.addParameter(&custom_mqtt_hostname);

  WiFiManagerParameter custom_mqtt_port("mqtt-port", "port", sonoffSettings.mqttPort(), 6);
  wifiManager.addParameter(&custom_mqtt_port);

  WiFiManagerParameter custom_mqtt_client_id("mqtt-client-id", "Client ID", sonoffSettings.mqttClientID(), 24);
  wifiManager.addParameter(&custom_mqtt_client_id);

  WiFiManagerParameter custom_mqtt_topic("mqtt-topic", "Topic", sonoffSettings.mqttTopic(), 33);
  wifiManager.addParameter(&custom_mqtt_topic);

  WiFiManagerParameter custom_sonoff_hostname("sonoff-hostname", "SonoffHostname", sonoffSettings.sonoffHostname(), 10);
  wifiManager.addParameter(&custom_sonoff_hostname);

  //set config save notify callback
  wifiManager.setSaveConfigCallback(saveConfigCallback);


Serial.println("Wifi about to connect");

  if (!wifiManager.autoConnect(hostname)) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  }

  //Serial.println(custom_blynk_token.getValue());
  //save the custom parameters to FS
  if (shouldSaveConfig) {
    Serial.println("Saving config");
    WMSettings newSettings;
    strcpy(newSettings.bootState, custom_boot_state.getValue());

    strcpy(newSettings.mqttServer, custom_mqtt_hostname.getValue());
    strcpy(newSettings.mqttPort, custom_mqtt_port.getValue());
    strcpy(newSettings.mqttClientID, custom_mqtt_client_id.getValue());
    strcpy(newSettings.mqttTopic, custom_mqtt_topic.getValue());
    strcpy(newSettings.sonoffHostname, custom_sonoff_hostname.getValue());
    

    Serial.println(sonoffSettings.bootState());

    sonoffSettings.save(newSettings);
    
  }

  ticker.detach();


Serial.println("Constructed wifi");
}


