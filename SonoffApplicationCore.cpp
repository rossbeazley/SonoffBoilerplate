#include "SonoffApplicationCore.h"

SonoffApplicationCore::SonoffApplicationCore(Relay * relay)
{
  this->relay = relay;
  
}

void SonoffApplicationCore::externalOn() 
{
  this->relay->close();  
}


void SonoffApplicationCore::externalOff() 
{
  this->relay->open();  
}


