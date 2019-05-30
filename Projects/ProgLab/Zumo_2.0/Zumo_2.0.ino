#include <PLab_ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>

#define maxSpeed     400
#define reverseSpeed 400
#define lightThreshold  1800

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
unsigned int sensorValues[6];
ZumoReflectanceSensorArray reflectaneceSensors;

void setup()
{
   reflectaneceSensors.init();
   motors.setSpeeds(0,0);
   button.waitForButton();
}

void findLine()
{
   reflectaneceSensors.read(sensorValues);
   if (sensorValues[0] > lightThreshold)
   {
      turnLeft(1000);
   }
   else if (sensorValues[5] > lightThreshold)
   {
      turnRight(1000);
   }
}

void turnLeft(int delayTime)
{
   motors.setSpeeds(0, 200);
   delay(delayTime);
}
void turnRight(int delayTime)
{
   motors.setSpeeds(200, 0);
   delay(delayTime);
}

void loop()
{
   findLine();
   motors.setSpeeds(200, 200);
}


