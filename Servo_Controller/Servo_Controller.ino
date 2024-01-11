/*
 *  SERVO - ARDUINO CONTROLLER
 * 
 */
 
 #include <Servo.h>
 #include <math.h>
 

 int deg = 0;
 int count = 0;
 float x; 
 Servo myservo;


void setup() {
  myservo.attach(10,650,2340);

}

void loop() {
//  count += 1;
//  x = cos(M_PI*count/180);
//  deg = 90 + (int)x*90;



  deg = rand()%180;
  myservo.write(deg);
  delay(60000);
  
  

}
