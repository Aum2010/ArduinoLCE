#include <Wire.h> 
#define LED_Add 0x3B 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte customChar1[] = { //ฟ
  0x01,
  0x01,
  0x01,
  0x11,
  0x11,
  0x15,
  0x1B,
  0x11
};

byte customChar2[] = { //า
  0x00,
  0x00,
  0x0E,
  0x11,
  0x01,
  0x01,
  0x01,
  0x01
};

byte customChar3[] = { //ร์
  0x0E,
  0x08,
  0x1F,
  0x10,
  0x1E,
  0x02,
  0x02,
  0x06
};

byte customChar4[] = { //ม
  0x00,
  0x00,
  0x19,
  0x09,
  0x09,
  0x1D,
  0x1B,
  0x09
};

byte customChar5[] = { //ไ
  0x00,
  0x11,
  0x0B,
  0x05,
  0x01,
  0x01,
  0x01,
  0x01
};

byte customChar6[] = { //ก่
  0x02,
  0x02,
  0x00,
  0x0E,
  0x11,
  0x11,
  0x11,
  0x11
};

// Set the LCD address to 0x27 for a 16 chars and 2 line display
int k = 0; 
void setup()
{
   Wire.begin();
  lcd.begin();
  Serial.begin(9600);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  
  
}
void loop() {
   Wire.beginTransmission(LED_Add);
  Wire.write(0xAA);
  Wire.endTransmission();
  delay(500);
   Wire.beginTransmission(LED_Add);
  Wire.write(0x55);
  Wire.endTransmission();
  delay(500);
   for(int i=16;i>k;i--){

  for(int j=16;j>k;j--){
      lcd.setCursor(j-1,0);
      lcd.print(" ");
    }
    
      lcd.setCursor(i-2,0);
      //
      switch(k){
      case 1 : lcd.print("*"); break;
      case 2 : lcd.print("*"); break;
      case 3 : lcd.print("*") ; break;
 
      case 4 : lcd.print((char)1); break;
      case 5 : lcd.print((char)2); break;
      case 6 : lcd.print((char)3); break;
      case 7 : lcd.print((char)4); break;
      case 8 : lcd.print((char)5); break;
      case 9 : lcd.print((char)6); break;
  
     
      case 10 : lcd.print("*"); break;
      case 11 : lcd.print("*"); break;
      case 12 : lcd.print("*"); break;
      case 13 : lcd.print("*"); break;
      case 14 : lcd.print("*"); break;
      case 15 : lcd.print("*"); break;
      }
      //
      delay(50);
   
   }
    lcd.setCursor(k-1,0);
    //
     switch(k){
      case 1 : lcd.print("*"); break;
      case 2 : lcd.print("*"); break;
      case 3 : lcd.print("*"); break;
      
     case 4 : lcd.print((char)1); break;
      case 5 : lcd.print((char)2); break;
      case 6 : lcd.print((char)3); break;
      case 7 : lcd.print((char)4); break;
      case 8 : lcd.print((char)5); break;
      case 9 : lcd.print((char)6); break;
      case 10 : lcd.print("*"); break;
      case 11 : lcd.print("*"); break;
      case 12 : lcd.print("*"); break;
      case 13 : lcd.print("*"); break;
      case 14 : lcd.print("*"); break;
      case 15 : lcd.print("*"); break;
      }
    //
    k++;
    if(k==16){k=0;}

    

}
