#pragma once

class AbstractButton
{
	public:
		virtual void high(unsigned long uptime) = 0;
		virtual void low(unsigned long uptime) = 0;
    virtual void loop(unsigned long uptime) = 0;
};

class InteruptGPIOButton
{
	public:
		InteruptGPIOButton(AbstractButton&);
	private:
		AbstractButton & button;
};
