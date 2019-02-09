#include <Servo.h> 
Servo myservo1; // create servo object to control a servo 
Servo myservo2;
int var =8;
void setup() 
{ 
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(10);
  myservo1.write(8);
  myservo2.write(8);
  delay(1000);
  Serial.begin(9600);
} 
void loop() 
{ 
  clkwise();  
} 
void clkwise()
{ 
  while(var >= 8 && var < 180)
  {
    while(var <= 180)
    {
      var += 1;
      myservo1.write(var); 
      myservo2.write(var);
      delay(5); 
      Serial.println(var);  
      break;
    }
  }
  delay(300);
  while(var <= 180 && var > 8)
  {
    while(var >= 0)
    {
      var -= 1;
      myservo1.write(var);
      myservo2.write(var);
      delay(5);
      Serial.println(var); 
      break;
    }
  }
  delay(300);
}


