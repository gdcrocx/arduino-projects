/*   
  This sketch increases a 3 bit number every time '+' button is pressed and decreases the value when '-' button is pressed on the remote.It shows the output on 3 LEDs in Binary Format   
  */  
 #include <IRremote.h>  
 int RECV_PIN = 15;  
 IRrecv irrecv(RECV_PIN);  
 decode_results results;  
 int i = 0;  
 void setup()  
 {  
  pinMode(11,OUTPUT);   // declare LED pins as output pins  
  pinMode(12,OUTPUT);  
  pinMode(13,OUTPUT);  
  pinMode(7,INPUT);// Declare the 7th pin as a input pin. We will use the button on the 7th pin  
  digitalWrite(7,HIGH);  
  irrecv.enableIRIn(); // Start the Remote receiver  
  Serial.begin(9600);  
 }  
 void loop()  
 {  
  if (irrecv.decode(&results)) {  
   Serial.println(results.value);  
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
   delay(35);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
   delay(35);
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
   delay(35);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
   delay(35);
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
   delay(35);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
   delay(35);
   while(digitalRead(7)==0);  // wait till button is released to avoid incrementing the counter again  
   delay(300);         // small delay to avoid debounce  
   irrecv.resume(); // Receive the next value  
  }  
 }  
