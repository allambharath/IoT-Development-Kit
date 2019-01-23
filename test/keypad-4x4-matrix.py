import RPi.GPIO as GPIO
import time
from pad4pi import rpi_gpio

KEYPAD = [
        ["1","2","3","A"],
        ["4","5","6","B"],
        ["7","8","9","C"],
        ["*","0","#","D"]
]

ROW_PINS = [24,19,21,23] # BCM numbering
COL_PINS = [15,12,3,5] # BCM numbering

factory = rpi_gpio.KeypadFactory()
keypad = factory.create_keypad(keypad=KEYPAD, row_pins=ROW_PINS, col_pins=COL_PINS)


def printKey(key):
    print(key)
    time.sleep(2)

keypad.registerKeyPressHandler(printKey)

def destroy():   #When program ending, the function is executed. 
	GPIO.cleanup()

if __name__ == '__main__': #Program starting from here 
	try:
        while True:
            time.sleep(0.5)  
	except KeyboardInterrupt:  
		destroy()
	except :
        keypad.cleanup()