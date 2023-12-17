#include <Servo.h>
#include <IRremote.hpp>

Servo servo_1;
Servo servo_2;
int del = 10, rem = 7;

IRrecv irrecv(rem);
decode_results sig;

void setup() {
servo_1.attach(2);
servo_2.attach(4);
pinMode(A1, INPUT_PULLUP);
pinMode(A2, INPUT_PULLUP);
Serial.begin(9600);
irrecv.enableIRIn();

}

void loop() {
  float read , res;




  if(irrecv.decode(&sig))
  {
      read = analogRead(A1);
     res = (read*180.0)/1023.0;
      // Serial.print(read );
  //Serial.println(res);

  Serial.println(sig.value , HEX);
   if(sig.value==0xFF18E7)
    {
      servo_1.write(res);
      
      Serial.println("s1" );
    }

    if(sig.value==0xFF4AB5)
    {
      servo_2.write(res);
      Serial.println("s2");
    }

    irrecv.resume();
  }
  delay(del);
  
}
