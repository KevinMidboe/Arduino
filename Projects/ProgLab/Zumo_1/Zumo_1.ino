#include <PLab_ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>

ZumoReflectanceSensorArray reflectanceSensors;
unsigned int sensor_values[6];
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
int lastError = 0;

const int MAX_SPEED = 800;
// Set constants for PID control
const float KP = 0.5;  // Proportional constant
const float KD = 6;    // Derivative constant
const int SV = 2500; // Set-value for position (in the middle of sensors)

unsigned long Timer;   //"ALWAYS use unsigned long for timers, not int"

void setup()
{
  Serial.begin(9600);
  reflectanceSensors.init();
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  button.waitForButton();
  for(int i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motors.setSpeeds(-200, 200);
    else
      motors.setSpeeds(200, -200);
      
    reflectanceSensors.calibrate();

    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motors.setSpeeds(0, 0);
  button.waitForButton();

  digitalWrite(13, LOW);
}

void loop()
{
  reflectanceSensors.read(sensor_values);
  if (sensor_values[5] < 1800)
  {
    motors.setSpeeds(-100, -100);
    delay(1000);
    motors.setSpeeds(-100, 100);
    delay(1000);
  }
  else if (sensor_values[0] < 1800)
  {
    motors.setSpeeds(-100, -100);
    delay(1000);
    motors.setSpeeds(100, -100);
    delay(1000);
  }
  else
  {
    motors.setSpeeds(100, 100);
  }
  
  int pv = reflectanceSensors.readLine(sensor_values);
  // Our "error" is how far we are away from the center of the line, which
  // corresponds to position 2500.
  int error = pv - SV; 
  // do PD computation ( Integral is not used)
  int speedDifference = KP*error + KD * (error - lastError);
  
  
  //Serial.println(error);
  lastError = error;

  // Get individual motor speeds.  The sign of speedDifference
  // determines if the robot turns left or right.
  int m1Speed = MAX_SPEED + speedDifference;
  int m2Speed = MAX_SPEED - speedDifference;

  

  motors.setSpeeds(m1Speed, m2Speed);
}
