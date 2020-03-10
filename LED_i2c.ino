#define LED_Add 0x3B 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  
  }

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(LED_Add);
  Wire.write(0xAA);
  Wire.endTransmission();
  delay(500);
  Wire.beginTransmission(LED_Add);
  Wire.write(0x55);
  Wire.endTransmission();
  delay(500);
}
