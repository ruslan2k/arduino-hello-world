#include <Arduino.h>

int led_pin=13;

void setup() {
  int led_pin=13;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(10000);
}
