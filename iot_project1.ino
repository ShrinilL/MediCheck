
#include <Wire.h>
#include <Servo.h>
const int trigPin = 7;
const int echoPin = 6;

Servo Myservo;

void setup()
{
  Serial.begin(9600);
  Myservo.attach(5);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.print(" Distance  ");
  Serial.print(" Measurement  ");
  delay(2000);
}

void loop()
{
  long duration, cm;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  cm=microsecondsToCentimeters(duration);
  
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  delay(100);
  
  if(cm>=15) {
    Myservo.write(0);
  }
  else {
    Myservo.write(90);
  }
  
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}