#include "MQTTInbound.h"
#include <Arduino.h>

int         lastMQTTConnectionAttempt = 0;

//settings.mqttClientID
//mqttCallback
//settings.mqttTopic
/*
  char  mqttClientID[24]  = "spk-socket";
  char  mqttTopic[33]     = HOSTNAME;
  */
  
//http://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}


MQTTInbound::MQTTInbound(PubSubClient * psC,char * clientID, char * topic, SonoffApplicationCore * appcore) : mqttClient(psC), mqttClientID(clientID), mqttTopic{topic}, appCore{appcore}
{
  
}

  
void MQTTInbound::connectToMQTT() 
{
                                       //more than 3 minutes has passed
  if(lastMQTTConnectionAttempt == 0 || millis() > lastMQTTConnectionAttempt + 3 * 60 * 1000) 
  {
        lastMQTTConnectionAttempt = millis();
        Serial.println(millis());
        Serial.println("Trying to connect to mqtt");
        if (this->mqttClient->connect(this->mqttClientID)) {
          Serial.println("connected");
          this->mqttClient->set_callback( [this](const MQTT::Publish& pub) { this->mqttCallback(pub); });
          //this->mqttClient->set_callback(this->mqttCallback);
          Serial.println("Callback set");
          char topic[50];
          //sprintf(topic, "%s/+/+", settings.mqttTopic);
          //mqttClient.subscribe(topic);
          sprintf(topic, "%s/+", this->mqttTopic);
          Serial.print("subscribing to ");
          Serial.println(topic);
          this->mqttClient->subscribe(topic);

          // This broadcasts the current state of the system, can migrate this to an observer gets notified of state pattern
          //updateMQTT(0);
        } else {
          Serial.println("failed");
        }
   }
}

void MQTTInbound::mqttCallback(const MQTT::Publish& pub) {
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
    Serial.println(pub.payload_string());
    Serial.println("pub not has_stream");
    String topic = pub.topic();
    String payload = pub.payload_string();


    
    Serial.print("topic: ");
    Serial.println(topic);

    Serial.print("payload: ");
    Serial.println(payload);

    
    if (topic == this->mqttTopic) {
      Serial.println("exact match");
      return;
    }
    
    if (topic.startsWith(this->mqttTopic)) 
    {
      Serial.println("for this device");
      topic = topic.substring(strlen(this->mqttTopic) + 1);
      String channelString = getValue(topic, '/', 0);
      if(!channelString.startsWith("channel-")) {
        Serial.println("no channel");
        return;
      }
      channelString.replace("channel-", "");
      int channel = channelString.toInt();
      Serial.println(channel);
      if (payload == "on") {
        this->appCore->externalOn();
      }
      if (payload == "off") {
        this->appCore->externalOff();
      }
      if (payload == "toggle") {
        this->appCore->externalToggle();
      }

      // TODO remodel this
//      if(payload == "") {
//        updateMQTT(channel);
//      }
      
    }
    else
    {
      Serial.print("Topic didnt start with: ");
      Serial.println(this->mqttTopic);
    }
  }
}

