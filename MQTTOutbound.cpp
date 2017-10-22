
#include "MQTTOutbound.h"

MQTTOutbound::MQTTOutbound(PubSubClient & psC, char * mqttTopic) : _mqttClient(psC), _mqttTopic{mqttTopic}
{

}

void MQTTOutbound::updateMQTT(int channel, int state) {
  
  char topic[50];
  sprintf(topic, "%s/channel-%d/status", _mqttTopic, channel);
  String stateString = state == 0 ? "off" : "on";
  _mqttClient.publish(topic, stateString);
}
