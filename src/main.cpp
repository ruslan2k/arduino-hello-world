// Example sketch for interfacing with the DS1302 timekeeping chip.
//
// Copyright (c) 2009, Matt Sparks
// All rights reserved.
//
// http://quadpoint.org/projects/arduino-ds1302
#include <Arduino.h>
#include <DS1302.h>

const int RST_PIN = 5;
const int DAT_PIN = 6;
const int CLK_PIN = 7;

int counter = 0;

// Create a DS1302 object.
DS1302 rtc(RST_PIN, DAT_PIN, CLK_PIN);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void printTime() {
  Time t = rtc.time();
  const String day = dayAsString(t.day);

  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  Serial.print("printTime func ");
  // Print the formatted string to serial so we can see the time.
  Serial.println(buf);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);

  // Initialize a new chip by turning off write protection and clearing the
  // clock halt flag. These methods needn't always be called. See the DS1302
  // datasheet for details.
  rtc.writeProtect(false);
  rtc.halt(false);

  // Make a new time object to set the date and time.
  //     YYYY MM DD - hh  mm  ss  Day of week
  Time t(2024, 8, 17, 13, 25, 50, Time::kSaturday);

  // Set the time and date on the chip.
  rtc.time(t);

  // Print the current time and date
  printTime();
}

// Loop and print the time every second.
void loop() {
  Serial.println(counter);
  printTime();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);

  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);

  counter++;
}
