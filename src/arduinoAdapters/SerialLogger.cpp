#include "SerialLogger.h"


SerialLogger::SerialLogger()
{
    Serial.begin(115200);
}

void SerialLogger::d(char* msg)
{
    Serial.println(msg);
}