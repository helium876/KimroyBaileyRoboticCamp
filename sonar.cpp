#include <Ultrasonic.h>

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
int led = 10; 
int val = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  val = ultrasonic.Ranging(CM);
  Serial.println(" cm" );
  if (val <= 10)
  {
  	turnOn();
  }
  else{
  	turnOff();
  }
}

void turnOn(){
	digitalWrite(led, HIGH);
}

void turnOff(){
	digitalWrite(led, LOW);
}