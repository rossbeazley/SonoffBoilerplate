#pragma once

#include "SonoffApplicationCore.h"

class SonoffInternalButton
{
  public:
    SonoffInternalButton(SonoffApplicationCore *);
    void loop();
  private:
    SonoffApplicationCore * core;
};

