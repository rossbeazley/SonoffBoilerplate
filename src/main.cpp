#include <Arduino.h>
#include "SonoffApplicationShell.h"

SonoffApplicationShell * appShell = nullptr;

void setup()
{
  Serial.begin(115200);
  Serial.println("start setup");
  appShell = new SonoffApplicationShell{};
  Serial.println("done setup");
}

void loop()
{
  appShell->loop();
}

