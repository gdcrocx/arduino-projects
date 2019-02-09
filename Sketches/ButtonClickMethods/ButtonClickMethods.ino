int temp = 0;
int pin1 = 5;
int pin2 = 6;
int led = 13;
void setup()
{
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
  clickRelease();
}
void clickHold()
{
  if (digitalRead(pin1) == HIGH)
  {
    digitalWrite(led, HIGH);
    temp++;
  }
  else
  {
    digitalWrite(led, LOW);
  }
  Serial.println(temp);
}
void clickRelease()
{
  do
  {
    digitalWrite(led, HIGH);
    temp++;
    Serial.println(temp);
  } while (digitalRead(pin2) == LOW);
  digitalWrite(led, LOW);
}
void loop()
{
  clickHold();
}
