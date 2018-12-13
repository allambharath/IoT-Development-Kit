import RPi.GPIO as GPIO
import time
import Adafruit_DHT
import Adafruit_CharLCD as LCD
from datetime import datetime
import requests
import json

temp1 = 0
temp2 = 0
hum1 = 0
hum2 = 0
# Raspberry Pi pin setup
lcd_rs = 17
lcd_en = 27
lcd_d4 = 22
lcd_d5 = 23
lcd_d6 = 24
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

time.sleep(5.0)
lcd.clear()

def destroy():   #When program ending, the function is executed. 
	GPIO.cleanup()

if __name__ == '__main__': #Program starting from here 
    
    try:
        while True:
            humidity, temperature = Adafruit_DHT.read_retry(11, 4)
            print(humidity)
            print(temperature)
            
            #lcd.message(datetime.now().strftime('%b %d  %H:%M:%S\n'))
           
            r1= requests.get("https://api.thingspeak.com/update.json?api_key=IBUC2HWBHUYYC6SG&field1="+str(temperature))
            print("Temperature Uploaded")
            time.sleep(2)
            r = requests.get("http://api.thingspeak.com/channels/456119/fields/1/last.json?api_key=7UW8N07YGBUMJQY8")
           # n = json.dumps(r.content)
            o = json.loads(r.content)
            gas = int(o["field1"])
            print(o["field1"])
            lcd.clear()
            lcd.message("GAS : "+str(o["field1"]))
            lcd.message("\nTemp:"+str(temperature))
            if(gas>145) :
                lcd.message("")
            time.sleep(3)  
    except KeyboardInterrupt:
            destroy()
