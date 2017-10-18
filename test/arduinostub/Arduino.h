#pragma once

#include <map>

#define HIGH (1)

#define LOW (0)

#define OUTPUT (1)
#define INPUT (-1)

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
int digitalRead(int pin);

class MockStream {
public:
	void println(const char *msg);
	void println(int value);
private:
};

extern MockStream Serial;

extern std::map<int, int> spyPinState;
extern std::map<int, int> spyPinMode;