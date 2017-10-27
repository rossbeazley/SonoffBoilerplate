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
  
  Serial.println("SonoffInternalButton::toggleState");
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

SonoffInternalButton::~SonoffInternalButton()
{
  Serial.println("Deconstruct SonoffInternalButton");
}

void SonoffInternalButton::loop()
{
  //Serial.println("SonoffInternalButton::loop");
  switch (cmd) {
    case CMD_WAIT:
      //Serial.println("WAIT");
      break;
    case CMD_BUTTON_CHANGE: 
    {
      //Serial.println("CMD_BUTTON_CHANGE");
        int currentState = digitalRead(SONOFF_BUTTON);
          Serial.print("current state (HIGH IS ");
          Serial.print(HIGH);
          Serial.print(") ");
          Serial.println(currentState);
        
          Serial.print("button state ");
          Serial.println(buttonState);
        
        if (currentState != buttonState) {
          if (buttonState == LOW && currentState == HIGH) {
            Serial.print("if buttonState == LOW && currentState == HIGH");
            long duration = millis() - startPress;
            Serial.print("duration ");
            Serial.println(duration);
            
            if (duration < 2000) {
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.println("short press - toggle relay");
              Serial.print("Core mem location ");
              Serial.println((long int)&core);
  
              this->core->externalToggle();
            } else if (duration < 5000) {
              Serial.println("medium press - reset");
              restart();
            } else if (duration < 60000) {
              Serial.println("long press - reset settings");
              reset();
            }
          } else if (buttonState == HIGH && currentState == LOW) {
            Serial.println("else if (buttonState == HIGH && currentState == LOW)");
            startPress = millis();
            Serial.print("Start of press at ");
            Serial.println(startPress);
          } else {
            Serial.println("else none");
          }
          buttonState = currentState;
          Serial.print("button state ");
          Serial.println(buttonState);
        }
    }
    break;
  
  }

  //Serial.println("SonoffInternalButton::loop");
  
}


