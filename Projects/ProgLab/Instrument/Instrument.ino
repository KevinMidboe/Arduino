#include <Servo.h> 
 
Servo myservo;
 
int potpin = 0; 
int potReading; 
int photocellPin = 1;
int photocellReading;
 
void setup() 
{ 
  myservo.attach(9);
} 
 
void loop() 
{ 
  potReading = analogRead(potpin);           
  potReading = map(potReading, 0, 1023, 0, 179);     
  myservo.write(potReading);                  
  photocellReading = analogRead(photocellPin);
  
  int thisPitch = map(photocellReading, 1, 1000, 120, 1500);
  tone(8, thisPitch, 10);
  delay(1);  
}
