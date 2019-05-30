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
  
#define reverseSpeed     200
#define turnSpeed        200
#define forwardSpeed     100
#define revDuration      200
#define turnDuration     500
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors;

const int echoPin1 = 2;
const int echoPin2 = 4;
const int triggerPin1 = 3;
const int triggerPin2 = 5;
const int maxDistance = 40;

NewPing sonar1(triggerPin1, echoPin1, maxDistance);
NewPing sonar2(triggerPin2, echoPin2, maxDistance);
 
void setup()
{
  Serial.begin(9600);
   sensors.init();
   button.waitForButton();
}

void turnLeft()
{
  motors.setSpeeds(-reverseSpeed, -reverseSpeed);
  delay(revDuration);
  motors.setSpeeds(turnSpeed, -turnSpeed);
  delay(turnDuration);
  motors.setSpeeds(forwardSpeed, forwardSpeed);
}

void turnRight()
{
  motors.setSpeeds(-reverseSpeed, -reverseSpeed);
  delay(revDuration);
  motors.setSpeeds(-turnSpeed, turnSpeed);
  delay(turnDuration);
  motors.setSpeeds(forwardSpeed, forwardSpeed);
}

void loop()
{
  sensors.read(sensor_values);
  if (sensor_values[0] < lightThresHold || sensor_values[5] < lightThreshold)
  {
    if (sensor_values[0] < lightThreshold)
    {
      turnLeft();
    }
    else if (sensor_values[5] < lightThreshold)
    {
      turnRight();
    }
  }
  
  unsigned int time = sonar1.ping();
  if (  
  
  // If haven't done anything, go forward
  motors.setSpeeds(forwardSpeed, forwardSpeed);
}
