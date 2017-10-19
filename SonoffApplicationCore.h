#pragma once

class RelayObserver
{
  public:
    virtual void CLOSED() = 0;
  
};

class Relay
{
  public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void addObserver(RelayObserver*) = 0;
};



class SonoffApplicationCoreObserver
{
  public:
    virtual void ON() = 0;
    
};

class SonoffApplicationCore : public RelayObserver
{
  public:
    SonoffApplicationCore(Relay*); //think i can avoid pointers?
    void externalOn();
    void externalOff();
    void addObserver(SonoffApplicationCoreObserver*);
    void CLOSED();
  private:
    Relay* relay;
    SonoffApplicationCoreObserver* obs;
    
  
};

