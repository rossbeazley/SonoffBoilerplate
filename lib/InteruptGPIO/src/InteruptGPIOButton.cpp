#include "InteruptGPIOButton.h"
#include "Arduino.h"
#include <functional>
#include <map>

std::function<void(uint8_t)> InteruptGPIOButtonISRLambda14;

void InteruptGPIOButtonISR14()
{
  InteruptGPIOButtonISRLambda14(14);
}




typedef void (*ISRFunctionPointer)(void);
std::map<uint8_t, ISRFunctionPointer> isrFunctionsByPinNumber = { {14,InteruptGPIOButtonISR14} };



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

  void (*isrfp)(void) = InteruptGPIOButtonISR14;

  isrfp = isrFunctionsByPinNumber.find(14)->second;

  pinMode(14, INPUT_PULLUP);
  attachInterrupt(14, isrfp, CHANGE);
}
