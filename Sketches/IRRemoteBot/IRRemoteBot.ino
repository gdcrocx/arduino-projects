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
#include <IRremote.h>
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results;
const int m1PinP = 2,m1PinN = 3,m2PinP = 4,m2PinN = 5;
void setup()
{
  irrecv.enableIRIn();
  delay(1000);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(m1PinP,OUTPUT);
  pinMode(m1PinN,OUTPUT);
  pinMode(m2PinP,OUTPUT);
  pinMode(m2PinN,OUTPUT);
  Serial.begin(9600);
}
void loop()
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
    case 16753245:
      pwr_off();
      break;
    default:
      Serial.println("Invalid Input");
    } // EOSwitchloop
    irrecv.resume(); 
  } // EOWhile loop
}
void turn_right()
{ 
  Serial.println("Progressing rightTurn Operation");
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
  Serial.println("Progressing leftTurn Operation");
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












