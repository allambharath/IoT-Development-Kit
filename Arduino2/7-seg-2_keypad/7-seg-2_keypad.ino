#include <Keypad.h>
#include <ShiftRegister74HC595.h>
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{B11111001, B10100100, B10110000, 'A'},
{B10011001, B10010010, B10000010, 'B'},
{'7', '8', '9', 'C'},
{'*', B11000000, '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {8,9,10,11}; //Rows 0 to 3
byte colPins[numCols]= {4,5,6,7}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


        // create shift register object (number of shift registers, data pin, clock pin, latch pin)
        ShiftRegister74HC595 sr (1, 2, 12, 13); 
        uint8_t  numberB[] = {B11000000, //0
                      B11111001, //1 
                      B10100100, //2
                      B10110000, //3 
                      B10011001, //4
                      B10010010, //5
                      B10000010, //6
                      B11111000, //7
                      B10000000, //8
                      B10010000 //9
                     };

        void setup() {
         Serial.begin(9600); 
        }

        void loop() {

        //  sr.setAllHigh(); // set all pins HIGH
         // delay(500);

        //  sr.setAllLow(); // set all pins LOW
       //   delay(500); 
 char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)
{
//Serial.print(keypressed);
uint8_t pinValues[] = {keypressed};
Serial.println(atoi(keypressed));
                 sr.setAll(pinValues); 
            
}

              
           
          


          // set all pins at once
         // uint8_t pinValues[] = {B11111001,B11111001}; 
         // sr.setAll(pinValues); 
          //delay(1000);

          // read pin (zero based)
         // uint8_t stateOfPin5 = sr.get(5);

        }
        
