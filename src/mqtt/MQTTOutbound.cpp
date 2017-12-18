
#include "MQTTOutbound.h"
#include<stdio.h>

MQTTOutbound::MQTTOutbound(char * mqttTopic, PublishChannel& connection) :
                                              _mqttTopic{mqttTopic}
                                              ,mqttConnection(connection)
{
  
}

void MQTTOutbound::updateMQTT(int channel, const char*  stateString) {
  char topic[50];
  sprintf(topic, "%s/channel-%d/status", _mqttTopic, channel);
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