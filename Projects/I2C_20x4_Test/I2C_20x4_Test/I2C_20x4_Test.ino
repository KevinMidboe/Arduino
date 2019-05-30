#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F
#define En_pin      2
#define Rw_pin      5
#define Rs_pin      4
#define D4_pin      0
#define D5_pin      1
#define D6_pin      6
#define D7_pin      7
#define BACKLIGHT_PIN   3

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin,
                      D4_pin, D5_pin, D6_pin, D7_pin);

void setup() {
    Serial.begin(9600);
    lcd.begin (20, 4);

    // Switch on the backlight
    lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
    lcd.setBacklight(HIGH);

    // Position cursor and write some text
    lcd.print("Poop in face");
}

void loop() {
  if (Serial.available()) {
    lcd.clear();
    lcd.home();
    while(Serial.available() > 0) {
      lcd.print(Serial.read());
      delay(1000);
    }
  }

}
