/*  fmP - HIGH fmN - LOW --> FORWARD
    fmP - LOW fmN - HIGH --> REVERSE
    rmP - HIGH rmN - LOW --> LEFT
    rmP - LOW rmN - HIGH --> RIGHT
*/
#include <Servo.h>
#include <IRremote.h>
const int trigPin = 18;
const int echoPin = 19;
const int redPin = 5;
const int greenPin = 3;
const int bluePin = 6;
const double threshold = 10.00,space = 20.00, revspace = 45.00;
const int seekIncrement = 30;
const int seekPos = (180 / seekIncrement);
int arr_dist[seekPos];
Servo head;
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results;
const int fm1PinP = 14, fm1PinN = 15, rm2PinP = 16, rm2PinN = 17;

void setup() 
{
  irrecv.enableIRIn();
  delay(1000);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(fm1PinP,OUTPUT);
  pinMode(fm1PinN,OUTPUT);
  pinMode(rm2PinP,OUTPUT);
  pinMode(rm2PinN,OUTPUT);
  Serial.begin(9600);
  head.attach(9); //Servo attached to PIN 9 on InduinoX
  head.write(90);
  red();
  green();
  blue();
  yellow();
  cyan();
  magenta();
  noColor();
  Serial.println("Bot UP ! Head fixed at default (90deg");
}
void loop()
{
  thinkr();
}
int thinkr()
{
  int cm = dist();
  Serial.println();
  Serial.print("Available Distance measurement - ");
  Serial.println(cm);
  delay(300);
  if(cm < threshold)  
  {
    int freepos = seek();
    noColor();
    Serial.print("Max free distance position : ");
    Serial.println(freepos);
    if(freepos > (seekPos/2))
    {
      turn_right();
      Serial.println("Made right turn");
      noColor();
      delay(4000);
    }
    else if(freepos < (seekPos/2))
    {
      turn_left();
      Serial.println("Made left turn");
      noColor();
      delay(4000);
    }
  }
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
  duration = pulseIn(echoPin,HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print("Obstacle at    ");
  Serial.print(cm);
  Serial.println("cms");  
  return cm;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}
int seek()
{
  /*Serial.println();
  Serial.print("Head at ");
  Serial.println(head.read());
  delay(300);*/
  head.write(1);
  for(int pos=1; pos <=179; pos+=seekIncrement)
  {
    head.write(pos); 
    arr_dist[pos/seekIncrement] = dist();
    blue();
    delay(500);      
  }
  head.write(90);  
  //for(int i=0; i <= seekPos; i++)
  //{
  //  Serial.println(arr_dist[i]);
  //}
  int maxd = arr_dist[0];
  int maxpos = 0;
  for (int i = 0; i <= seekPos; i++)
  {
    if (arr_dist[i] > maxd)
    {
      maxd  = arr_dist[i];
      maxpos = i+1;
    }
  }
  return maxpos;
  delay(1000);
}
void turn_left()
{ 
  Serial.println("Progressing leftTurn Operation");
  digitalWrite(fm1PinP,LOW);
  digitalWrite(fm1PinN,HIGH);
  digitalWrite(rm2PinP,HIGH);
  digitalWrite(rm2PinN,LOW);
  yellow();
  digitalWrite(11,HIGH);
  delay(3000);
  digitalWrite(11,LOW);
}
void turn_right()
{ 
  Serial.println("Progressing rightTurn Operation");
  digitalWrite(fm1PinP,HIGH);
  digitalWrite(fm1PinN,LOW);
  digitalWrite(rm2PinP,LOW);
  digitalWrite(rm2PinN,HIGH);
  yellow();
  digitalWrite(12,HIGH);
  delay(3000);
  digitalWrite(12,LOW);
}
void forward() 
{
  Serial.println("Progressing forward Operation");
  digitalWrite(fm1PinP,LOW);
  digitalWrite(fm1PinN,HIGH);
  digitalWrite(rm2PinP,LOW);
  digitalWrite(rm2PinN,HIGH);
  green();
}
void reverse() 
{
  Serial.println("Progressing reverse Operation");
  digitalWrite(fm1PinP,HIGH);
  digitalWrite(fm1PinN,LOW);
  digitalWrite(rm2PinP,HIGH);
  digitalWrite(rm2PinN,LOW);
  cyan;
}
void pwr_off()
{
  Serial.println("Decceleration Operation");
  digitalWrite(fm1PinP,LOW);
  digitalWrite(fm1PinN,LOW);
  digitalWrite(rm2PinP,LOW);
  digitalWrite(rm2PinN,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
void setColor(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
void red() {
  noColor();
  setColor(0, 255, 255);  // red
  delay(1000);
  Serial.println("RED");
  noColor();
}
void green() {
  noColor();
  setColor(255, 0, 255);  // green
  delay(1000);
  Serial.println("GREEN");
  noColor();
}
void blue() {
  noColor();
  setColor(255, 255, 0);  // blue
  delay(1000);
  Serial.println("BLUE");
  noColor();
}
void yellow() {
  noColor();
  setColor(0, 0, 255);  // yellow
  delay(1000);
  Serial.println("YELLOW");
  noColor();
}
void magenta() {
  noColor();
  setColor(0, 255, 0);  // magenta
  delay(1000);
  Serial.println("MAGENTA");
  noColor();
}
void cyan() {
  noColor();
  setColor(255, 0, 0);  // cyan
  delay(1000);
  Serial.println("CYAN");
  noColor();
}
void noColor() {
  setColor(255, 255, 255);  // null
}
