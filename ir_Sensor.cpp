#include <LiquidCrystal.h>

/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
 /*
////////REMOTE1//////////////////
#define OPEN_S1 0X20DFC03F
#define CLOSE_S1  0X20DF40BF
#define STOP_S1 0X20DF10EF
*/
////////////////REMOTE2///////////////

#define FORWARD_S1 0X61A050AF
#define REVERSE_S1  0X61A0D02F
#define TURN_LEFT_S1 0X61A0B04F
#define TURN_RIGHT_S1 0X61A030CF
#define STOP_S1 0X61A0F00F
#define FIRE_S1 0X61A0708F
#define FIREout_S1 0X61A008F7


// #define FORWARD_S1 0X20
// #define FORWARD_S1 0X820
// #define REVERSE_S1  0X21
// #define REVERSE_S1  0X821
// #define TURN_LEFT_S1 0X11
// #define TURN_LEFT_S1 0X811
// #define TURN_RIGHT_S1 0X10
// #define TURN_RIGHT_S1 0X810
// #define STOP_S1 0X80C
// #define STOP_S1 0XC
// #define FIRE_S1 0XD
// #define FIRE_S1 0X80D
// #define FIREout_S1 0X61A008F7


#include <IRremote.h>
#include <Servo.h>

Servo servoLeft;
Servo servoRight;
#include <SoftwareSerial.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results; //BLUETOOTH DECLARATION

/* Declares an array holding various armature positions. If your servo starts grinding when you try 0 or 4, change this array to hold values in the range 1000 - 2000. */

int input = 11;            // input from the control device
int flag = 0;             // makes sure that the serial only prints once the input
int LEFT = 8;
int RIGHT = 9;
int FAN = 10;

SoftwareSerial mySerial(0, 1); // Initialize SoftwareSerial (RX, TX)
 

void setup()
{
  Serial.begin(9600);// THIS IS FOR PRINT SCREEN
  mySerial.begin(9600);// FOR BLUETOOTH
  irrecv.enableIRIn(); // Start the receiver
  pinMode (FAN, OUTPUT);

/*  
  ///////BLUETOOTH///////
  
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT); 
*/
}

void loop() 
{
  ////// THIS IS WHERE IR CODE START///////
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    switch (results.value) 
    {

//REMOTE FORWARD BUTTON
    case FORWARD_S1:
          stop();
         Serial.println("Forward");
          servoLeft.attach(LEFT);                      // Attach left signal to P13
          servoRight.attach(RIGHT);                     // Attach right signal to P12 
          forward();
        // servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
        // servoRight.writeMicroseconds(1300);        // Right wheel clockwise
        // delay(2000); 
         // servoRight.write(0);
         // servoLeft.write(180);
       
    break;


    case TURN_LEFT_S1:
          stop();
          servoLeft.attach(LEFT);                      // Attach left signal to P13
          servoRight.attach(RIGHT);                     // Attach right signal to P12 
          Serial.println("Turn Left");
          turnLeft();
          // servoLeft.writeMicroseconds(1500);   // Left wheel stop
          // servoRight.writeMicroseconds(1300);  // Right wheel clockwise
         // delay(600);
          // servoRight.write(145);
         // servoLeft.write(0);
    break;    
    
    case TURN_RIGHT_S1:
          stop();
          servoLeft.attach(LEFT);                      // Attach left signal to P13
          servoRight.attach(RIGHT);                     // Attach right signal to P12 
         Serial.println("Turn Right");
        //   servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
        // servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
         turnRight();
  // delay(600);
         // servoRight.write(180);
         // servoLeft.write(130);
    break;    


    case STOP_S1:
       Serial.println("STOP");
      servoLeft.detach();                      // Attach left signal to P13
      servoRight.detach();                     // Attach right signal to P12     break;
    break;
    
    case REVERSE_S1:
          stop();
          servoLeft.attach(LEFT);                      // Attach left signal to P13
          servoRight.attach(RIGHT);                     // Attach right signal to P12 
          reverse();
         Serial.println("Reverse");
         // servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
         // servoRight.writeMicroseconds(1700);        // 1.3 ms -> clockwise
         // delay(2000);
         // servoRight.write(180);
         // servoLeft.write(0);

    break;
    
 
   case FIRE_S1:
        servoLeft.detach();                      // Attach left signal to P13
        servoRight.detach();                     // Attach right signal to P12     break;
        Serial.println("OUT EEEE FIRE");
        digitalWrite(FAN, HIGH);   // turn the LED on (HIGH is the voltage level)
    break;
  

   case FIREout_S1:
        servoLeft.detach();                      // Attach left signal to P13
        servoRight.detach();                     // Attach right signal to P12     break;
        Serial.println("OUT FIRE");
        digitalWrite(FAN, LOW);   // turn the LED on (HIGH is the voltage level)
  
    break;
  
    
}// END OF SWITCH CASE FOR IR

}// END OF IR VOID LOOP



}

void stop(){
  servoLeft.detach();
  servoRight.detach();
}


// Motion routines for forward, reverse, turns, and stop
void forward() {
  servoLeft.write(0);
  servoRight.write(180);
}

void reverse() {
  servoLeft.write(180);
  servoRight.write(0);
}

void turnRight() {
  servoLeft.write(180);
  servoRight.write(180);
}
void turnLeft() {
  servoLeft.write(0);
  servoRight.write(0);
}

void stopRobot() {
  servoLeft.write(90);
  servoRight.write(90);
}




