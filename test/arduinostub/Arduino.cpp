#include "Arduino.h"
#include <iostream>


unsigned long millis(void)
{
	return mockTimeMillis;
}


void attachInterrupt(uint8_t pin, void (*fp)(void), int mode)
{
	spyISRs[pin]=fp;
}

void detachInterrupt(uint8_t pin)
{
	spyISRs[pin]=NULL;
}

void pinMode(int pin, int mode) {
	std::cout << "pinMode(" << pin << ", " << mode << ")" << std::endl;
	spyPinMode[pin] = mode;
}

void digitalWrite(int pin, int value) {
	std::cout << "digitalWrite(" << pin << ", " << value << ")" << std::endl;
	spyPinState[pin] = value;
}

int digitalRead(int pin) {
	std::cout << "digitalRead(" << pin << ")" << std::endl;
	return spyPinState[pin];
}

void MockStream::print(const char *msg) {
	std::cout << "Serial.println(" << msg << ")";
}

void MockStream::println(const char *msg) {
	std::cout << "Serial.println(" << msg << ")" << std::endl;
}

void MockStream::println(int value) {
	std::cout << "Serial.println(" << value << ")" << std::endl;
}

void MockStream::println(String & msg){
	std::cout << "Serial.println(" << msg.pString << ")" << std::endl;
}

MockStream Serial;
std::map<int, int> spyPinState;
std::map<int, int> spyPinMode;

std::map<int, void (*)(void)> spyISRs;

unsigned long mockTimeMillis=0;

