# @Auth Xtrans Solutions Pvt. Ltd.
# @Supreeth
# Program to test Buzzer

import time
import RPi.GPIO as gpio

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD) 

led = 5     # pin is connected to LED and it should be OUT
switch = 24  # pin is connected to SWITC and it should be IN
gpio.setup(led,gpio.OUT)
gpio.setup(switch,gpio.IN)

def glow_led():
  print("Button pressed")

GPIO.add_event_detect(switch, GPIO.RISING , callback = glow_led, bouncetime = 100)

