#ifndef WRITEFUNCTIONS_HPP
#define WRITEFUNCTIONSHPP

#include "EnvFunctions.hpp"

void writeData(bool data[IOPIN_NB]);
void writeContent(long addr, bool data[IOPIN_NB]);


void writeData(bool data[IOPIN_NB])
{
  for(int i = 0; i < IOPIN_NB; ++i)
  {
    digitalWrite(IO[i], data[i]);
  }
}


void writeContent(long address, byte data)
{
  const unsigned long begin = millis();
  selectAddress(address, true);
  
  bool binaryData[IOPIN_NB];
  convertByteToBinary(data, binaryData);
  Serial.print("[LOG] : Donnees converties en binaire : ");

  for(int j = 0; j < IOPIN_NB; ++j)
  {
    Serial.print(binaryData[j]);
  }
  Serial.println();
  
  writeData(binaryData);
  
  Serial.print("[LOG] : Succes en ");
  Serial.print(millis() - begin);
  Serial.println(" ms");
  Serial.println();

  delay(AFTER_DELAY);
}

#endif // WRITEFUNCTIONS_HPP
