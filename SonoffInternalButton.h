#pragma once

#include "SonoffApplicationCore.h"

class SonoffInternalButton
{
  public:
    SonoffInternalButton(SonoffApplicationCore*);
    ~SonoffInternalButton();
    void loop();
  private:
    SonoffApplicationCore * core;
};


