void setup() 
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() 
{
  digitalWrite(11,HIGH);
  delay(600);
  digitalWrite(12,HIGH);
  delay(600);
  digitalWrite(13,HIGH);
  delay(600);
  digitalWrite(11,LOW);
  delay(600);
  digitalWrite(12,LOW);
  delay(600);
  digitalWrite(13,LOW);
  delay(600);

}

