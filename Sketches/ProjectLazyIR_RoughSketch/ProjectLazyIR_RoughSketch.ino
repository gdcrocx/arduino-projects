/*
RS     : Pin 10 Black
 E      : Pin 9 Blue
 D4     : Pin 2 Red
 D5     : Pin 4 Yellow
 D6     : Pin 7 Blue
 D7 `   : Pin 8 Orange
 
 Red    : Pin 5 RGB LED
 Blue   : Pin 6 RGB LED
 Green  : Pin 3 RGB LED
 
 Indicator RED   : Pin 11
 Indicator BLUE  : Pin 12
 Indicator WHITE : Pin 13
 
 Ground : Pin 14
 RES    : Pin 15
 RX     : Pin 0
 TX     : Pin 1
 */
#include<LiquidCrystal.h>
#include <IRremote.h>  
LiquidCrystal lcd(10,9,2,4,7,8);
int ledPin11 = 11;
int ledPin12 = 12;
int ledPin13 = 13;
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results; 
void setup() 
{
lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO      ");
  delay(1550);
  lcd.setCursor(0,1);
  lcd.print("HOME AUTOMATION ");
  delay(1500);
  lcd.clear();
  delay(500);
  pinMode(ledPin11,OUTPUT);
  pinMode(ledPin12,OUTPUT);
  pinMode(ledPin13,OUTPUT);
  //Setting RGB LED to Zero
  analogWrite(5,0);
  analogWrite(6,0);
  delay(100);
  lcd.print("Please Wait !!");
  //Setting RGB LED to RED and others to Zero
  analogWrite(5,255);
  delay(500);
  //Setting RGB LED to BLUE and others to Zero
  analogWrite(5,0);
  analogWrite(6,255);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  //Setting RGB LED to RED and others to Zero
  analogWrite(6,0);
  analogWrite(5,255);
  delay(500);
  //Setting RGB LED to BLUE and others to Zero
  analogWrite(5,0);
  analogWrite(6,255);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  //Setting RGB LED to RED and others to Zero
  analogWrite(6,0);
  analogWrite(5,255);
  delay(500);
  //Setting RGB LED to BLUE and others to Zero
  analogWrite(5,0);
  analogWrite(6,255);
  lcd.clear();
  delay(500);
  //Setting RGB LED to Zero
  analogWrite(5,0);
  analogWrite(6,0);
  delay(200);
  //Setting RGB LED to Green
  lcd.clear();
  lcd.print("Ready !!");
  analogWrite(3,255);
  delay(200);
  analogWrite(3,0);
  lcd.noDisplay();
  delay(200);
  //Setting RGB LED to Green
  lcd.display();
  analogWrite(3,255);
  delay(200);
  analogWrite(3,0);
  lcd.noDisplay();
  delay(200);
  //Setting RGB LED to Green
  lcd.display();
  analogWrite(3,255);
  delay(200);
  analogWrite(3,0);
  //Light Blinking Over
  pinMode(7,INPUT);		// Declare the 7th pin as a input pin. We will use the button on the 7th pin  
  digitalWrite(7,HIGH);  
  irrecv.enableIRIn(); 		// Start the Remote receiver  
  Serial.begin(9600);
}
void blinks()
{
     digitalWrite(11,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(13,HIGH);
     delay(35);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
     delay(35);
     digitalWrite(11,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(13,HIGH);
     delay(35);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
     delay(35);
     digitalWrite(11,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(13,HIGH);
     delay(35);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
     delay(35);
}
void wait()
{
  while(digitalRead(7)==0);  // wait till button is released to avoid incrementing the counter again  
  delay(300);         // small delay to avoid debounce  
  irrecv.resume(); // Receive the next value
}
void clickSwitch(state)
{
  if(state == 0)
    state =1;
  else state = 0;
}
void loop() 
{
  if (irrecv.decode(&results))
 {  
   //Serial.println(results.value); 
   if (results.value == 16724175)
   {
     Serial.println("Button 1 is pressed");
     blinks();
     wait();
   }
   else if (results.value == 16718055)
   {
     Serial.println("Button 2 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16743045)
   {
     Serial.println("Button 3 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16716015)
   {
     Serial.println("Button 4 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16726215)
   {
     Serial.println("Button 5 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16734885)
   {
     Serial.println("Button 6 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16728765)
   {
     Serial.println("Button 7 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16730805)
   {
     Serial.println("Button 8 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16732845)
   {
     Serial.println("Button 9 is pressed");
     blinks();
     wait();
   }
    else if (results.value == 16756815)
   {
     Serial.println("Button 0 is pressed");
     blinks();
     wait();
   }
   else 
   { 
     Serial.println("Command not identified !! ");
     blinks();
     wait();
   }
 }
  else
 {
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
 }
Serial.end();
}




