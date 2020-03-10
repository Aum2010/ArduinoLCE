#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int k = 16; 
void setup()
{
  // initialize the LCD
  lcd.begin();
  Serial.begin(9600);
  // Turn on the blacklight and print a message.
  //lcd.backlight();
  //lcd.print("Hello, world!");
}

void loop() {
   for(int i=0;i<k;i++){
    
    for(int j=0;j<k;j++){
      lcd.setCursor(j,0);
      lcd.print(" ");
    }
    
    lcd.setCursor(i,0);
    switch(i){
      case 1 : lcd.print("A"); break;
      case 2 : lcd.print("B"); break;
      case 3 : lcd.print("C"); break;
      case 4 : lcd.print("D"); break;
      case 5 : lcd.print("E"); break;
      case 6 : lcd.print("F"); break;
      case 7 : lcd.print("G"); break;
      case 8 : lcd.print("H"); break;
      
    }
    
    delay(100);
    
    Serial.println(k);
    
   
   }

    lcd.setCursor(k,0);
    lcd.print("H");
    k--;
    if(k==0){k=16;}

}
