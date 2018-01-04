#pragma once

#include <Arduino.h>

class PublishChannel
{
  public:
    virtual void publish(String topic, String payload) = 0;

};
