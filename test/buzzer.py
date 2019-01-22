# @Auth Xtrans Solutions Pvt. Ltd.
# Program to test Buzzer

import time
import RPi.GPIO as gpio

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)
gpio.setup(28,gpio.OUT)

try:
    while True:
        gpio.output(28,0)
        time.sleep(.3)
        gpio.output(28,1)
        time.sleep(.3)
except KeyboardInterrupt:
        gpio.cleanup()
        exit
