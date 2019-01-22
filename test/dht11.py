import time
import Adafruit_DHT

#Set the type of sensor and the pin for sensor
sensor = Adafruit_DHT.DHT11
pin = 4


while(1):
    try:
        humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
        print ("Humidity =",humidity)
        print ("Temperature =",temperature)
    except ValueError:
        print ("Unable to read data")

