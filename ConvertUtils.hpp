#ifndef CONVERTUTILS_HPP
#define CONVERTUTILS_HPP

#endif // CONVERTUTILS_HPP

void convertByteToBinary(byte data, bool binaryData[]);
void convertLongToBinary(long address, bool binaryAddress[]);
byte boolArrayToHex(bool boolArray[], int length);



void convertByteToBinary(byte data, bool binaryData[]) {
  for (int j = 0; j < 8; j++) {
    binaryData[j] = (data >> (7 - j)) & 1;
  }
}

void convertLongToBinary(long address, bool binaryAddress[]) {
  for (int i = 0; i < 15; i++) {
    binaryAddress[i] = (address >> (14 - i)) & 1;
  }
}

byte boolArrayToHex(bool boolArray[], int length) {
  byte result = 0;
  for (int i = 0; i < length; i++) {
    Serial.print(boolArray[i]);
    Serial.print(" ");
    result |= (boolArray[i] << (length - i - 1));
  }
  Serial.println();
  return result;
}
