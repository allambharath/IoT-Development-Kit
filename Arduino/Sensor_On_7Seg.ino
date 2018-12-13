#include <ShiftRegister74HC595.h>
#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
#define RX 2
#define TX 3
int smokeA0 = A0;
LiquidCrystal lcd(16,17,10,11,12,13);
String AP = "sierracartel SF LS";       // CHANGE ME
String PASS = "Konect@12345"; // CHANGE ME
String API = "PPGTYTC5TOFDE7CF";   // CHANGE ME
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX);
ShiftRegister74HC595 sr (2, 5, 6, 7); 
uint8_t  seg_number[] = {B11000000, //0
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
  esp8266.begin(115200);
  pinMode(smokeA0, INPUT);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
  lcd.begin(16,2);

}

void loop() {
 //valSensor = getSensorData();
 valSensor = analogRead(smokeA0);
 String getData = "GET /update?api_key="+ API +"&"+ field +"="+String(valSensor);
sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
 
 lcd.clear();
 lcd.setCursor(0,0);
//text to print
lcd.print("   GAS Value");
// set cusor position to start of next line
lcd.setCursor(0,1);
lcd.print(String(valSensor));
 uint8_t pinValues[] = {seg_number[valSensor/10],seg_number[valSensor%10]};
sr.setAll(pinValues); 
 Serial.println(getData);
 delay(1000);
}
int getSensorData(){
  return random(1000); // Replace with 
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
