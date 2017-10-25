#include "SonoffInternalButton.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>


#define   SONOFF_BUTTON             0

const int CMD_WAIT = 0;
const int CMD_BUTTON_CHANGE = 1;

int cmd = CMD_WAIT;
//int relayState = HIGH;


//inverted button state
int buttonState = HIGH;
int inputStateCount = 5;

static long startPress = 0;

void toggleState() {
  cmd = CMD_BUTTON_CHANGE;
}

void restart() {
  //TODO turn off relays before restarting
  ESP.reset();
  delay(1000);
}

void reset() {
  //reset wifi credentials
  WiFi.disconnect();
  delay(1000);
  ESP.reset();
  delay(1000);
}

SonoffInternalButton::SonoffInternalButton(SonoffApplicationCore * core) : core{core}
{

//setup button
  pinMode(SONOFF_BUTTON, INPUT);
  attachInterrupt(SONOFF_BUTTON, toggleState, CHANGE);

  
}

void SonoffInternalButton::loop()
{
  switch (cmd) {
    case CMD_WAIT:
      break;
    case CMD_BUTTON_CHANGE: 
    {
        int currentState = digitalRead(SONOFF_BUTTON);
        if (currentState != buttonState) {
          if (buttonState == LOW && currentState == HIGH) {
            long duration = millis() - startPress;
            if (duration < 1000) {
              Serial.println("short press - toggle relay");
              this->core->externalToggle();
            } else if (duration < 5000) {
              Serial.println("medium press - reset");
              restart();
            } else if (duration < 60000) {
              Serial.println("long press - reset settings");
              reset();
            }
          } else if (buttonState == HIGH && currentState == LOW) {
            startPress = millis();
          }
          buttonState = currentState;
        }
    }
    break;
  
  }
}

