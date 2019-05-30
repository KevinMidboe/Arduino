#include "Arduino.h"
#include "JoystickController.h"

enum PINS{
  PIN_ANALOG_X       = 0,
  PIN_ANALOG_Y       = 1,
  PIN_BUTTON_SELECT  = 2,
  PIN_BUTTON_UP      = 4,
  PIN_BUTTON_DOWN    = 5,
  PIN_BUTTON_LEFT    = 6,
  PIN_BUTTON_RIGHT   = 3
};

JoystickController::JoystickController(int low, int high){
  _threshouldLow = low;
  _threshouldHigh = high;
  this->_setup();
}

void JoystickController::update(){
  this->_reset();
  this->_updateDirection();
  this->_updateButtons();
}

int JoystickController::getDirection(){
  return _direction; 
}

bool JoystickController::selectButtonPressed(){
  return _selectButtonPressed;
}

bool JoystickController::upButtonPressed(){
  return _upButtonPressed;
}

bool JoystickController::downButtonPressed(){
  return _downButtonPressed;
}

bool JoystickController::leftButtonPressed(){
  return _leftButtonPressed;
}

bool JoystickController::rightButtonPressed(){
  return _rightButtonPressed;
}

/**
 * Protected.
 */
void JoystickController::_reset(){
  _direction = DIRECTION_NONE;
  _selectButtonPressed = false;
  _upButtonPressed     = false;
  _downButtonPressed   = false;
  _leftButtonPressed   = false;
  _rightButtonPressed  = false; 
}

/**
 * Protected.
 */
void JoystickController::_setup(){
  pinMode(PIN_BUTTON_SELECT, INPUT);
  digitalWrite(PIN_BUTTON_SELECT, HIGH);
  
  pinMode(PIN_BUTTON_UP, INPUT);
  digitalWrite(PIN_BUTTON_UP, HIGH);
  
  pinMode(PIN_BUTTON_DOWN, INPUT);
  digitalWrite(PIN_BUTTON_DOWN, HIGH);
  
  pinMode(PIN_BUTTON_LEFT, INPUT);
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
  
  pinMode(PIN_BUTTON_RIGHT, INPUT);
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
  
  this->_reset();
}

/**
 * Protected.
 */
void JoystickController::_updateDirection(){
  const int NONE     = 0;
  const int POSITIVE = 1;
  const int NEGATIVE = -1;
  
  int x = analogRead(PIN_ANALOG_X);
  int y = analogRead(PIN_ANALOG_Y);
  
  int directX = NONE;
  int directY = NONE;
  
  if (x < _threshouldLow){
    directX = NEGATIVE;
  }
  
  if (x > _threshouldHigh){
    directX = POSITIVE;
  }
  
  if (y < _threshouldLow){
    directY = NEGATIVE;
  }
  
  if (y > _threshouldHigh){
    directY = POSITIVE;
  }
  
  if (directX == NONE){
    if (directY == POSITIVE){
      _direction = DIRECTION_UP;
    }
    if (directY == NEGATIVE){
      _direction = DIRECTION_DOWN;
    }
  }
  
  if (directX == POSITIVE){
    if (directY == NONE){
      _direction = DIRECTION_RIGHT;
    }
    if (directY == POSITIVE){
      _direction = DIRECTION_UP_RIGHT;
    }
    if (directY == NEGATIVE){
      _direction = DIRECTION_DOWN_RIGHT;
    }
  }
  
  if (directX == NEGATIVE){
    if (directY == NONE){
      _direction = DIRECTION_LEFT;
    }
    if (directY == POSITIVE){
      _direction = DIRECTION_UP_LEFT;
    }
    if (directY == NEGATIVE){
      _direction = DIRECTION_DOWN_LEFT;
    }
  }
}

/**
 * Protected.
 */
void JoystickController::_updateButtons(){
  int S = digitalRead(PIN_BUTTON_SELECT);
  int U = digitalRead(PIN_BUTTON_UP);
  int D = digitalRead(PIN_BUTTON_DOWN);
  int L = digitalRead(PIN_BUTTON_LEFT);
  int R = digitalRead(PIN_BUTTON_RIGHT);
  
  if (this->_buttonPressed(S)){
    _selectButtonPressed = true;
  }
    
  if (this->_buttonPressed(U)){
    _upButtonPressed = true;
  }
    
  if (this->_buttonPressed(D)){
    _downButtonPressed = true;
  }
    
  if (this->_buttonPressed(L)){
    _leftButtonPressed = true;
  }
    
  if (this->_buttonPressed(R)){
    _rightButtonPressed = true;
  }
}

/**
 * Protected.
 */
bool JoystickController::_buttonPressed(int state){
  return (state == LOW); 
}
