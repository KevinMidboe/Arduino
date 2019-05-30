#include <SPI.h> // needed in Arduino 0019 or later
#include <Ethernet.h>
#include <Twitter.h>
#include <Time.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0xA7, 0x51 };
//byte ip[] = {192, 168, 0, 105}; 

char buf[100];

Twitter twitter("2307428619-TIM5H7Lh6L9HrrQLMynR5cinWpNbiUTt2827myM");

int i = 0;
int buttonPin = 3;

String stringKevin = String("@KevinMidboe");
String stringVannFerdig = String(" Vannet er ferdig! 0");

void setup()
{
  delay(1000);
  Ethernet.begin(mac);
  Serial.begin(9600); 
}
/*
void tweet(String msg[]) {
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}*/

void loop()
{
 if (analogRead(buttonPin) != 0) 
 {
   i++;
   stringKevin += stringVannFerdig;
    stringKevin += seconds();
    char charBuf[50];
    stringKevin.toCharArray(charBuf, 50);
    twitter.post(charBuf);
    
    // zero delay
    delay(1000);
  }
}
