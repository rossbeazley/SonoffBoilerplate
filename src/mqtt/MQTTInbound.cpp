#include "MQTTInbound.h"
#include <Arduino.h>


MQTTInbound::MQTTInbound(const char * topic, LightSwitch * appcore, const char * hostname) :
  mqttTopic{topic}
  , appCore{appcore}
  , hostname{hostname}
{

}

//http://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
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
    String channelString = getValue(topic, '/', 0);
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
