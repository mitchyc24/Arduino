const int buzzer = 8; //buzzer to arduino pin 9
const int AirValue = 620;   //replace this with value1
const int WaterValue = 310; //replace this with value2
int soilMoistureValue = 0;
int soilMoisturePercent = 0;



void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {
  soilMoistureValue = analogRead(A0);
  //Serial.println(soilMoistureValue);
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

 if(soilMoisturePercent < 25){
  tone(buzzer, 1000); // Send 1KHz sound signal...
  per_print(soilMoisturePercent);
 }
 else{
  noTone(buzzer);
  per_print(soilMoisturePercent);
 }

 delay(1000);
}

void per_print(int value){
  Serial.print(soilMoisturePercent);
  Serial.println("%");
}
