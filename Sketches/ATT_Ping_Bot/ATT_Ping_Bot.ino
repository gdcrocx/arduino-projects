/*      ____
 ____ |head| ____
 | M1 |      | M2 |
 ----  ____  ----      
 L   |tail|    R
 ----
 
 Pin2 - Motor 1 Positive
 Pin3 - Motor 1 Negative
 Pin4 - Motor 2 Positive
 Pin5 - Motor 2 Negative
 */
const int trigPin = 1;
const int echoPin = 5;
const double threshold = 10.00;
const int m1PinP = 2, m1PinN = 3, m2PinP = 6, m2PinN = 7;
void setup()
{
  pinMode(m1PinP,OUTPUT);
  pinMode(m1PinN,OUTPUT);
  pinMode(m2PinP,OUTPUT);
  pinMode(m2PinN,OUTPUT);
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
  beepr(cm);
  delay(200); 
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}
int beepr(double dist)
{
  if(dist < threshold)
  {
    turn_left();
  } 
  else
  {
    forward();
  }
  return 0;
}
void turn_left()
{ 
  digitalWrite(m1PinP,LOW);
  digitalWrite(m1PinN,HIGH);
  digitalWrite(m2PinP,HIGH);
  digitalWrite(m2PinN,LOW);
}
void turn_right()
{ 
  digitalWrite(m1PinP,HIGH);
  digitalWrite(m1PinN,LOW);
  digitalWrite(m2PinP,LOW);
  digitalWrite(m2PinN,HIGH);
}
void reverse() 
{
  digitalWrite(m1PinP,LOW);
  digitalWrite(m1PinN,HIGH);
  digitalWrite(m2PinP,LOW);
  digitalWrite(m2PinN,HIGH);
}
void forward() 
{
  digitalWrite(m1PinP,HIGH);
  digitalWrite(m1PinN,LOW);
  digitalWrite(m2PinP,HIGH);
  digitalWrite(m2PinN,LOW);
}









