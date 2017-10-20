#include "SonoffApplicationCore.h"

SonoffApplicationCore::SonoffApplicationCore(Relay * relay)
{
  this->relay = relay;
  this->relay->addObserver(this);
  
}

void SonoffApplicationCore::externalOn() 
{
  this->relay->close();  
}


void SonoffApplicationCore::externalOff() 
{
  this->relay->open();  
}

void SonoffApplicationCore::addObserver(SonoffApplicationCoreObserver* obs)
{
  this->obs = obs;;
}

void SonoffApplicationCore::CLOSED()
{
  this->obs->ON();
}

void SonoffApplicationCore::OPEN()
{
  this->obs->OFF();
}

