# @Auth Xtrans Solutions Pvt. Ltd.
# @Supreeth
# Program to LED and switches

import time
import RPi.GPIO as gpio

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD) 

led1 = 5     # pin is connected to LED and it should be OUT
led2 = 3     # pin is connected to LED and it should be OUT
led3 = 12     # pin is connected to LED and it should be OUT
led4 = 15    # pin is connected to LED and it should be OUT
switch1 = 24  # pin is connected to SWITC and it should be IN
switch2 = 19  # pin is connected to SWITC and it should be IN
switch3 = 21  # pin is connected to SWITC and it should be IN
switch4= 23  # pin is connected to SWITC and it should be IN

gpio.setup(led1,gpio.OUT)
gpio.setup(led2,gpio.OUT)
gpio.setup(led3,gpio.OUT)
gpio.setup(led4,gpio.OUT)
gpio.setup(switch1,gpio.IN)
gpio.setup(switch2,gpio.IN)
gpio.setup(switch3,gpio.IN)
gpio.setup(switch4,gpio.IN)

def glow_led(event):
    if event == switch1 :
        gpio.output(led1, False)
        time.sleep(1)
        gpio.output(led1, True)
    
    elif event == switch2 :
        gpio.output(led2, False)
        time.sleep(1)
        gpio.output(led2, True)
        
    
    elif event == switch3 :
        gpio.output(led3, False)
        time.sleep(1)
        gpio.output(led3, True)
    
    elif event == switch4 :
        gpio.output(led4, False)
        time.sleep(1)
        gpio.output(led4, True)

gpio.add_event_detect(switch1, gpio.RISING , callback = glow_led, bouncetime = 100)
gpio.add_event_detect(switch2, gpio.RISING , callback = glow_led, bouncetime = 100)
gpio.add_event_detect(switch3, gpio.RISING , callback = glow_led, bouncetime = 100)
gpio.add_event_detect(switch4, gpio.RISING , callback = glow_led, bouncetime = 100)

try:
    while(True):
    #to avoid 100% CPU usage
        time.sleep(1)
except KeyboardInterrupt:
    #cleanup GPIO settings before exiting
    GPIO.cleanup()


