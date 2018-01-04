#include "MQTTPubSubClientConnection.h"


int         lastMQTTConnectionAttempt = 0;

//settings.mqttClientID
//mqttCallback
//settings.mqttTopic
/*
  char  mqttClientID[24]  = "spk-socket";
  char  mqttTopic[33]     = HOSTNAME;
*/



MQTTConnection::MQTTConnection(char* mqttHostname, int mqttPort, char * clientID, char * topic, MQTTInbound * inbound) :
    mqttHostname{mqttHostname}
  , mqttPort{mqttPort}
  , mqttClientID(clientID)
  , mqttTopic{topic}
  , inbound{inbound}
{
    this->mqttClient.set_server(this->mqttHostname, this->mqttPort);
}

void MQTTConnection::loop()
{
  if (!this->mqttClient.connected()) {
     this->connectToMQTT();
  } else {
     this->mqttClient.loop();
  }
}

void MQTTConnection::connectToMQTT()
{
  //more than 3 minutes has passed
  if (lastMQTTConnectionAttempt == 0 || millis() > lastMQTTConnectionAttempt + 3 * 60 * 1000)
  {
    lastMQTTConnectionAttempt = millis();
    Serial.println(millis());
    Serial.println("Trying to connect to mqtt");
    if (this->mqttClient.connect(this->mqttClientID)) {
      Serial.println("connected");
      this->mqttClient.set_callback( [this](const MQTT::Publish & pub) {
        this->mqttCallback(pub);
      });
      //this->mqttClient->set_callback(this->mqttCallback);
      Serial.println("Callback set");
      char topic[50];
      //sprintf(topic, "%s/+/+", settings.mqttTopic);
      //mqttClient.subscribe(topic);
      sprintf(topic, "%s/+", this->mqttTopic);
      Serial.print("subscribing to ");
      Serial.println(topic);
      this->mqttClient.subscribe(topic);

      // This broadcasts the current state of the system, can migrate this to an observer gets notified of state pattern
      //updateMQTT(0);
    } else {
      Serial.println("failed");
    }
  }
}

void MQTTConnection::mqttCallback(const MQTT::Publish& pub) {
  Serial.print(pub.topic());
  Serial.print(" => ");
  if (pub.has_stream())
  {
    Serial.print(".. ");
    int BUFFER_SIZE = 100;
    uint8_t buf[BUFFER_SIZE];
    int read;
    while (read = pub.payload_stream()->read(buf, BUFFER_SIZE)) {
      Serial.write(buf, read);
    }
    pub.payload_stream()->stop();
    Serial.println("had buffer");
  }
  else
  {
    Serial.println("pub not has_stream");
    String topic = pub.topic();
    String payload = pub.payload_string();

    Serial.print("topic: ");
    Serial.println(topic);

    Serial.print("payload: ");
    Serial.println(payload);

    this->inbound->message(topic, payload);

  }
}

void MQTTConnection::publish(String topic, String payload)
{
  Serial.print("About to publsh ");
  Serial.print(topic);
  Serial.print(" ");
  Serial.println(payload);
  if ( this->mqttClient.connected() ) {
    this->mqttClient.publish(topic, payload);
  } else {
    Serial.println("but not connected");
  }

}






