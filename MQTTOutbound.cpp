
#include "MQTTOutbound.h"

/*
 * 
 * 
 * Take in instance of the MQTTConnection and publish to that
 * 
 * 
 * 
 * 
 */

MQTTOutbound::MQTTOutbound(char * mqttTopic, MQTTConnection& connection) :
                                              _mqttTopic{mqttTopic}
                                              ,mqttConnection(connection)
{
  
}

void MQTTOutbound::updateMQTT(int channel, int state) {
  char topic[50];
  sprintf(topic, "%s/channel-%d/status", _mqttTopic, channel);
  String stateString = state == 0 ? "off" : "on";
  this->mqttConnection.publish(topic, stateString);
}

