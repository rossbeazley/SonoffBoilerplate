#pragma once
#include <Arduino.h>

struct Log {
    virtual void print(String msg) = 0;
    virtual void println(String msg) = 0;
};