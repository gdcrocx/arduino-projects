const double threshold = 1.5;
double fDist, lDist, rDist, bDist;
void setup() 
{
  Serial.begin(9600);
  for( int i=2; i<9; i=i+2)
  {
    //Initialize all 4 Distance Sensor
    pinMode(i, OUTPUT);
    digitalWrite(i,LOW);
    delayMicroseconds(2);
    digitalWrite(i,HIGH);
    delayMicroseconds(10);
    digitalWrite(i,LOW);
    //Serial.print(i);
  };
};

void loop() {
  ultraRadar();
};
long microsecondsToInches(long microseconds)
{
  return microseconds /74 /2;
};
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
};
void ultraRadar()
{
  for( int i=2; i<9; i=i+2)
  {
    //Initialize all 4 Distance Sensor
    double duration, inches, cm, feet;  
    //Serial.println(i);
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
    delayMicroseconds(2);
    digitalWrite(i,HIGH);
    delayMicroseconds(10);
    digitalWrite(i,LOW);
    if(i == 2)
    {      
      pinMode(i+1,INPUT);
      duration = pulseIn(i+1,HIGH);
    
      inches =  microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      feet = inches / 12;
      fDist = cm;
    }
    else if (i == 4) 
    {
      pinMode(i+1,INPUT);
      duration = pulseIn(i+1,HIGH);
    
      inches =  microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      feet = inches / 12;
      lDist = cm;
    }
    else if (i == 6) 
    {
      pinMode(i+1,INPUT);
      duration = pulseIn(i+1,HIGH);
    
      inches =  microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      feet = inches / 12;
      rDist = cm;
    }
    else if (i == 8) 
    {
      pinMode(i+1,INPUT);
      duration = pulseIn(i+1,HIGH);
    
      inches =  microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      feet = inches / 12;
      bDist = cm;
    }
    //Serial.print("Obstacle at    ");
    //Serial.print(feet);
    //Serial.print("feet   ---  ");
    //Serial.print(inches);
    //Serial.print("inches");
    //Serial.print(" ---  ");
    //Serial.print(cm);
    //Serial.print("cms");
    //Serial.println();    
  };
  if( fDist <= 500 && lDist <= 500 && rDist <= 500 && bDist <= 500)
  {
    Serial.print("Forward - ");
    Serial.print(fDist);
    Serial.print("cms Left - ");
    Serial.print(lDist);
    Serial.print("cms Right - ");
    Serial.print(rDist);
    Serial.print("cms Backward - ");
    Serial.print(bDist);
    Serial.print("cms");
    Serial.println(' ');
    digitalWrite(12, HIGH);
    delay(200);    
  }
  else
  {
    Serial.println("--Skipped--");
  }
};
