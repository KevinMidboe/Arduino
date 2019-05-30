/*
Drive forward and turn left or right when border is detected
  - Only reflectionsensor 0 and 5 are used.
*/
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <NewPing.h>
 
#define LED 13
 
// this might need to be tuned for different lighting conditions, surfaces, etc.
#define lightThreshold  1800 // 
  
#define reverseSpeed     400
#define turnSpeed        400
#define forwardSpeed     400
#define revDuration      300
#define turnDuration     200
#define triggerPin  3
#define echoPin  2
#define maxDistance  200

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors;

NewPing sonar(triggerPin, echoPin, maxDistance);

unsigned int pingSpeed = 100;
unsigned long pingTimer;
 
void setup()
{
   Serial.begin(115200);
   sensors.init();
   pingTimer = millis();
   //button.waitForButton();
}

boolean findLine()
{
  sensors.read(sensor_values);
  if (sensor_values[0] < lightThreshold || sensor_values[5] < lightThreshold)
  {
    if (sensor_values[0] < lightThreshold)
    {
      turnLeft();
      return true;
    }
    else if (sensor_values[5] < lightThreshold)
    {
      turnRight();
      return true;
    }
  }
  return false;
}

void turnLeft()
{
  motors.setSpeeds(-reverseSpeed, -reverseSpeed);
  delay(revDuration);
  motors.setSpeeds(turnSpeed, -turnSpeed);
  delay(turnDuration);
}

void turnRight()
{
  motors.setSpeeds(-reverseSpeed, -reverseSpeed);
  delay(revDuration);
  motors.setSpeeds(-turnSpeed, turnSpeed);
  delay(turnDuration);
}
/*
void search()
{
  time = sonar.ping();
  distance = sonar.convert_cm(time);
  if (distance < 40)
    motors.setSpeeds(310, 400);
  else
  {
    motors.setSpeeds(400, 400);
    delay(20);
    time = sonar.ping();
    distance = sonar.convert_cm(time);
    if (distance < 40)
      motors.setSpeeds(310, 400);
  }
}*/

void echoCheck()
{
  if (sonar.check_timer())
  {
    if (sonar.ping_result / US_ROUNDTRIP_CM < 20)
    {
      Serial.println(sonar.ping_result / US_ROUNDTRIP_CM);
      motors.setSpeeds(310, 400);
    }
    else
    {
      Serial.println("Nothing here!");
      motors.setSpeeds(400, 400);
      delay(20);
    }
  }
}

void scan()
{
  // Init at start, find the target.
}

void loop()
{ 
  findLine(); 
  motors.setSpeeds(310, 400);
  if (millis() >= pingTimer)
  {
    pingTimer += pingSpeed;
    sonar.ping_timer(echoCheck);
  }
}
