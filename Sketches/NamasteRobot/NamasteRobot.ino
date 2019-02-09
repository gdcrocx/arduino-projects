#include <Servo.h>				//Initiating the header files and defining the pins
#define trigPin 2
#define echoPin 4
#define led 12
//#define relay 8
//Servo sl;					//Attaching the objects
Servo head;
//Servo sr;
//Servo el;   
//Servo er;
int posh=0;
int posl=0;
int posr=0;
void setup()
{
  //sl.attach(9);        			//Attaching the servos to the arduino I/O pins
  //sr.attach(10);
  //el.attach(11);
  //er.attach(5);
  head.attach(7);
Serial.begin (9600);
pinMode(trigPin, OUTPUT);			//Defining the I/O pins
//pinMode(relay, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
//digitalWrite(relay,HIGH);
}
void loop()
{
  for(posh = 0;posh <= 180; posh +=1)
  {
    head.write(posh);
    adam();					//Adding the function to check in the every step of the head turn process
    delay(5);
  }
  for(posh = 180;posh >=0; posh -=1)
  {
   head.write(posh);
   adam();					//Adding the function to check in the every step of the head turn process
   delay(5);
  }   
}
 void adam()					//Calling back the function.
{
  long duration, distance;
  digitalWrite(trigPin, LOW); 				
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
 if (distance < 10)				// This is where the LED On/Off happens
 {  
  digitalWrite(led,HIGH); 
  Serial.println("WELCOME");
  head.write(90);
/*for(posl = 0, posr = 180; posl <= 90 ; posl +=1)  		 //shoulder up
  {
    sl.write(posl);
    sr.write(posr);
    posr -=1;
    delay(15);
  }
for(posr = 0,posl=180; posr <= 45; posr +=1)			// elbow close
  {
    er.write(posr);
    el.write(posl);
    posl -=1;
    delay(15);
  }
  digitalWrite(relay,LOW);					//Relay is activated for 1 second
  delay(1000);
  digitalWrite(relay,HIGH);
  delay(1000); 
  delay(1000); 		// A delay of 1 seconds is added in Namaste position
for(posr = 45,posl=135; posr >= 0; posr -=1)			//elbow open
 {
    er.write(posr);
    el.write(posl);
    posl +=1;
    delay(15);
  }

for(posr = 90,posl= 90; posr <= 180; posr +=1)			//shoulder down
{
sr.write(posr);
sl.write(posl);
posl -=1;
delay(15);
  }
*/
  }

  else						    		//In all the remaining cases LED is OFF
  {
    digitalWrite(led,LOW);
  }
}

