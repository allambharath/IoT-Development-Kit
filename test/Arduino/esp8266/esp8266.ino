#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<ThingSpeak.h>
#include<ArduinoJson.h>
String rawData;
#define RX 2
#define TX 3
int smokeA0 = A0;
LiquidCrystal lcd(14,15,16,17,18,19);
String AP = "sierracartel SF LS";       // CHANGE ME
String PASS = "Konect@12345"; // CHANGE ME
String API = "PPGTYTC5TOFDE7CF";   // CHANGE ME
const char APIR = '7UW8N07YGBUMJQY8';
long unsigned int MyChannelId = 456119;
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 
StaticJsonBuffer<200> jsonBuffer;

  
void setup() 
{
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
 //String getData = "GET /update?api_key="+ API +"&"+ field +"="+String(valSensor);
 String getData = "GET /channels/456119/fields/1/last.json?api_key=7UW8N07YGBUMJQY8";
 sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);
 delay(1500);
 countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
 //String response = ThingSpeak.readRaw(MyChannelId, String(String("/fields/") + String(1) + String("/last_data_age")),APIR);
//Serial.print("Response: ");
//Serial.print(response);
 lcd.clear();
 lcd.setCursor(0,0);
//text to print
lcd.print("   GAS Value");
// set cusor position to start of next line
lcd.setCursor(0,1);
lcd.print(String(valSensor));
//Serial.println(getData);
// if (esp8266.available() > 0) {
 //delay(100);
// esp8266.setTimeout(1500);
 rawData = esp8266.readString();
 Serial.println(rawData);
 
 JsonObject& root = jsonBuffer.parseObject(rawData);
 
if(!root.success()) {
  Serial.println("parseObject() failed");
  return false;
}

 const char* sensor = root["created_at"];
 


 Serial.println(sensor);
 delay(4000);
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
