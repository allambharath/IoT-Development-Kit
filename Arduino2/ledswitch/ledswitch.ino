int led = 14;
int switch1 = 2;
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
    //delay(1000);
  }
  else
  {
   digitalWrite(led,HIGH); 
   //delay(1000);
  }
}  


