import time

# Import SPI library (for hardware SPI) and MCP3008 library.
import Adafruit_GPIO.SPI as SPI
import Adafruit_MCP3008


# Software SPI configuration:
##CLK  = 18
##MISO = 23
##MOSI = 24
##CS   = 25
##mcp = Adafruit_MCP3008.MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)

#Hardware SPI configuration:
SPI_PORT   = 0
SPI_DEVICE = 0
mcp = Adafruit_MCP3008.MCP3008(spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE))


print('Reading MCP3008 values, press Ctrl-C to quit...')
# Print nice channel column headers.
##print('| {0:>4} | {1:>4} | {2:>4} | {3:>4} | {4:>4} | {5:>4} | {6:>4} | {7:>4} |'.format(*range(8)))
##print('-' * 57)
# Main program loop.
while True:
    # Read all the ADC channel values in a list.
    #value = 0
     # The read_adc function will get the value of the specified channel (0-7).
    value1 = mcp.read_adc(0)
    #value2 = mcp.read_adc(1)
    # Print the ADC values.
    print(value1)
    #print(value2)
    # Pause for half a second.
    time.sleep(0.5)