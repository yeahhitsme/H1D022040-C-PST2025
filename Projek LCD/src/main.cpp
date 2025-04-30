#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D4;
int SCL_pin = D3;
LiquidCrystal_I2C lcd(0x27,26,2);

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DEWIIII REBAHKAN SEMUA LETIHMU PADAMKAN API KECILMU SEJENAK TERLELAP DALAM MIMPIMU HINGGA PAGI MENJEMPUTMU");
}

void loop() {
  
  
  delay(300);
}
