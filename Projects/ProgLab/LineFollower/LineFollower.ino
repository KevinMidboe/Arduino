#include <PLab_ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>

#define driveSpeed     150
#define lightThreshold  800

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
unsigned int sensorValues[6];
ZumoReflectanceSensorArray reflectanceSensors;

void setup()
{
   reflectanceSensors.init();
   motors.setSpeeds(0,0);
   button.waitForButton();
}

void findLine()
{
   reflectanceSensors.read(sensorValues);
   if (sensorValues[0] > lightThreshold)
   {
      turnLeft();
   }
   else if (sensorValues[5] > lightThreshold)
   {
      turnRight();
   }
}

void turnLeft()
{
   motors.setSpeeds(-driveSpeed, -300);
   delay(400);
}
void turnRight()
{
   motors.setSpeeds(-300, -driveSpeed);
   delay(400);
}

void loop()
{
   findLine();
   motors.setSpeeds(driveSpeed, driveSpeed);
}


