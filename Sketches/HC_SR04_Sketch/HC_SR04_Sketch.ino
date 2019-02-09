const int trigPin = 2;
const int echoPin = 3;
const double threshold = 1.5;
void setup() 
{
  Serial.begin(9600);
}

void loop() {
  double duration, inches, cm, feet;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pinMode(echoPin,INPUT);
  duration = pulseIn(echoPin,HIGH);

  inches =  microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  feet = inches / 12;
  Serial.print("Obstacle at    ");
  Serial.print(feet);
  Serial.print("feet   ---  ");
  Serial.print(inches);
  Serial.print("inches");
  Serial.println(" ---  ");
  Serial.print(cm);
  Serial.print("cms");
  Serial.println();
  digitalWrite(11,HIGH);
  beepr(feet);
  delay(200); 

}
long microsecondsToInches(long microseconds)
{
  return microseconds /74 /2;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}
int beepr(double dist)
{
  if(dist < threshold)
  {
    digitalWrite(12,HIGH);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(12,LOW);
    digitalWrite(5,LOW);
  } 
  else
  {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
  }
  return 0;
}


