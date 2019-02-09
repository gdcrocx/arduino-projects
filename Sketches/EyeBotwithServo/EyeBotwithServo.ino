#include <Servo.h> 
#include <IRremote.h>
const int trigPin = 2;
const int echoPin = 4;
const double threshold = 10.00;
Servo myservo1; // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results;
void setup() 
{
  myservo1.attach(6);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(7);  // attaches the servo on pin 10 to the servo object 
  myservo1.write(0);
  myservo2.write(0);
  irrecv.enableIRIn();
  delay(1000);
  Serial.begin(9600);
}
void loop() 
{
  /*double duration, cm;
   pinMode(trigPin,OUTPUT);
   digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
   //delayMicroseconds(2);
   pinMode(echoPin,INPUT);
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
   int beepr(double dist) //cm to local variable 'dist'
   {
   if(dist < threshold) //Less than threshold dist LED @ PIN 12 burns, Need action
   {
   digitalWrite(12,HIGH);
   if (irrecv.decode(&results)) 
   {
   long int input = results.value;
   Serial.println(input);
   switch (input) 
   {
   case '16724175':    
   turn_left();
   break;
   case '16743045':    
   turn_right();
   break;
   } 
   irrecv.resume(); 
   }
   }
   else  //Above threshold dist LED @ PIN 12 burns, Keep moving in the current direction
   {
   digitalWrite(12,LOW);
   Serial.println("Servos in same direction, moving forward");
   }
   return 0;
   }*/
  turn_left();
  delay(300);
  turn_right();
  delay(300);
}
void turn_left()
{ 
  int var1 =0, var2 = 0, turnUpperLimit = 0;
  var1 =  myservo1.read();
  Serial.println(var1);
  var2 = myservo2.read();
  Serial.println(var2);
  delay(500);
  Serial.println("Progressing leftTurn Operation");
  delay(2000);
  turnUpperLimit = var2 + 90;
  if((var1 < 180)||(var2 < 180))
  {
    while(var2 >= 0 && var2 <= turnUpperLimit)
    {
      var2 += 1;
      myservo2.write(var2);  //Actuating right servo to turn left, while left servo is idle
      delay(5); 
      Serial.println(var2);  
    }
  }
  else
  {
    var1 = 0; 
    var2 = 0; 
    Serial.println("Resetting variables for  leftTurn Operation");
    turn_left();
  }

  Serial.println("leftTurn Operation Complete!!");
  delay(1000); //Idling time
}
void turn_right()
{ 
  int var1 =0, var2 = 0, turnUpperLimit = 0;
  var1 =  myservo1.read();
  Serial.println(var1);
  var2 = myservo2.read();
  Serial.println(var2);
  delay(500);
  Serial.println("Progressing rightTurn Operation");
  delay(2000);
  turnUpperLimit = var1 + 90;
  if((var1 < 180)||(var2 < 180))
  {
    while(var1 >= 0 && var1 <= turnUpperLimit)
    {
      var1 += 1;
      myservo1.write(var1);  //Actuating left servo to turn right, while right servo is idle
      delay(5); 
      Serial.println(var1);  
    }
  }
  else
  {
    var1 = 0; 
    var2 = 0; 
    Serial.println("Resetting variables for  leftTurn Operation");
    turn_left();
  }
  Serial.println("rightTurn Operation Complete!!");
  delay(1000); //Idling time
}
/*void aboutTurn() //Needs 360deg turn and hence crimpping the 180deg limiter on the TowerPro SG90. As of now, 180deg limitations and hence this option cant be performed
 {
 int var1 =0, var2 = 0, turnUpperLimitL = 0, turnUpperLimitR = 0;
 Serial.print(var1);
 Serial.print(var2);
 Serial.println("Progressing aboutTurn Operation");
 delay(2000);
 turnUpperLimitL = var1 + 180;
 turnUpperLimitR = var1 + 180;
 while(var1 >= 0 && var2 >= 0 && var1 < 360 && var2 < 360 && turnUpperLimitL > 180 && turnUpperLimitR > 180)
 {
 var1 += 1;
 myservo1.write(var1);  //Actuating left servo to turn right, while right servo is idle
 delay(5); 
 Serial.println(var1);  
 }
 delay(300); //Idling time
 }*/

















