#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
Servo myservo;
int val = 0;

void setup() {
  Serial.begin(9600); 
   myservo.attach(10);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  val = ultrasonic.Ranging(CM);
  Serial.println(" cm" );
  delay(100);
  if(val < 10){
    myservo.write(0);
  }
  else{
    myservo.write(90);
  }
}
