from gpiozero import MCP3008
from time import sleep
tmp = MCP3008(channel=0, device=0)

while True:
    adcValue = (tmp.value * 3.3)*100
    print('{:.1f}'.format(adcValue), 10 * ' ')
    sleep(0.1)
