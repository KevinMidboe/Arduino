const int buttonPin0 = 0;

const int led = 13;

void setup() {
  pinMode(buttonPin0, INPUT);
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
if (analogRead(buttonPin0) == 0) {
  digitalWrite(led, HIGH);
}
else {
  digitalWrite(led, LOW);
}
  
  delay(1000);
}
