#pragma once
#include "Log.h"

struct SerialLog : Log
{
    void print(String msg)
    {
        Serial.print(msg);
    }

    void println(String msg)
    {
        Serial.println(msg);
    }
};