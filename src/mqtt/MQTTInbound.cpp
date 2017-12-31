#include "MQTTInbound.h"
#include <Arduino.h>


MQTTInbound::MQTTInbound(const char * topic, LightSwitch * appcore, const char * hostname) :
  mqttTopic{topic}
  , appCore{appcore}
  , hostname{hostname}
{

}

void MQTTInbound::message(String topic, String payload)
{

  if (topic == this->mqttTopic) {
    Serial.println("exact match, is a topic broadcast");
    this->processCommand(payload);
  }
  else if (topic.startsWith(this->mqttTopic))
  {
    Serial.println("for this device");

    // strip the topic from the start of the message, suggests topic shouldnt be known in this method, not if we are using it for a broadcast tho
    topic = topic.substring(strlen(this->mqttTopic) + 1);

    //TODO need to put channel ID in config
      int found = topic.indexOf('/');
      String channelString = topic.substring(0,found);
    
    Serial.println(channelString);
    if (!channelString.equals(this->hostname)) {
      Serial.print("dosnt match hostname: ");
      Serial.println(this->hostname);
      return;
    }
    this->processCommand(payload);

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


// should really move this to its own class
void MQTTInbound::processCommand(String payload)
{
  if (payload == "on") {
      this->appCore->externalOn();
    }
    else if (payload == "off") {
      this->appCore->externalOff();
    }
    else if (payload == "toggle") {
      this->appCore->externalToggle();
    }
}
