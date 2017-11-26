#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "SonoffApplicationCore.h"
#include "MQTTInbound.h"

class MQTTConnection
{
  public:
    MQTTConnection(char* mqttHostname, int mqttPort, char * clientID, char * topic, MQTTInbound * inbound);
    void connectToMQTT();
    void loop();
    void publish(String topic, String payload);
    
  private:
    char* mqttHostname;
    int  mqttPort;
    char * mqttClientID;
    char * mqttTopic;
    WiFiClient wificlient;
    PubSubClient mqttClient{wificlient};
    void mqttCallback(const MQTT::Publish& );
    MQTTInbound * inbound;
};

