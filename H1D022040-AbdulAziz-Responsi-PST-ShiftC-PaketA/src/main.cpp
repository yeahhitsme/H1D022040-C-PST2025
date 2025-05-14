#include <Arduino.h>

int echoPin = D0;
int trigPin = D1;
int LED1 = D3; //LED Merah sebagai tanda peringatan
int LED2 = D5; //LED Hijau sebagai tanda aman

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
  Serial.print(" cm");

  if (distance<=10)
  {
    digitalWrite(LED1,HIGH); //LED Merah menyala
  } else if (distance >10)
  {
    digitalWrite(LED2,HIGH); //LED Hijau menyala
  }
  
  delay(1000);
}
