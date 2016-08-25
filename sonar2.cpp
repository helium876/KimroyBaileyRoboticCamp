#include <Ultrasonic.h>
#include <Servo.h> 

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
Servo RightServo;
Servo LeftServo;

void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  sum = ultrasonic.Ranging(CM) * 5;
  digitalWrite(led, HIGH);
  delay(sum);
  digitalWrite(led, LOW);
  delay(sum);
}