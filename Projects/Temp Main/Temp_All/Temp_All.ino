
int temperaturePin = 0;
const int buttonPin = 0;

int secondDisplayState = HIGH;
const boolean ON = HIGH;
const boolean OFF = LOW;
int buttonState, Avrund;

int firstDisplay[] = {10, 9, 8, 7, 6, 5, 4};

int data = 11;
int latch = 12;
int clock = 13;

byte firstNumber[10][7] = {
{ON, ON, ON, OFF, ON, ON, ON}, // 0
{ON, OFF, OFF, OFF, OFF, OFF, ON}, // 1
{OFF, ON, ON, ON, OFF, ON, ON}, // 2
{ON, ON, OFF, ON, OFF, ON, ON}, // 3
{ON, OFF, OFF, ON, ON, OFF, ON}, // 4
{ON, ON, OFF, ON, ON, ON, OFF}, // 5
{ON, ON, ON, ON, ON, ON, OFF}, // 6
{ON, OFF, OFF, OFF, OFF, ON, ON}, // 7
{ON, ON, ON, ON, ON, ON, ON}, // 8
{ON, ON, OFF, ON, ON, ON, ON}};  // 9

byte secondNumber[5][7] = {
{OFF, ON, ON, ON, ON, ON, ON}, // 0
{OFF, OFF, OFF, ON, OFF, OFF, ON}, // 1
{ON, ON, ON, OFF, OFF, ON, ON}, // 2
{ON, ON, OFF, ON, OFF, ON, ON}, // 3
{ON, OFF, OFF, ON, ON, OFF, ON}}; // 4
void setup()
{
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
  
  for (int i = 0; i < 7; i++)
  {
    pinMode(firstDisplay[i], OUTPUT);
  }
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);  
  pinMode(latch, OUTPUT);
}
void loop()
{
  Avrund = 0;
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    float temperature = getVoltage(temperaturePin);
    temperature = (temperature - .5) * 100;

    Serial.print(temperature); 
    Serial.println(" Celsius");
    
    temperature = temperature * 10;
    int intConvertedTemp = (int) temperature;
    String stringConvertedTemp = (String) intConvertedTemp;
    
    for (int i = 0; i < 10; i++)
    {
      if (stringConvertedTemp.substring(0,1) == (String) i)
      {
        for (int j = 0; j < 7; j++)
        {
          changeThe7Segments(j, secondNumber[i][j]);
        }
      }
      if (stringConvertedTemp.substring(2,3) > "5")
      {
        Avrund = 1;
      }
      if (stringConvertedTemp.substring(1,2) == (String) i)
      {
        for (int j = 0; j < 7; j++)
        {
          digitalWrite(firstDisplay[j], firstNumber[i + Avrund][j]);
        }
      }
    } 
    delay(1250);
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(firstDisplay[i], OFF);
      changeThe7Segments(i, OFF);
    }
  }
}
float getVoltage(int pin)
{
   return (analogRead(pin) * .004882814);
}
void updateSecondDisplay(int value)
{
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, value);
  digitalWrite(latch, HIGH);
}
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};

 void changeThe7Segments(int led, int state)
 {
   secondDisplayState = secondDisplayState & masks[led];
   if(state == ON)
   {
     secondDisplayState = secondDisplayState | bits[led];
   } 
   updateSecondDisplay(secondDisplayState);
 }
