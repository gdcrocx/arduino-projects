#include <Servo.h>
#include <IRremote.h>
const int trigPin = 18;
const int echoPin = 19;
const double threshold = 10.00;
const double space = 20.00;
int arr_dist[36];
Servo head;
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results;
const int m1PinP = 14, m1PinN = 15, m2PinP = 16, m2PinN = 17;
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
  head.attach(9);
  head.write(90);
  Serial.println("Bot UP ! Head fixed at default");
  seek();
}
void loop()
{
  thinkr();
}
double dist() 
{
  double duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pinMode(echoPin,INPUT);
  //Serial.print(duration);
  duration = pulseIn(echoPin,HIGH);
  //Serial.print(duration);
  cm = microsecondsToCentimeters(duration);
  //Serial.print("Obstacle at    ");
  //Serial.print(cm);
  //Serial.println("cms");
  //Serial.println(cm);
  return cm;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}
int thinkr()
{
  int cm = dist();
  //Serial.println(cm);
  if(cm < threshold)  
  {
    Serial.print("Max free distance position : ");
    int freepos = seek();
    Serial.println(freepos);
  }
}
int seek()
{
  Serial.print("Head at ");
  Serial.println(head.read());
  delay(300);
  /*for(int i=0;i<36;i++)
  {
    arr_dist[i] = 0;
    Serial.println(arr_dist[i]);
  }
  delay(3000);
  if(head.read() == 90)
  {
    Serial.println("Head seeking");
    for(int pos=90; pos >=1; pos-=5)
    {
      head.write(pos); 
      arr_dist[pos/5] = dist();
      delay(20);
    }*/
    head.write(1);
    for(int pos=1; pos <=179; pos+=5)
    {
      head.write(pos); 
      arr_dist[pos/5] = dist();
      delay(20);
    }
    /*for(int pos=179; pos >=90; pos-=5)
    {
      head.write(pos);
      arr_dist[pos/5] = dist();
      delay(20);
    }*/
    head.write(90);
  //}
  for(int i=0;i<36;i++)
  {
    Serial.println(arr_dist[i]);
  }
  int maxd = arr_dist[0];
  int maxpos = 0;
  for (int i = 1; i < 36; i++)
  {
    if (arr_dist[i] > maxd)
    {
      maxd  = arr_dist[i];
      maxpos = i+1;
    }
  }
  return maxpos;
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

























