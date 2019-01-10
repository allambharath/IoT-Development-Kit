int soilA1 = A1;
// Your threshold value
//int sensorThres = 400;

void setup() {
  pinMode(soilA1, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(soilA1);

  Serial.print("Soil Content is: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  
  delay(1000);
}
