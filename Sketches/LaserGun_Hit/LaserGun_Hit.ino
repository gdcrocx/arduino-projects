#include <IRremote.h>
int Port1 = 2;
int Port2 = 3;
int Port3 = 4;
int Port4 = 5;
int Port5 = 6;
IRrecv irrecv(); 
decode_results results; 
void setup() 
{
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  irrecv.enableIRIn();
}
void loop() 
{
  if (irrecv.decode(&results))
  {  

    Serial.begin(9600);
    Serial.println(result1.value);
    Serial.println(result2.value);
    Serial.println(result3.value);
    Serial.println(result4.value);
    Serial.println(result5.value);   
    delay(1000);
    Serial.end();
    irrecv.resume(); 
  }
}




