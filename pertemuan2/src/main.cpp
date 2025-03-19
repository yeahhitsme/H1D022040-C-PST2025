#include <Arduino.h>

int echoPin = D0;
int trigPin = D1;
int LED1 = D3;
int LED2 = D8;

long duration;
int distance;

void setup() {
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration*0.034/2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");

  if (distance<=10)
  {
    digitalWrite(LED1,HIGH);
  } else if (distance <=20)
  {
    digitalWrite(LED2,HIGH);
  } else {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  }
  
  delay(1000);
}
