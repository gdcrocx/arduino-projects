#include <IRremote.h>
int ledPin11 = 11;
int ledPin12 = 12;
int ledPin13 = 13;
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results; 
void setup() 
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  irrecv.enableIRIn(); 		
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
int clickSwitch(int pinNumber)
{
  int state = digitalRead(pinNumber);
  Serial.println("prevState > " + String(state));
  if(state == 0)
    state =1;
  else state = 0;
  digitalWrite(pinNumber,state);
  Serial.println("switchedState > " + String(state));
  return state;
}
void loop() 
{
  if (irrecv.decode(&results))
  {  
    digitalWrite(11,HIGH);
    delay(800);
    Serial.begin(9600);
    if (results.value == 16724175)
    {
      Serial.println("Button 1 is pressed");
      blinks();
      clickSwitch(4);
    }
    else if (results.value == 16718055)
    {
      Serial.println("Button 2 is pressed");
      blinks();
      clickSwitch(5);
    }
    else if (results.value == 16743045)
    {
      Serial.println("Button 3 is pressed");
      blinks();
      clickSwitch(6);
    }
    else 
    { 
      Serial.println("IR Code not identified !! ");
      delay(300);
      blinks();
    }
    Serial.end();
    irrecv.resume(); 
  }
  else
  {
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
  }
}










