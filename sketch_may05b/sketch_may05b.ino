#include<SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR

int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
digitalWrite(8, HIGH);
Serial.begin(9600);

}

void loop()

{

sensorValue = analogRead(sensorPin);
if (sensorValue<100)
{
digitalWrite(9, LOW);
digitalWrite(8, LOW);
}
else
{
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}

}
