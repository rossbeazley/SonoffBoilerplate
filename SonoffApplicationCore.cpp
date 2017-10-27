#include "SonoffApplicationCore.h"
#include <Arduino.h>

SonoffApplicationCore::SonoffApplicationCore(Relay * relay,bool initialStateOnIsTrue)
{
  this->relay = relay;
  this->relay->addObserver(this);
  if(initialStateOnIsTrue)
  {
    relay->close();
  }
  
}

SonoffApplicationCore::~SonoffApplicationCore()
{
  Serial.println("Desctructed SonoffApplicationCore::SonoffApplicationCore");
}

void SonoffApplicationCore::externalOn() 
{
  this->relay->close();  
}


void SonoffApplicationCore::externalOff() 
{
  this->relay->open();  
}


void SonoffApplicationCore::externalToggle()
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

void SonoffApplicationCore::addObserver(SonoffApplicationCoreObserver* obs)
{
  this->obs = obs;;
}


void SonoffApplicationCore::CLOSED()
{
  this->on=true;
  if(this->obs)
  {
    this->obs->ON();
  }
}

void SonoffApplicationCore::OPEN()
{
  this->on=false;
  if(this->obs)
  {
  this->obs->OFF();
  }
}


