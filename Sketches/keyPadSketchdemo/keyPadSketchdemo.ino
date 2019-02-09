int Button[] = {
  7,8,9};
int LED[] = {
  11,12,13};
int statePIN;
int i;
const int pinCount = 3;
void setup()
{
  Serial.begin(9600);
  for(i=0;i<pinCount;i++)
  {
    pinMode(Button[i], INPUT_PULLUP);
    pinMode(LED[i], OUTPUT);
    digitalWrite(Button[i],HIGH); //Turn OFF
    digitalWrite(LED[i],LOW);     //LED OFF
  }
}
void loop()
{
  for(i=0;i<pinCount;i++)
  {
    statePIN = debounce(digitalRead(Button[i]));
    if(statePIN == 0)
    {
      digitalWrite(LED[i],HIGH);
      Serial.println(Button[i]);
      delay(10);
    }
    else
    {
      digitalWrite(LED[i],LOW);
      Serial.println('0');
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


















