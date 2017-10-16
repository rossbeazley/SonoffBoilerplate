#include <ArduinoOTA.h>

#import "SonoffRelay.h"

SonoffRelay::SonoffRelay(int gpiopin) {
  _gpiopin = gpiopin;
}

void SonoffRelay::relayInit(int channel) {
  pinMode(SONOFF_RELAY_PINS[channel], OUTPUT);
}

void SonoffRelay::pokeRelay(int state, int channel) {
  digitalWrite(SONOFF_RELAY_PINS[channel], state);
  // announce new state
}

void SonoffRelay::turnOn(int channel) {
  int relayState = HIGH;
  pokeRelay(relayState, channel);
}

void SonoffRelay::turnOff(int channel) {
  int relayState = LOW;
  pokeRelay(relayState, channel);
}


void SonoffRelay::toggle(int channel) {
  Serial.println("toggle state");
  Serial.println(digitalRead(SONOFF_RELAY_PINS[channel]));
  int relayState = digitalRead(SONOFF_RELAY_PINS[channel]) == HIGH ? LOW : HIGH;
  pokeRelay(relayState, channel);
}


int SonoffRelay::currentState(int channel) {
  return digitalRead(SONOFF_RELAY_PINS[channel]);
}
