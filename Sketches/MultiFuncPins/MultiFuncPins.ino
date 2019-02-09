#include <IRremote.h>
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results; 
void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  irrecv.enableIRIn();
}
void clickSwitch(int pinNumber)
{
  int state = digitalRead(pinNumber);
  Serial.println("prevState > " + String(state));
  if(state == 0)
    state = 1;
  else  state = 0;
  digitalWrite(pinNumber,state);
  Serial.println("switchedState > " + String(state));
}
void loop() 
{
  if (irrecv.decode(&results))
  {  
    Serial.begin(9600);
    if (results.value == 16724175)
    {
      Serial.println("Button 1 is pressed");
      clickSwitch(11);
    }
    else if (results.value == 16718055)
    {
      Serial.println("Button 2 is pressed");
      clickSwitch(12);
    }
    else if (results.value == 16743045)
    {
      Serial.println("Button 3 is pressed");
      clickSwitch(13);
    }
    else 
    { 
      Serial.println("IR Code not identified !! ");
      delay(300);
    }
    Serial.end();
    irrecv.resume(); 
  }
}











