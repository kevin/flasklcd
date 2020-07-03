#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);

  lcd.print("hello, world!");

  Serial.begin(9600);
  Serial.setTimeout(10);

}

void loop() {

  

}

void serialEvent() {

  static String text;

  text = Serial.readString();

  String top = text.substring(0, text.indexOf("bottom:"));
  String bottom = text.substring(text.lastIndexOf("bottom:") + 7);

  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(top);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(bottom);
  
}
