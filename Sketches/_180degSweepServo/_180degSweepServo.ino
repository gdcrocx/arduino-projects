#include <Servo.h> 
Servo myservo1; // create servo object to control a servo 
//int cpos = 0;    // variable to store the servo position 
int var =0;
void setup() 
{ 
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  //myservo2.attach(10);
  myservo1.write(0);
  delay(1000);
  Serial.begin(9600);
} 
void loop() 
{ 
  //Serial.print(clkwise());
  clkwise();  
  delay(1000);
  //myservo2.write(counterclkwise(0));       
} 
void clkwise()
{ 
  while(var >= 0 && var < 180)
  {
    while(var <= 180)
    {
      var += 1;
      myservo1.write(var); 
      delay(2); 
      Serial.println(var);  
      break;
    }
  }
  while(var <= 180 && var > 0)
  {
    while(var >= 0)
    {
      var -= 1;
      myservo1.write(var);
      delay(2);
      Serial.println(var); 
      break;
    }
  }
}
/* 
 cpos = 0; cpos < 180; cpos += 10)  // goes from 0 degrees to 180 degrees 
 {                                  // in steps of 1 degree 
 Serial.print(cpos); 
 return cpos;
 // tell servo to go to position in variable 'pos' 
 delay(15);                       // waits 15ms for the servo to reach the position 
 } 
 for(cpos = 180; cpos>=1; cpos-=10)     // goes from 180 degrees to 0 degrees 
 {    
 Serial.print(" - ");
 Serial.println(cpos);     
 return cpos;            // tell servo to go to position in variable 'pos' 
 delay(15);                       // waits 15ms for the servo to reach the position 
 } 
 }
 int counterclkwise(int ccpos)
 {
 for(ccpos = 180; ccpos>=1; ccpos-=10)     // goes from 180 degrees to 0 degrees 
 {                                
 Serial.println(ccpos);     return ccpos;            // tell servo to go to position in variable 'pos' 
 delay(15);                       // waits 15ms for the servo to reach the position 
 } 
 for(int cpos = 0; cpos < 180; cpos += 10)  // goes from 0 degrees to 180 degrees 
 {                                  // in steps of 1 degree 
 return cpos;           // tell servo to go to position in variable 'pos' 
 delay(15);                       // waits 15ms for the servo to reach the position 
 } 
 }*/







