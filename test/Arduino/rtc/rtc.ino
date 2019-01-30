#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h> 
LiquidCrystal lcd(16, 17, 13, 12, 11, 10);

RTC_DS1307 RTC;

void setup () {
    Serial.begin(57600);
    Wire.begin();
    RTC.begin();
    lcd.begin(16,2);

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
    DateTime now = RTC.now();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(now.year());
    Serial.print(now.year(), DEC);
    lcd.print("/");
    Serial.print('/');
    lcd.print(now.month());
    Serial.print(now.month(), DEC);
    lcd.print("/");
    Serial.print('/');
    lcd.print(now.day());
    Serial.print(now.day(), DEC);
    lcd.setCursor(0,1);
    Serial.print(' ');
    lcd.print(now.hour());
    Serial.print(now.hour(), DEC);
    lcd.print(":");
    Serial.print(':');
    lcd.print(now.minute());
    Serial.print(now.minute(), DEC);
    lcd.print(":");
    Serial.print(':');
    lcd.print(now.second());
    Serial.print(now.second(), DEC);
    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now.unixtime() + 7 * 86400L + 30);
    
    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();
    
    Serial.println();
    delay(1000);
}
