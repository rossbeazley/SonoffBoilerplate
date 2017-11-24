#pragma once

class OTAUpdate
{
  public:
    OTAUpdate(char*);
    void loop();
  private:
    char* hostname;
};

