#ifndef ENVFUNCTIONS_HPP
#define ENVFUNCTIONS_HPP


#include "PinDefinitions.hpp"

void setMode(bool state);
void selectAddress(long addr, bool log = false);



void setMode(bool state)
{
  pinMode(CE, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(WE, OUTPUT);

  for(int i = 0; i < ADDRESS_NB; ++i)
  {
    pinMode(A[i], OUTPUT);
  }
  
  if(state)
  {
    // Mode d'ecriture
    for(int i = 0; i < IOPIN_NB; ++i)
    {
      pinMode(IO[i], OUTPUT);
      digitalWrite(IO[i], LOW);
    }
    
  }
  else
  {
    // Mode de lecture
    for(int i = 0; i < IOPIN_NB; ++i)
    {
      digitalWrite(IO[i], LOW);
      pinMode(IO[i], INPUT);
    }
  }
}


void selectAddress(long addr, bool log = false)
{
  bool binAddr[15];
  convertLongToBinary(addr, binAddr);
  if(log)
  {
    Serial.println("-----------------------------------------------------");
    Serial.print("[LOG] : Iteration ");
    Serial.println(addr + 1);
    Serial.print("[LOG] : Adresse selectionnee : ");
  }
  
  for(int i = 0; i < 15; ++i)
  {
    digitalWrite(A[i], binAddr[i]);
    if(log)    
      Serial.print(binAddr[i]);
  }
  Serial.println();
}


#endif // ENVFUNCTIONS_HPP
