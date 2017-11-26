#pragma once

class OTAUpdate
{
  public:
    OTAUpdate(char*,char*);
    void loop();
  private:
    char* hostname;
    char* clientId;
};

