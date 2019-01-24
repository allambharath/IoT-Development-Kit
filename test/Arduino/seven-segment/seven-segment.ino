//Demo program to test seven segment display
//
#include <ShiftRegister74HC595.h>

// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, 26, 24, 25); 
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
  
}

void loop() {
  for (int i = 0; i < 10; i++) {
     for (int j = 0; j < 10; j++) {
        uint8_t pinValues[] = {numberB[i],numberB[j]};
        sr.setAll(pinValues); 
        delay(1000); 
      }
  }

}
