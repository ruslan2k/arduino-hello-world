#include <DS3231.h>                    
DS3231  rtc(SDA, SCL);                 

void setup()
{
  Serial.begin(9600);                
  rtc.begin();                        
  
// Установка времени
  rtc.setDOW(WEDNESDAY);               // СРЕДА
  rtc.setTime(16, 29, 0);              //  16:29:00 
  rtc.setDate(17, 7, 2024);            //  17 07 2024 
}
void loop()
{
  Serial.print(rtc.getDOWStr());       // Отправляем день-неделя
  Serial.print(" ");
  
  Serial.print(rtc.getDateStr());      // Отправляем дату
  Serial.print(" -- ");

  Serial.println(rtc.getTimeStr());    // Отправляем время
  
  delay (10000);                      
}
