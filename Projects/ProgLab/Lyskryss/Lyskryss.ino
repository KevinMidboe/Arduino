#include <Servo.h>
#include <NewPing.h>

#define Trigger_Pin 12
#define Echo_Pin 11
#define Max_Distance 200

// Green car - 10
// Yellow car - 9
// Red car - 8
// Green person - 7
// Red person - 6
// ECHO 11 & 12


NewPing sonar(Trigger_Pin, Echo_Pin, Max_Distance);

Servo gateServo;
int servoPos = 0;

int lightPinArray[] = {
  10, 9, 9, 8, 7, 6, 6, 7, 9, 8, 9};
boolean lightStateArray[] = {
  LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, HIGH, LOW, LOW};
int lightDelayArray[] = {
  1000, 0, 500, 0, 500, 0, 2000, 0, 500, 500, 0};

void setup() 
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(i + 6, OUTPUT);
  }
  gateServo.attach(4);
}

void personDetected()
{
  for(int i = 0; i < 12; i++)
  {
    delay(lightDelayArray[i]);
    digitalWrite(lightPinArray[i], lightStateArray[i]);
  }

void loop()
{
  unsigned int uS = sonar.ping();
  if ((uS /US_ROUNDTRIP_CM) < 5 && uS /US_ROUNDTRIP_CM > 1)
  {
    personDetected();
  }
  else
  {
    digitalWrite(7, HIGH);
    digitalWrite(10, HIGH);
  }
}
