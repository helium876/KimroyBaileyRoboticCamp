#include <Ultrasonic.h>
#include <Servo.h> 

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
Servo RightServo;
Servo LeftServo;
int distance = 0;

void setup() {
  Serial.begin(9600); 
  RightServo.attach(10);
  LeftServo.attach(11);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  distance = ultrasonic.Ranging(CM);
  delay(500);
  if (distance){
    connect();
    RightServo.write(0);
    LeftServo.write(180);
  }else{
    RightServo.detach();
    LeftServo.detach();
  }
}

void connect(){
  RightServo.attach(10);
  LeftServo.attach(11);
}