#include <SoftwareSerial.h>
#include <AccelStepper.h>
#define HALFSTEP 8
SoftwareSerial mySerial(2,3);
String cmd;
#define motorPin1  10     // IN1 on the ULN2003 driver 1
#define motorPin2  11    // IN2 on the ULN2003 driver 1
#define motorPin3  12     // IN3 on the ULN2003 driver 1
#define motorPin4  13    // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup()
{
mySerial.begin(9600);   
Serial.begin(9600);
pinMode(13,OUTPUT);
stepper1.setMaxSpeed(1000.0);
 stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(20000);
   
delay(100);
}
void loop()
{
if (Serial.available()>0)
mySerial.write(Serial.read());
cmd = mySerial.readString();
if(cmd == "ON")
{
  while(1)
  {//mySerial.write(mySerial.read());
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  stepper1.run();
//  if(mySerial.readString() == "OFF")
//  {
//    stepper1.stop();
//  }
  }
}

}

