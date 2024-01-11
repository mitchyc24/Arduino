 #define ssd_0 52 // 52    ---48---
 #define ssd_1 50 //     |           |
 #define ssd_2 48 //     50          46
 #define ssd_3 46 //     |           |
 #define ssd_4 47 //       ---47----
 #define ssd_5 49 //     |           |
 #define ssd_6 51 //     53          49
 #define ssd_7 53 //     |           |
 #define led 13   //       ----51----
 
 #define dat 4
 boolean reg[8];
 int speedLED = 100;

void setup() {
 pinMode(ssd_0, OUTPUT);
 pinMode(ssd_1, OUTPUT);
 pinMode(ssd_2, OUTPUT);
 pinMode(ssd_3, OUTPUT);
 pinMode(ssd_4, OUTPUT);
 pinMode(ssd_5, OUTPUT);
 pinMode(ssd_6, OUTPUT);
 pinMode(ssd_7, OUTPUT);
 pinMode(led, OUTPUT);
}

void loop() {


  infinity();
  decreaseSpeed(0.95); 

}

void decreaseSpeed(float amnt){
    speedLED *= amnt; 
}

void writePos(int a)
{
  digitalWrite(a,HIGH);
  delay(speedLED);
  digitalWrite(a,LOW);
}
void infinity(void){
  writePos(47);
  writePos(50);
  writePos(48);
  writePos(46);
  writePos(47);
  writePos(53);
  writePos(51);
  writePos(49);
}
