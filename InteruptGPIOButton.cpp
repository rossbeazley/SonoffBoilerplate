#include "InteruptGPIOButton.h"
#include "Arduino.h"
#include <functional>

std::function<void(void)> InteruptGPIOButtonISRLambda;

void InteruptGPIOButtonISR()
{
  InteruptGPIOButtonISRLambda();
}

InteruptGPIOButton::InteruptGPIOButton(AbstractButton & ab) : button{ab}
{
  InteruptGPIOButtonISRLambda = [this]()->void{
    if (digitalRead(14))
    {
      this->button.high();
    }
    else
    {
      this->button.low();
    }


  };
  pinMode(14, INPUT);
  attachInterrupt(14, InteruptGPIOButtonISR, CHANGE);
}
