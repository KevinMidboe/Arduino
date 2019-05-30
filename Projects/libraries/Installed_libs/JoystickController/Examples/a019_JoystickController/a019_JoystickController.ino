#include "JoystickController.h"

JoystickController controller;

void setup(){
  Serial.begin(9600);
}

void loop(){
  controller.update();
  
  if (controller.selectButtonPressed()){
    Serial.println("S"); 
  }
  
  if (controller.upButtonPressed()){
    Serial.println("U"); 
  }
  
  if (controller.downButtonPressed()){
    Serial.println("D"); 
  }
  
  if (controller.leftButtonPressed()){
    Serial.println("L"); 
  }
  
  if (controller.rightButtonPressed()){
    Serial.println("R"); 
  }
  
  int direct = controller.getDirection();
  
  switch (direct){
    case  JoystickController::DIRECTION_UP:
      Serial.println("UP");
      break;
    case  JoystickController::DIRECTION_UP_RIGHT:
      Serial.println("UP-RIGHT");
      break;
    case  JoystickController::DIRECTION_RIGHT:
      Serial.println("RIGHT");
      break;
    case  JoystickController::DIRECTION_DOWN_RIGHT:
      Serial.println("DOWN-RIGHT");
      break;
    case  JoystickController::DIRECTION_DOWN:
      Serial.println("DOWN");
      break;
    case  JoystickController::DIRECTION_DOWN_LEFT:
      Serial.println("DOWN-LEFT");
      break;
    case  JoystickController::DIRECTION_LEFT:
      Serial.println("LEFT");
      break;
    case  JoystickController::DIRECTION_UP_LEFT:
      Serial.println("UP-LEFT");
      break;
  }
  
  delay(100);
}
