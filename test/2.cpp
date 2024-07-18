#include <Wire.h>

#define DS1307_ADDRESS 0x68

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);
  
  int second = bcdToDec(Wire.read() & 0x7f);
  int minute = bcdToDec(Wire.read());
  int hour = bcdToDec(Wire.read() & 0x3f);
  
  Serial.print("Time: ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
  
  delay(1000);
}

byte decToBcd(byte val) {
  return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val) {
  return ( (val/16*10) + (val%16) );
}
