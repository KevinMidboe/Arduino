#include <Servo.h>

int relayPins[] = {4, 7, 6, 5};
int buttonPins[] = {8, 9, 10, 11, 12, 13};
int relayState[] = {0, 0, 0, 0};
int buttonState = 0;

Servo myservo;

void setup() {
  for (int i = 0; i < 6; i++)
  {
    if (i < 4)
    {
      pinMode(relayPins[i], OUTPUT);
    }
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  myservo.attach(3);
} 

void loop()  
{
  for (int i = 0; i < 6; i++)
  {
    buttonState = digitalRead(buttonPins[i]);
    if (buttonState == LOW)
    {
      switch (i)
      {
        case 4:
          //
          break;
        case 3:
          // Turn on the servo for speaker
          myservo.write(150);
          delay(1000);
          myservo.write(140);
          break;
        default:
          relayChange(i);
          break;
      }
    }
    while (buttonState == LOW)
    {
      delay(50);
      buttonState = digitalRead(buttonPins[i]);
    }
  }                   
}

void relayChange(int i)
{
  if (relayState[i] == 0)
  {
    digitalWrite(relayPins[i], HIGH);
    relayState[i] = 1;
  }
  else
  {
    digitalWrite(relayPins[i], LOW);
    relayState[i] = 0;
  }
}
