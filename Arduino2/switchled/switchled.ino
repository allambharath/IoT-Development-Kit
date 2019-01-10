const int switchPin = 4; //Switch Connected to PIN 4
const int ledPin = 8; //LED Connected to PIN 8
int switchState = 0; // Variable for reading Switch status
void setup()
{
    pinMode(ledPin, OUTPUT); //LED PIN is Output
    pinMode(switchPin, INPUT);//Switch PIN is input with PULLUP
}
void loop()
{
    switchState = digitalRead(switchPin); //Reads the status of the switch.
    if (switchState == LOW) //If the switch is pressed
    {
        digitalWrite(ledPin, HIGH); //LED ON
        delay(3000); //3 Second Delay
        digitalWrite(ledPin, LOW); //LED OFF
    }
}
