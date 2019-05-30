#include <SoftwareSerial.h>

// The serial connection to the GPS module
SoftwareSerial gpsSerial(4, 3);

void setup(){
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void loop(){
  while (gpsSerial.available()) {         // check for gps data 
    Serial.write(gpsSerial.read());
  }
}
