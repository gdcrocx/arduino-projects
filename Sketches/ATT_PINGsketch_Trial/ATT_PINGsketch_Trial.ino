const int trigPin = 2;
const int echoPin = 3;
//const double threshold = 10.00;
void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
}
void loop()
{
  double duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pinMode(echoPin,INPUT);
  duration = pulseIn(echoPin,HIGH);
  cm = microsecondsToCentimeters(duration);
  if(cm<10)
  {
    digitalWrite(6,HIGH);
  }
  else
  {
    digitalWrite(6,LOW);
  }
  delay(200); 
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}


