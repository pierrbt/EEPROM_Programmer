#ifndef READFUNCTIONS_HPP
#define READFUNCTIONS_HPP

#include "DataFile.hpp"

void readData(bool data[IOPIN_NB]);
void verifyContent();
void compareData(byte dataToWrite[], byte dataToRead[], int length);


void verifyContent()
{
  setMode(0);
  const int dataLength = sizeof(DATA);
  byte decodedData[dataLength];
  long readAddr = 0;
  for(int i = 0; i < dataLength; ++i)
  {
    selectAddress(readAddr);
    
    bool octet[IOPIN_NB];
    readData(octet);

    decodedData[i] = boolArrayToHex(octet, IOPIN_NB);
    
    readAddr++;
  }

  Serial.print("DATA : ");
  for(int i = 0; i < dataLength; ++i)
  {
    Serial.print(DATA[i]);
    Serial.print(" ");
  }
  Serial.println();

  Serial.print("READ : ");
  for(int i = 0; i < dataLength; ++i)
  {
    Serial.print(decodedData[i]);
    Serial.print(" ");
  }
  Serial.println();

  

  compareData(DATA, decodedData, dataLength);
  
}

void readData(bool data[IOPIN_NB])
{
  for(int i = 0; i < IOPIN_NB; i++)
  {
    data[i] = digitalRead(IO[i]);
  }
}



void compareData(byte dataToWrite[], byte dataToRead[], int length) {
  bool binaryAddress[ADDRESS_NB];
  bool binaryData[IOPIN_NB];
  int errorsCount = 0;

  for (int i = 0; i < length; i++) {
    // Affichage de l'adresse et des données
    convertLongToBinary(i, binaryAddress);
    Serial.print("[LOG] Adresse : " + String(i));    
    Serial.print(" -- Donnees ecrites : 0x");
    Serial.print(dataToWrite[i], HEX);
    Serial.print(" / Donnees lues : 0x");
    Serial.println(dataToRead[i], HEX);

    // Comparaison des données
    if (dataToWrite[i] != dataToRead[i]) {
      Serial.println("[ERREUR] Les données lues ne correspondent pas aux données écrites.");
      // Affichage de l'adresse où l'erreur a été détectée
      convertLongToBinary(i, binaryAddress);
      Serial.print("[ERREUR] Adresse de l'erreur : ");
      for (int j = 0; j < ADDRESS_NB; j++) {
        Serial.print(binaryAddress[j]);
      }
      Serial.print(" (0x");
      Serial.print(i, HEX);
      Serial.println(")");
      Serial.println();
      // Incrémentation du compteur d'erreurs
      errorsCount++;
    }
  }

  // Affichage du nombre d'erreurs détectées
  if (errorsCount > 0) {
    Serial.print("[ERREUR] ");
    Serial.print(errorsCount);
    Serial.println(" erreur(s) détectée(s) !");
  } else {
    Serial.println("[LOG] Aucune erreur détectée !");
  }
}

#endif // READFUNCTIONS_HPP
