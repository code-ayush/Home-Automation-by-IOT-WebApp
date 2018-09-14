#include<SoftwareSerial.h>

int sensorPin = A0; // FLAME
int sensorValue = 0; // variable to store the value coming from the sensor
int state = LOW; // by default, no motion detected
int sensorThres = 400; //GAS thresold


void setup() {
pinMode(4, OUTPUT); //led
pinMode(2, INPUT_PULLUP); //pir
pinMode(6, OUTPUT); //TRIGER
pinMode(5, INPUT); //ECHO
pinMode(7, OUTPUT);// LED
pinMode(9, OUTPUT);//LED
pinMode(A1, INPUT);//GAS
Serial.begin(9600);

}

void loop()
{
 
  long duration, distance;
  digitalWrite(6, LOW); 
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  duration = pulseIn(5, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 30) {
    digitalWrite(7, HIGH);
}
  if (distance > 30 || distance <= 0){
    digitalWrite(7, LOW);
  }
  else {
  Serial.print(distance);
  Serial.println(" cm");
   
  }
  delay(500);
}

