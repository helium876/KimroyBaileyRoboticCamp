/*

	Blinks led faster the closer you get to it
	
*/

#include <Ultrasonic.h>

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
int led = 10; 
int sum = 0; 

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