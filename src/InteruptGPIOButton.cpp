#include "InteruptGPIOButton.h"
#include "Arduino.h"
#include <functional>

std::function<void(void)> InteruptGPIOButtonISRLambda;

void InteruptGPIOButtonISR()
{
  InteruptGPIOButtonISRLambda();
}

InteruptGPIOButton::InteruptGPIOButton(AbstractButton & ab) : button(ab)
{
  InteruptGPIOButtonISRLambda = [this]()->void{
    if (digitalRead(14))
    {
      this->button.high(millis());
    }
    else
    {
      this->button.low(millis());
    }


  };
  pinMode(14, INPUT_PULLUP);
  attachInterrupt(14, InteruptGPIOButtonISR, CHANGE);
}
