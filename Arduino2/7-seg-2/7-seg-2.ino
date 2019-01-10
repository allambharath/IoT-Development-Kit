        #include <ShiftRegister74HC595.h>

        // create shift register object (number of shift registers, data pin, clock pin, latch pin)
        ShiftRegister74HC595 sr (2, 0, 1, 2); 
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

        //  sr.setAllHigh(); // set all pins HIGH
         // delay(500);

        //  sr.setAllLow(); // set all pins LOW
       //   delay(500); 


          for (int i = 0; i < 6; i++) {

             for (int j = 0; j < 10; j++) {
            uint8_t pinValues[] = {numberB[i],numberB[j]};
                 sr.setAll(pinValues); 
                delay(1000); 
              }
           
          }


          // set all pins at once
         // uint8_t pinValues[] = {B11111001,B11111001}; 
         // sr.setAll(pinValues); 
          //delay(1000);

          // read pin (zero based)
         // uint8_t stateOfPin5 = sr.get(5);

        }
        
