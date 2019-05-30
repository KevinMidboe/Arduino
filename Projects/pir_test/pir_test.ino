
int ledPin = 13;
int inputPins[] = {2, 4};
bool pirState[] = {0, 0};
int val[] = {0, 0};

void setup() {
  delay(1500);
  pinMode(ledPin, OUTPUT);
  pinMode(inputPins[0], INPUT);
  pinMode(inputPins[1], INPUT);
  Serial.begin(9600);
}

void loop() 
{
  val[0] = digitalRead(inputPins[0]);
  val[1] = digitalRead(inputPins[1]);

  if (val[0] == 1)
  {
    if (checkState(1) == 1) {
      turnOn();
    }
  }
  else if (val[1] == 1)
  {
    if (checkState(0) == 1) {
      turnOn();
    }
  }
  
  Serial.println(val[0]);
  Serial.println(val[1]);
  Serial.println();
  delay(100);
}

void turnOn()
{
  digitalWrite(ledPin, HIGH);
  delay(3000);
  digitalWrite(ledPin, LOW);
}

int checkState(int sensorID)
{
  int changeState = 0;
  for (int i = 0; i < 10; i++)
  {
    if (digitalRead(inputPins[sensorID]) == 1) {
      changeState = 1;
    }
    delay(100);
  }
  
  return changeState;
}
