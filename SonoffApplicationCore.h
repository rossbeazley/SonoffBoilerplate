#pragma once

class Relay
{
  public:
    virtual void open() = 0;
    virtual void close() = 0;
};

class SonoffApplicationCore
{
  public:
    SonoffApplicationCore(Relay*); //think i can avoid pointers?
    void on();
    void off();
    
  
};

