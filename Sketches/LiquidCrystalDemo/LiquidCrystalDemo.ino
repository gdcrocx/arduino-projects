#include <LiquidCrystal.h>
LiquidCrystal lcd(19, 18, 17, 16, 15, 14);
void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World");
  //lcd.setCursor(1, 1);
  //lcd.print("How are you?");
}
void loop() {
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
}
