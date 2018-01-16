#include "InteruptGPIOButton.h"
#include "Arduino.h"
#include <functional>

std::function<void(uint8_t)> InteruptGPIOButtonISRLambda14;

void InteruptGPIOButtonISR14()
{
  InteruptGPIOButtonISRLambda14(14);
}

InteruptGPIOButton::InteruptGPIOButton(AbstractButton & ab) : button(ab)
{
  InteruptGPIOButtonISRLambda14 = [this](uint8_t pinNo)->void{
    if (digitalRead(pinNo))
    {
      this->button.high(millis());
    }
    else
    {
      this->button.low(millis());
    }


  };
  pinMode(14, INPUT_PULLUP);
  attachInterrupt(14, InteruptGPIOButtonISR14, CHANGE);
}
