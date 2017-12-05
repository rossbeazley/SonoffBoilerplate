#include "SonoffInternalButton.h"
#include <ESP8266WiFi.h>


#define   SONOFF_BUTTON             0



void SonoffInternalButton::restart() {
  //TODO turn off relays before restarting
  ESP.reset();
  delay(1000);
}

void SonoffInternalButton::reset() {
  //reset wifi credentials
  WiFi.disconnect();
  delay(1000);
  ESP.reset();
  delay(1000);
}

// TODO wrap this up in an ISR manager
SonoffInternalButton* that = nullptr;
void isr()
{
  that->toggleState();
}

void SonoffInternalButton::toggleState() {  
  Serial.println("SonoffInternalButton::toggleState");
  this->cmd = CMD_BUTTON_CHANGE;
}


SonoffInternalButton::SonoffInternalButton(RelayLightSwitch * core) : core{core}
{

//setup button
  pinMode(SONOFF_BUTTON, INPUT);

  that=this;
  attachInterrupt(SONOFF_BUTTON, isr, CHANGE);  
}

void SonoffInternalButton::loop()
{
  //Serial.println("SonoffInternalButton::loop");
  switch (this->cmd) {
    case CMD_WAIT:
      //Serial.println("WAIT");
      break;
    case CMD_BUTTON_CHANGE: 
    {
      //Serial.println("CMD_BUTTON_CHANGE");
        int currentState = digitalRead(SONOFF_BUTTON);
//          Serial.print("current state (HIGH IS ");
//          Serial.print(HIGH);
//          Serial.print(") ");
//          Serial.println(currentState);
//        
//          Serial.print("button state ");
//          Serial.println(this->buttonState);
//        
        if (currentState != this->buttonState) {
          if (buttonState == LOW && currentState == HIGH) {
            Serial.print("if buttonState == LOW && currentState == HIGH");
            long duration = millis() - startPress;
            Serial.print("duration ");
            Serial.println(duration);
            
            if (duration < 2000) {
              Serial.println("short press - toggle relay");
              Serial.print("Core mem location ");
              Serial.println((long int)&core);
  
              this->core->externalToggle();
            } else if (duration < 5000) {
              Serial.println("medium press - reset");
              this->restart();
            } else if (duration < 60000) {
              Serial.println("long press - reset settings");
              this->reset();
            }
          } else if (buttonState == HIGH && currentState == LOW) {
            Serial.println("else if (buttonState == HIGH && currentState == LOW)");
            startPress = millis();
            Serial.print("Start of press at ");
            Serial.println(startPress);
          } else {
            Serial.println("else none");
          }
          this->buttonState = currentState;
          //Serial.print("button state ");
          //Serial.println(this->buttonState);
        }
    }
    break;
  
  }

  //Serial.println("SonoffInternalButton::loop");
  
}


