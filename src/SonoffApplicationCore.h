#pragma once

class RelayObserver
{
  public:
    virtual void CLOSED() = 0;
    virtual void OPEN() = 0;
  
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
    virtual void OFF() = 0;
    
};

class LightSwitch
{
  public:
    virtual void externalOn() = 0;
    virtual void externalOff() = 0;
    virtual void externalToggle() = 0;
};

class SonoffApplicationCore : public RelayObserver, public LightSwitch
{
  public:
    SonoffApplicationCore(Relay&,bool = false); //think i can avoid pointers?
    void externalOn();
    void externalOff();
    void externalToggle();
    void addObserver(SonoffApplicationCoreObserver*);
    //void toggleLight();
    //void resetSettings();
    //void restart();
    
  //RelayObserver
    void CLOSED();
    void OPEN();
  private:
    Relay& relay;
    SonoffApplicationCoreObserver* obs = nullptr;
    bool on;
    
  
};


