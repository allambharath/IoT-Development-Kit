#!/usr/bin/env python
import RPi.GPIO as GPIO
import time
from pad4pi import rpi_gpio
import time
import Adafruit_GPIO.SPI as SPI
import Adafruit_MCP3008
import sys
import Adafruit_DHT
temp1 = 0
temp2 = 0
hum1 = 0
hum2 = 0


# Setup Keypad
KEYPAD = [
        [0,1,2,3],
        [4,5,6,7],
        [8,9,10,11],
        [12,13,14,15]
]

# same as calling: factory.create_4_by_4_keypad, still we put here fyi:
ROW_PINS = [5, 6, 26, 16] # BCM numbering
COL_PINS = [13, 19, 20, 21] # BCM numbering

factory = rpi_gpio.KeypadFactory()
keypad = factory.create_keypad(keypad=KEYPAD, row_pins=ROW_PINS, col_pins=COL_PINS)

SDI   = 17
RCLK  = 27
SRCLK = 22

##CLK  = 18
##MISO = 23
##MOSI = 24
##CS   = 25
##mcp = Adafruit_MCP3008.MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)
SPI_PORT   = 0
SPI_DEVICE = 0
mcp = Adafruit_MCP3008.MCP3008(spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE))

segCode = [0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e]

#segCode = [0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e]

def print_msg():
	print 'Program is running...'
	print 'Please press Ctrl+C to end the program...'
	
def printKey(key):
  humidity, temperature = Adafruit_DHT.read_retry(11, 4)
  print(key)
  hc595_shift(segCode[key]<<8|segCode[key])
  temp2 = int(temperature)/10
  temp1 = int(temperature)%10
  hum2 = int(humidity)/10
  hum2 = int(humidity)%10
  time.sleep(1)
  if key == 4 :
      hc595_shift(segCode[temp1]<<8|segCode[temp2])
      time.sleep(5)
  if key == 6 :
      hc595_shift(segCode[hum1]<<8|segCode[hum2])
      time.sleep(5)
    
def setup():
	GPIO.setmode(GPIO.BCM)
	GPIO.setwarnings(False)#Number GPIOs by its physical location
	GPIO.setup(SDI, GPIO.OUT)
	GPIO.setup(RCLK, GPIO.OUT)
	GPIO.setup(SRCLK, GPIO.OUT)
	GPIO.output(SDI, GPIO.LOW)
	GPIO.output(RCLK, GPIO.LOW)
	GPIO.output(SRCLK, GPIO.LOW)

def hc595_shift(dat):
	for bit in range(0, 16):
		GPIO.output(SDI, 0x8000 & (dat << bit))
		GPIO.output(SRCLK, GPIO.HIGH)
		time.sleep(0.001)
		GPIO.output(SRCLK, GPIO.LOW)
	GPIO.output(RCLK, GPIO.HIGH)
	time.sleep(0.001)
	GPIO.output(RCLK, GPIO.LOW)
	
keypad.registerKeyPressHandler(printKey)

def destroy():   #When program ending, the function is executed. 
	GPIO.cleanup()

if __name__ == '__main__': #Program starting from here 
	print_msg()
	setup() 
	try:
            while True:
            
            #value1 = mcp.read_adc(0)
            #print(value1)
            #t1 = value1/10
            #t2 = value1%10
            
            
            #print(t1)
            #print(t2)
            #hc595_shift(segCode[t1]<<8|segCode[t2])
            #time.sleep(3)
                hc595_shift(segCode[temp1]<<8|segCode[temp2])
                time.sleep(0.5)  
	except KeyboardInterrupt:  
		destroy()
	except :
                keypad.cleanup()

