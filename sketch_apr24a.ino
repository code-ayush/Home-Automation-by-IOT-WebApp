#include<SoftwareSerial.h>
char dataString[50] = {0};
int a =0; 
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
  connection();
  Fire();
  pir();
  Ultra();
  gas();
  
 
}
void connection()
{
  
   a++;                          // a value increase every loop
  sprintf(dataString,"%02X",a); // convert a value to hexa 
  Serial.println(dataString);   // send the data
  delay(1000);                  // give the loop some break
}
void Fire()
{
sensorValue = analogRead(sensorPin);
if (sensorValue < 100)
{
Serial.println("Fire Detected");
delay(1000);
}
}
void pir()
{
  if (digitalRead(2) == HIGH)
  {          
    digitalWrite(4, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW)
    {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else
  {
      digitalWrite(4, LOW); // turn LED OFF
      delay(100);             // delay 200 milliseconds 
      
      if (state == HIGH)
      {
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
      }
  }
}


void Ultra()
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
void gas()
{
  int analogSensor = analogRead(A1);

  //Serial.print("Pin A1: ");
  //Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);

  }
  delay(100);
}

