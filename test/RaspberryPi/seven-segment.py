#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

SDI   = 9	#data  
RCLK  = 10	#Latch	
SRCLK = 8	#Clock	

segCode = [0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e]

def print_msg():
	print ('Program is running...')
	print ('Please press Ctrl+C to end the program...')

def setup():
	GPIO.setmode(GPIO.BCM)    #Number GPIOs by its physical location
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

def loop():
	while True:
		for i in range(0, len(segCode)):
			for j in range(0, len(segCode)):
				hc595_shift((segCode[j])<<8|segCode[i])
				time.sleep(0.5)
			

def destroy():   #When program ending, the function is executed. 
	GPIO.cleanup()

if __name__ == '__main__': #Program starting from here 
	print_msg()
	setup() 
	try:
		loop()  
	except KeyboardInterrupt:  
		destroy()
