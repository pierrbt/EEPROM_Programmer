/*
 * 
 *  Projet : Programmeur d'EEPROM en Arduino
 *  Modèles supportés : AT28C256
 *  Auteur : Pierre BIDET
 *  Language : C++ Arduino
 *  Copyright 2023
 *  
*/


#include "ConvertUtils.hpp"
#include "EnvFunctions.hpp"
#include "ReadFunctions.hpp"
#include "WriteFunctions.hpp"
#include "PinDefinitions.hpp"
#include "DataFile.hpp"



void setup() {
  Serial.begin(115200);
  
  Serial.println("[LOG] : Initialisation de l'Arduino ");
  Serial.println("[LOG] : Initialisation des pins en mode d'ecriture ");
  
  setMode(1);
  
  Serial.println("[LOG] : Initialisation terminee ");
  Serial.println();

  long writeAddr = 0;
  
  for (int i = 0; i < sizeof(DATA); i++) {
    writeContent(writeAddr, DATA[i]);    
    writeAddr++;
  }

  verifyContent();
}

void loop() {
  
}
