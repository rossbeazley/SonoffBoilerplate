
#include "MQTTOutbound.h"
#include<stdio.h>

MQTTOutbound::MQTTOutbound(char * mqttTopic, char * hostname, PublishChannel& connection) :
                                              _mqttTopic{mqttTopic}
                                              ,_hostname{hostname}
                                              ,mqttConnection(connection)
{
  
}

void MQTTOutbound::updateMQTT(int channel, const char*  stateString) {
  char topic[50];
  sprintf(topic, "%s/%s/status", _mqttTopic, _hostname);  
  this->mqttConnection.publish(topic, stateString);
}

void MQTTOutbound::ON()
{
  this->updateMQTT(0,"on");
}

void MQTTOutbound::OFF()
{
  this->updateMQTT(0,"off");
}