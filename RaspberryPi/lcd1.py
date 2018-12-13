#!/usr/bin/python
# Example using a character LCD connected to a Raspberry Pi
from time import sleep, strftime
import Adafruit_CharLCD as LCD
from datetime import datetime
#we are calling for DATE
import SDL_DS1307

# Raspberry Pi pin setup
lcd_rs = 17
lcd_en = 27
lcd_d4 = 22
lcd_d5 = 23
lcd_d6 = 26
lcd_d7 = 10
lcd_backlight = 2

# Define LCD column and row size for 16x2 LCD.
lcd_columns = 16
lcd_rows = 2

#ds1307 = SDL_DS1307.SDL_DS1307(1, 0x68)  #entering I2c address, which we recorded previously
#ds1307.write_now()

lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7, lcd_columns, lcd_rows, lcd_backlight)



lcd.message('Hello\nXTRANS!')
# Wait 5 seconds

sleep(5.0)
lcd.clear()
#text = raw_input("Type Something to be displayed: ")
#lcd.message(text)

# Wait 5 seconds
##sleep(5.0)
##lcd.clear()
##lcd.message('Goodbye\nWorld!')
##sleep(5.0)
while True:
    lcd.clear()
    lcd.message(datetime.now().strftime('%b %d  %H:%M:%S\n'))
    sleep(1)
            
##    lcd.message(":")
##    lcd.message(ds1307._read_minutes())
##    lcd.message(":")
##    lcd.message(ds1307._read_seconds())
##    lcd.message(":")
##    time.sleep(1.0)
#lcd.clear()