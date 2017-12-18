#pragma once

class PublishChannel
{
  public:
    virtual void publish(const char* topic, const char* payload) = 0;

};
