void setup() 
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() 
{
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  delay(6000);
}

