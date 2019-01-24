
//CN4 and CN9 connected
//Led1 - Arduino  pin 13/A5 , Switch1 - 24/D10 
//Led2 - Arduino  pin 30/A4 , Switch1 - 25/D11 
//Led3 - Arduino  pin 11/A3 , Switch1 - 26/D12 
//Led4 - Arduino  pin 10/A2 , Switch1 - 27/D13 
int led = A3;   //Arduino  pin 13/A5
int switch1 = 12;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(switch1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(switch1));
  if(digitalRead(switch1) == 1)
  {
    digitalWrite(led,LOW);
    delay(1000);
  }
  else
  {
   digitalWrite(led,HIGH); 
   delay(1000);
  }
}  
