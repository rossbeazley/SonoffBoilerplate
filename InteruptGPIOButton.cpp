#include "InteruptGPIOButton.h"
#include "Arduino.h"
#include <functional>

std::function<void(void)> InteruptGPIOButtonISRLambda;

void edge()
{
	InteruptGPIOButtonISRLambda();
}

InteruptGPIOButton::InteruptGPIOButton(AbstractButton & ab) : button{ab}
{
	InteruptGPIOButtonISRLambda = [this]()->void{ this->button.on(); };
	pinMode(14,INPUT);
	attachInterrupt(14,edge,CHANGE);
}
