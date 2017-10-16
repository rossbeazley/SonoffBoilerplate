#include <ArduinoOTA.h>

#import "SonoffRelay.h"

const int SONOFF_RELAY_PINS[4] =    {12, 12, 12, 12};

void relayInit(int channel) {
pinMode(SONOFF_RELAY_PINS[channel], OUTPUT);
}

void pokeRelay(int state, int channel) {
  digitalWrite(SONOFF_RELAY_PINS[channel], state);
  // announce new state
}

void turnOn(int channel) {
  int relayState = HIGH;
  pokeRelay(relayState, channel);
}

void turnOff(int channel) {
  int relayState = LOW;
  pokeRelay(relayState, channel);
}


void toggle(int channel) {
  Serial.println("toggle state");
  Serial.println(digitalRead(SONOFF_RELAY_PINS[channel]));
  int relayState = digitalRead(SONOFF_RELAY_PINS[channel]) == HIGH ? LOW : HIGH;
  pokeRelay(relayState, channel);
}


int currentState(int channel) {
  return digitalRead(SONOFF_RELAY_PINS[channel]);
}
