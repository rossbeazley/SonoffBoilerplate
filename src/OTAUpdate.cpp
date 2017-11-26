#include "OTAUpdate.h"

#include <ArduinoOTA.h>

OTAUpdate::OTAUpdate(char* hostname, char* clientId) : hostname(hostname), clientId(clientId)
{
  ArduinoOTA.onStart([]() {
    Serial.println("Start OTA");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });


  char otaHostname[50];
  sprintf(otaHostname, "%s-%s", hostname, clientId);

  ArduinoOTA.setHostname(otaHostname);

  ArduinoOTA.begin();
}

void OTAUpdate::loop()
{
  ArduinoOTA.handle();
}

