
#include "MQTTOutbound.h"

//think this could be implementing a general "publisher" of the MQTT implementation
//it needs a mediator to observer the app core and publish when required
//this mediator can probably either be an pub/sub or allow the sub to poke it

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

