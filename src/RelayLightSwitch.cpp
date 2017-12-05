#include "RelayLightSwitch.h"

RelayLightSwitch::RelayLightSwitch(Relay & relay,bool initialStateOnIsTrue) : relay(relay)
{
  
  this->relay.addObserver(this);
  if(initialStateOnIsTrue)
  {
    this->relay.close();
  }
  
}

void RelayLightSwitch::externalOn() 
{
  this->relay.close();  
}


void RelayLightSwitch::externalOff() 
{
  this->relay.open();  
}


void RelayLightSwitch::externalToggle()
{
  if(this->on) 
  {
    this->externalOff();
  }
  else
  {
    this->externalOn();
  }
}

void RelayLightSwitch::addObserver(RelayLightSwitchObserver* obs)
{
  this->obs = obs;;
}


void RelayLightSwitch::CLOSED()
{
  this->on=true;
  if(this->obs)
  {
    this->obs->ON();
  }
}

void RelayLightSwitch::OPEN()
{
  this->on=false;
  if(this->obs)
  {
  this->obs->OFF();
  }
}


