int Button[] = {
  0,1,2,3,4,5,6,7,8,9}; //PINS 0-9 on the Arduino
int LED = 13; //LED Indicator
int statePIN; //State of the PINs chceked in FOR Loop
int i; //Incrementor
const int pinCount = 10; //Total Count of PINs for FOR loop
void setup()
{
  for(i=0;i<pinCount;i++)
  {
    pinMode(Button[i], INPUT_PULLUP);
    digitalWrite(Button[i],HIGH); //Turn OFF
  }
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);     //LED OFF
  Serial.begin(9600);
}
void loop()
{
  for(i=0;i<pinCount;i++)
  {
    statePIN = debounce(digitalRead(Button[i]));
    if(statePIN == 0)
    {
      digitalWrite(LED,HIGH);
      Serial.write(Button[i]+1);
      Serial.println(Button[i]+1);
    }
    else
    {
      digitalWrite(LED,LOW);
      //Serial.println(i);
    }
  }
}
boolean debounce(boolean last)
{
  boolean current = digitalRead(Button[i]);
  if(last != current)
  {
    delay(5);
    current = digitalRead(Button[i]);
  }
  return current;
}



















