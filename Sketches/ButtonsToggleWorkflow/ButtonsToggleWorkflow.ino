int toggleTHPin = 5; // PIN 8 is TRUE, then TEMP else HUMIDITY is selected
int toggleULPin = 6; // PIN 9 is TRUE, then UPPERLIMIT else LOWERLIMIT is selected
int togIncreasePin = 7;
int togDecreasePin = 8;
int led = 12; // TO WILLFULLY AVOID USING THE DEFAULT PIN 13 SMD LED
bool thFlag = 0; // 0 - Temp, 1 - Humidity
bool ulFlag = 0; // 0 - Upper, 1 - Lower
int TU = 0;
int TL = 0;
int HU = 0;
int HL = 0;
// Condition Programmatic Constants
#define MIN_THRESHOLD 0 //DHT11 Sensor supports from 0 degree Celsius to 50 degrees Celsius
#define MAX_THRESHOLD 50 //DHT11 Sensor supports from 0 degree Celsius to 50 degrees Celsius 
void setup()
{
  pinMode(toggleTHPin, INPUT); // Toggle to Temp controls
  pinMode(toggleULPin, INPUT); // Toggle to Humidity controls
  pinMode(togIncreasePin, INPUT); // Increase in Counter control value
  pinMode(togDecreasePin, INPUT); // Decrease in Counter control value
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  //Start Check
  Serial.print("TH FLAG - ");
  Serial.print(thFlag);
  Serial.print(" UL FLAG - ");
  Serial.print(ulFlag);
  Serial.print(" TU - ");
  Serial.print(TU);
  Serial.print(" TL - ");
  Serial.print(TL);
  Serial.print(" HU - ");
  Serial.print(HU);
  Serial.print(" HL - ");
  Serial.println(HL);
}
void loop()
{
  if (digitalRead(toggleTHPin) == HIGH)
  {
    thFuncToggleHandler();
    thFuncDisplayHandler();
    delay(1000);
  }
  if (digitalRead(toggleULPin) == HIGH)
  {
    ulFuncToggleHandler();
    ulFuncDisplayHandler();
    delay(1000);
  }
  if (digitalRead(togIncreasePin) == HIGH || digitalRead(togDecreasePin) == HIGH)
  {
    tempController();
    Serial.print("TH FLAG - ");
    Serial.print(thFlag);
    Serial.print(" UL FLAG - ");
    Serial.print(ulFlag);
    Serial.print(" TU - ");
    Serial.print(TU);
    Serial.print(" TL - ");
    Serial.print(TL);
    Serial.print(" HU - ");
    Serial.print(HU);
    Serial.print(" HL - ");
    Serial.println(HL);
    delay(500);
  }
}
void thFuncToggleHandler()
{
  Serial.print("TH FLAG = ");
  Serial.print(thFlag);
  thFlag = !thFlag;
  Serial.print(" -> ");
  Serial.print(thFlag);
}
void thFuncDisplayHandler()
{
  if (thFlag == 0)
  {
    Serial.println(" => Temperature Selected");
  }
  else
  {
    Serial.println(" => Humidity Selected");
  }
}
void ulFuncToggleHandler()
{
  Serial.print("UL FLAG = ");
  Serial.print(ulFlag);
  ulFlag = !ulFlag;
  Serial.print(" -> ");
  Serial.print(ulFlag);
}
void ulFuncDisplayHandler()
{
  if (ulFlag == 0)
  {
    Serial.println(" => Upper Limit Selected");
  }
  else
  {
    Serial.println(" => Lower Limit Selected");
  }
}
int valueIncreaser(int val)
{
  if (val < MAX_THRESHOLD)
  {
    val += 1;
    delay(1000);
  }
  else
  {
    delay(1000);
    return MAX_THRESHOLD;
  }
  return val;
}
int valueDecreaser(int val)
{
  if (val > MIN_THRESHOLD)
  {
    val -= 1;
    delay(1000);
  }
  else
  {
    delay(1000);
    return MIN_THRESHOLD;
  }
  return val;
}
void tempController()
{
  if (thFlag == 0) // 0 - Temperature Controls
  {
    if (ulFlag == 0) // 0 - Upper the Temperature value
    {
      if (digitalRead(togIncreasePin) == HIGH)
      {
        TU = valueIncreaser(TU);        
      }
      else if(digitalRead(togDecreasePin) == HIGH)
      {
        TU = valueDecreaser(TU);
      }
    }
    else // 1 - Lower the Temperature value
    {
      if (digitalRead(togIncreasePin) == HIGH)
      {
        TL = valueIncreaser(TL);        
      }
      else if(digitalRead(togDecreasePin) == HIGH)
      {
        TL = valueDecreaser(TL);
      }
    }
  }
  else // 1 - Humidity Controls
  {
    if (ulFlag == 0) // 0 - Upper the Humidity value
    {
      if (digitalRead(togIncreasePin) == HIGH)
      {
        HU = valueIncreaser(HU);        
      }
      else if(digitalRead(togDecreasePin) == HIGH)
      {
        HU = valueDecreaser(HU);
      }
    }
    else // 1 - Lower the Humidity value
    {
      if (digitalRead(togIncreasePin) == HIGH)
      {
        HL = valueIncreaser(HL);        
      }
      else if(digitalRead(togDecreasePin) == HIGH)
      {
        HL = valueDecreaser(HL);
      }
    }
  }
}
