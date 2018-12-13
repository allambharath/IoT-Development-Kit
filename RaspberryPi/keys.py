import RPi.GPIO as GPIO
import time
from pad4pi import rpi_gpio

KEYPAD = [
        [0xc0,0xf9,0xa4,0xb0],
        [0x99,0x92,0x82,0xf8],
        [0x80,0x90,0x88,0x83],
        [0xc6,0xa1,0x86,0x8e]
]

SDI   = 17
RCLK  = 27
SRCLK = 22


ROW_PINS = [5, 6, 26, 16] # BCM numbering
COL_PINS = [13, 19, 20, 21] # BCM numbering

factory = rpi_gpio.KeypadFactory()
keypad = factory.create_keypad(keypad=KEYPAD, row_pins=ROW_PINS, col_pins=COL_PINS)

segCode = [0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e]

def print_msg():
	print 'Program is running...'
	print 'Please press Ctrl+C to end the program...'

def printKey(key):
  #humidity, temperature = Adafruit_DHT.read_retry(11, 4)
  print(key)
  #print(segCode[ord(key)])
  hc595_shift(key)
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
	for bit in range(0, 8):
		GPIO.output(SDI, 0x80 & (dat << bit))
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
                #hc595_shift(segCode[temp1]<<8|segCode[temp2])
                time.sleep(0.5)  
	except KeyboardInterrupt:  
		destroy()
	except :
                keypad.cleanup()