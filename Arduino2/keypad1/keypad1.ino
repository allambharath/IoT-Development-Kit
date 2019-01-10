/*4x4 Matrix Keypad connected to Arduino
This code prints the key pressed on the keypad to the serial port*/

#include <Keypad.h>
#include "LiquidCrystal.h" 
#include <dht.h>

dht DHT;

#define DHT11_PIN 12

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
LiquidCrystal lcd(14,15,16,17,18,19);
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};


//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {8,9,10,11}; //Rows 0 to 3
byte colPins[numCols]= {4,5,6,7}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//keypad.addEventListener(keypadEvent); // Add an event listener for this key


void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
int chk = DHT.read11(DHT11_PIN);
lcd.setCursor(0,0);
  Serial.print("Temperature = ");
  lcd.print("Temp :");
  lcd.print(DHT.temperature);


}

void printTemp()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.print("Temperature = ");
  lcd.print("Temp :");
  lcd.print(DHT.temperature);

}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
char keypressed = myKeypad.getKey();
if(keypressed)  

    {
        
        printTemp();
        lcd.setCursor(0,1);
       lcd.print(keypressed);
       //printTemp();
       //lcd.print(" Humi :");
       //lcd.print(DHT.humidity);
       //delay(5000);

    }

//Serial.print(keypressed);
//lcd.print(keypressed);


  //lcd.clear();
  
  //lcd.setCursor(0,1);
  //lcd.print("Humi :");
  //lcd.print(DHT.humidity);
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  //delay(500);
}
