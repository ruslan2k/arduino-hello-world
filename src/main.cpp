#include <Arduino.h>
#include <DS1302.h>

// Set the pins for the DS1302
const int RST_PIN = 5; // Reset
const int DAT_PIN = 6; // Data
const int CLK_PIN = 7; // Clock

// Create an instance of the DS1302 class
DS1302 rtc(RST_PIN, DAT_PIN, CLK_PIN);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  rtc.writeProtect(false);
  rtc.halt(false);

  // rtc.time(Time(2024, 7, 10, 0, 0, 0, Time::kWednesday));
}

void loop() {
  // Set the LED HIGH
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("HIGH");

  // Wait for a second
  delay(1000);

  // Set the LED LOW
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LOW");

  delay(10000);

  Serial.print(rtc.time().min);
  Serial.print(':');
  Serial.print(rtc.time().sec);
  Serial.println(' ');

}
