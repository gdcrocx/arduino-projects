#include <IRremote.h>
int RECV_PIN = 15;  
IRrecv irrecv(RECV_PIN);  
decode_results results; 

void setup() 
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  //pinMode(RECV_PIN,INPUT);
  irrecv.enableIRIn(); // Start the Remote receiver  
}

void loop() 
{
  if (irrecv.decode(&results))
  { 
    digitalWrite(11,HIGH);
    delay(200);
    digitalWrite(11,LOW);
    Serial.begin(9600);
    Serial.println(results.value);
    Serial.end();
    digitalWrite(12,HIGH);
    delay(300);
    digitalWrite(12,LOW);
    delay(1000);
    irrecv.resume(); // Receive the next value    
  }
}
