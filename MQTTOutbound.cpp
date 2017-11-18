
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

MQTTOutbound::MQTTOutbound(char * mqttTopic) :
                                              _mqttTopic{mqttTopic}
                                              //,_mqttClient{wificlient}
{
  //PubSubClient mqttClient(this->wificlient);
  //_mqttClient = &mqttClient;
}

void MQTTOutbound::updateMQTT(int channel, int state) {

// really we should connect before publishing, looks like we need an mediator around mqttClient
//    if (!mqttClient.connected()) {
//      _mqttClient->connectToMQTT();
//    }

  char topic[50];
  sprintf(topic, "%s/channel-%d/status", _mqttTopic, channel);
  String stateString = state == 0 ? "off" : "on";
  _mqttClient.publish(topic, stateString);
}

