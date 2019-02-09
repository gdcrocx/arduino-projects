#include <IRremote.h>
int IRLed = 14;
int Indicator = 11;
int IRButton = 7;
void setup() {
  pinMode(IRLed,OUTPUT);
  pinMode(IRButton,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(IRButton)==0)
  {
    digitalWrite(IRLed,HIGH); 
    Serial.begin(9600);
    Serial.println("ON");
    digitalWrite(Indicator,HIGH);
    delay(300);
    Serial.end();
    digitalWrite(IRLed,LOW);
    digitalWrite(Indicator,LOW);
   }
}


