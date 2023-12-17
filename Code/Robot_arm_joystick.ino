#include <Servo.h>

Servo servo_1;
Servo servo_2;
int del = 1000 , ctr=0;
float x , y;

void setup() 
{
servo_1.attach(2);
servo_2.attach(4);
pinMode(A1, INPUT_PULLUP);
pinMode(A2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
 if(digitalRead(3)==0)
 {
  ctr++;
 }

 if(ctr%2!=0)
 {
  x = (analogRead(A1) * 180.0) / 1023.0;
  y = (analogRead(A2) * 180.0) / 1023.0;

  servo_1.write(x);
  servo_2.write(y);
 }


  delay(del);
  
}
