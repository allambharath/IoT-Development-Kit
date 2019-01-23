# @Auth Xtrans Solutions Pvt. Ltd.
# @Supreeth
# Program to test light sensor

SPI_PORT   = 0
SPI_DEVICE = 0
mcp = Adafruit_MCP3008.MCP3008(spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE))
 
while True :
	value = mcp.read_adc(0)
	print(“Gas Value : “)
	print(value);
