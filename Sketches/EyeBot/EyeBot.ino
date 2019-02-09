#include <IRremote.h>
const int trigPin = 18;
const int echoPin = 19;
const double threshold = 10.00;
const double space = 20.00;
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results;
const int m1PinP = 8, m1PinN = 10, m2PinP = 16, m2PinN = 17;
void setup() 
{
  irrecv.enableIRIn();
  delay(1000);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(m1PinP,OUTPUT);
  pinMode(m1PinN,OUTPUT);
  pinMode(m2PinP,OUTPUT);
  pinMode(m2PinN,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  double duration, cm;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print("Obstacle at    ");
  Serial.print(cm);
  Serial.println("cms");
  digitalWrite(11,HIGH); //Burns all the time
  beepr(cm);
  delay(200); 
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}
int beepr(double dist)
{
  Serial.println(dist);
  if(dist < threshold)  
  {
    reverse();
    delay(200);
    pwr_off();
  }
  else if(dist > space)
  {
    while(irrecv.decode(&results)) 
    {
      long int input = results.value;
      Serial.println(input);
      switch(input)
      {
      case 16718055:
        Serial.println("Vehicle moving forward");
        if(input == 16718055)
        {
          forward();
        }
        break;
      case 16716015:
        Serial.println("Vehicle turning left");
        if(input == 16716015)
        {
          turn_left();
        }
        break;
      case 16734885:
        Serial.println("Vehicle turning right");
        if(input == 16734885)
        {
          turn_right();
        }
        break;
      case 16730805:
        Serial.println("Vehicle in reverse");
        if(input == 16730805)
        {
          reverse();
        }
        break;
      case 16726215:
        pwr_off();
        break;
      default:
        Serial.println("Invalid Input");
      } // EOSwitchloop
      irrecv.resume(); 
    } // EOWhile loop 
  }
  return 0;
  delay(3000); 
}
void turn_right()
{ 
  Serial.println("Progressing leftTurn Operation");
  digitalWrite(m1PinP,LOW);
  digitalWrite(m1PinN,HIGH);
  digitalWrite(m2PinP,HIGH);
  digitalWrite(m2PinN,LOW);
  digitalWrite(11,HIGH);
  delay(300);
  digitalWrite(11,LOW);
}
void turn_left()
{ 
  Serial.println("Progressing rightTurn Operation");
  digitalWrite(m1PinP,HIGH);
  digitalWrite(m1PinN,LOW);
  digitalWrite(m2PinP,LOW);
  digitalWrite(m2PinN,HIGH);
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(13,LOW);
}
void forward() 
{
  Serial.println("Progressing forward Operation");
  digitalWrite(m1PinP,LOW);
  digitalWrite(m1PinN,HIGH);
  digitalWrite(m2PinP,LOW);
  digitalWrite(m2PinN,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
void reverse() 
{
  Serial.println("Progressing reverse Operation");
  digitalWrite(m1PinP,HIGH);
  digitalWrite(m1PinN,LOW);
  digitalWrite(m2PinP,HIGH);
  digitalWrite(m2PinN,LOW);
  digitalWrite(12,HIGH);
  delay(300);
  digitalWrite(12,LOW);
}
void pwr_off()
{
  Serial.println("Decceleration Operation");
  digitalWrite(m1PinP,LOW);
  digitalWrite(m1PinN,LOW);
  digitalWrite(m2PinP,LOW);
  digitalWrite(m2PinN,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}















