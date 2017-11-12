#pragma once

class AbstractButton
{
	public:
		virtual void on() = 0;
		virtual void off() = 0;
};

class InteruptGPIOButton
{
	public:
		InteruptGPIOButton(AbstractButton&);
	private:
		AbstractButton & button;
};
