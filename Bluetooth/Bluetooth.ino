#include <SoftwareSerial.h>

int led = 13;
int data;

void setup(){
  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); 
  Serial.begin(9600);
}


void loop(){
  if(Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data);
    if(data == 2){
      digitalWrite(led, LOW);
      Serial.println('LED OFF');
    }
    
    if(data == 1){
      digitalWrite(led, HIGH);
      Serial.println('LED ON');
    }
  }
}



