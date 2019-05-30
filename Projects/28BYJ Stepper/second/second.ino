
int leftCCW[] = {8, 9, 10, 11};
int leftCW[] = {11, 10, 9, 8};
int leftButtons[] = {0, 1};

int rightCCW[] = {4, 5, 6, 7};
int rightCW[] = {7, 6, 5, 4};
int rightButtons[] = {2, 3};

const int motorSteps[8][4] = {
{1, 0, 0, 0},
{1, 1, 0, 0},
{0, 1, 0, 0},
{0, 1, 1, 0},
{0, 0, 0, 1},
{0, 0, 1, 1},
{0, 0, 0, 1},
{1, 0, 0, 1}
};

int motorSpeed = 0;

void setup()
{
for (int i=0; i < 4; i++) {
pinMode(leftCW[i], OUTPUT);
pinMode(rightCW[i], OUTPUT);
}
for (int i = 0; i < 2; i++) {
pinMode(leftButtons[i], INPUT);
pinMode(rightButtons[i], INPUT);
}

pinMode(12, INPUT);

Serial.begin(9600);
}

void loop()
{
if (digitalRead(12) == LOW)
{ windUp();	}
else { windDown(); }
}

void windUp() {
  while(digitalRead(rightButtons[1]) == LOW || digitalRead(leftButtons[1] == LOW)){
    if (digitalRead(rightButtons[1] == LOW))
    {
      for(int i=0; i < 8; i++){
        for(int j=0; j < 4; j++){
          // Right motor
          digitalWrite(rightCCW[j], motorSteps[j][i]);
          delay(1);
          }
        } 
    }
    
    if (digitalRead(leftButtons[1] == LOW))
    {
      for(int i=0; i < 8; i++){
        for(int j=0; j < 4; j++){
          // Left motor
          digitalWrite(leftCW[j], motorSteps[j][i]);
          delay(1);
        }
      } 
    }
  }
}

void windDown() {
  while(digitalRead(rightButtons[0]) == LOW || digitalRead(leftButtons[0] == LOW)){
    if (digitalRead(rightButtons[0] == LOW)) {
      for(int i=0; i < 8; i++){
        for(int j=0; j < 4; j++){
          // Right motor
          digitalWrite(rightCW[j], motorSteps[j][i]);
          delay(1);
    	}
      } 
    }
    
    if (digitalRead(leftButtons[0] == LOW)) {
    	for(int i=0; i < 8; i++){
          for(int j=0; j < 4; j++){
            // Left motor
            digitalWrite(leftCCW[j], motorSteps[j][i]);
            delay(1);
          }
        } 
    }
  }

}
