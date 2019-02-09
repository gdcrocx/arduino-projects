int val = 0; 
 void setup()  
 {  
  Serial.begin(9600);
 }  
 void loop()  
 {  
  val = analogRead(3);
  Serial.print("Light Intensity is : ");
  Serial.println(val);
  delay(1000);  
 } 
