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
     Keyboard.press((char) 0x80);
     Keyboard.press((char) 0x20);
     Keyboard.releaseAll();
     delay(100);
     Keyboard.print("Sleep");
     Keyboard.write((char) 0xB0);
     delay(500);
   }
 }

