#pragma once

class AbstractButton
{
	public:
		virtual void high() = 0;
		virtual void low() = 0;
};

class InteruptGPIOButton
{
	public:
		InteruptGPIOButton(AbstractButton&);
	private:
		AbstractButton & button;
};
