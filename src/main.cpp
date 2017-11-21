#ifndef UNIT_TEST
#include <Arduino.h>
#include <SerialLogger.h>

Logger * logger;

void setup() {
    logger = new SerialLogger();
}

void loop() {
    // put your main code here, to run repeatedly:
}
#endif