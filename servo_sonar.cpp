#include <Ultrasonic.h>
#include <Servo.h> 
Ultrasonic ultrasonic(11,10); // (Trig PIN,Echo PIN) 
Servo RightServo;
Servo LeftServo;
int distance = 0;

void setup() {
  Serial.begin(9600); 
  RightServo.attach(9);
  LeftServo.attach(8);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); 
  Serial.println(" cm" );
  distance = ultrasonic.Ranging(CM);
  if (distance < 20){
    connect();
    delay(500);
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