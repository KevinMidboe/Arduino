 const int buttonPin = 4;
 int buttonState = LOW;
 
 void setup() 
 {
   pinMode(buttonPin, LOW);
   Keyboard.begin();
 }
 
 void loop()
 {
   int buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH)
   {
     Keyboard.write((char) 0xB0);
     delay(500);    
     Keyboard.print("Kevinojm");
     Keyboard.write((char) 0xB0);
     delay(500);
   }
 }

