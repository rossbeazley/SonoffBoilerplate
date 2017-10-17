#include "Arduino.h"
#include "SonoffRelay.h"

//TODO move member init to out of constructor block
SonoffRelay::SonoffRelay(int gpiopin) {
  _gpiopin = gpiopin;
  _currentState=HIGH;
  this->pokeRelay(_currentState); 
}

void SonoffRelay::relayInit(int channel) {
  pinMode(SONOFF_RELAY_PINS[channel], OUTPUT);
}

void SonoffRelay::announce(int state) {
  for (int i = 0; i < views.size(); i++) {
    views[i]->state(state);
  }
}

void SonoffRelay::attachObserver(RelayObserver *observer) {
    views.push_back(observer);
}

void SonoffRelay::pokeRelay(int state, int channel) {
  _currentState = state;
  digitalWrite(SONOFF_RELAY_PINS[channel], _currentState);
  // announce new state
  SonoffRelay::announce(_currentState);
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
  return _currentState;
}
