// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
int led = 8;

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
  pinMode(led, OUTPUT);
}
void loop() {
  // read the sensor on analog A0:
	int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood");
    blinkFast();
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning");
    blink();
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining");
    NoBlink();
    break;
  }
  delay(500);  // delay between reads
}


void blink(){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
}

void blinkFast(){
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
}

void NoBlink(){
  digitalWrite(led, HIGH);
}