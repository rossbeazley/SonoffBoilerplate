#pragma once

#include <map>
#include "SString.h"

#define HIGH (1)

#define LOW (0)

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define CHANGE 1
#define FALLING 2
#define RISING 3

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
int digitalRead(int pin);

unsigned long millis(void);

void attachInterrupt(uint8_t pin, void (*fp)(void), int mode);
void detachInterrupt(uint8_t pin);

class MockStream {
public:
	void print(const char *msg);
	void println(const char *msg);
	void println(int value);
	void println(String & msg);
private:
};

extern MockStream Serial;

extern std::map<int, int> spyPinState;
extern std::map<int, int> spyPinMode;

extern std::map<int, void (*)(void)> spyISRs;

extern unsigned long mockTimeMillis;

