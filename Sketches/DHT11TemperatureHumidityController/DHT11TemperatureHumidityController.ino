// Program for a Temperature and Humidity Sensor
// Author: George Davis C
// Date: 08 August 2015
// Components Used: 4.7k resistor, DHT11 Temp & Humidity Sensor, Arduino Uno R3, 5v SONGLE Relays on HL-52S v1.0 - 2 Relays Board
#include <dht.h> //DHT Library by Rob Tillaart v0.1.01 for DHT-XX Sensors
dht DHT;
// Arduino PIN Assignments
// PIN 0 -> Receiver RX Lines to Arduino
// PIN 1 -> Transmitter TX Lines to Arduino
// RELAYS
// In this case, relayPin1 is Temperature Controller and
// relayPin2 is Humidity Controller
int relayPin1 = 2; // Arduino PIN 2 for Relay 1 DATA PIN
int relayPin2 = 3; // Arduino PIN 2 for Relay 2 DATA PIN
int DHT11_PIN = 4;
int toggleTHPin = 5; // PIN 8 is TRUE, then TEMP else HUMIDITY is selected
int toggleULPin = 6; // PIN 9 is TRUE, then UPPERLIMIT else LOWERLIMIT is selected
int togIncreasePin = 7;
int togDecreasePin = 8;
int editPin = 9;
int led = 12; // TO WILLFULLY AVOID USING THE DEFAULT PIN 13 SMD LED
// Global Variables for the Temperature & Humidity Control System
bool editFlag = 0;
bool thFlag = 0; // 0 - Temp, 1 - Humidity
bool ulFlag = 0; // 0 - Upper, 1 - Lower
int TU = 0;
int TL = 0;
int HU = 0;
int HL = 0;
int dhtTemp = 0;
int dhtHumid = 0;
// Relays are INVERSE in Arduino UNO
int RELAY_ON = 0;
int RELAY_OFF = 1;
// Condition Programmatic Constants
#define MIN_THRESHOLD 0 //DHT11 Sensor supports from 0 degree Celsius to 50 degrees Celsius
#define MAX_THRESHOLD 50 //DHT11 Sensor supports from 0 degree Celsius to 50 degrees Celsius 
void setup() // RUNS ONLY ONCE EVERY BOOT
{
  // SET THE MODE OF PINS TO EITHER INPUT OR OUTPUT
  pinMode(DHT11_PIN, INPUT);
  pinMode(toggleTHPin, INPUT); // Toggle to Temp controls
  pinMode(toggleULPin, INPUT); // Toggle to Humidity controls
  pinMode(togIncreasePin, INPUT); // Increase in Counter control value
  pinMode(togDecreasePin, INPUT); // Decrease in Counter control value
  pinMode(editPin, INPUT); // Edit ON/OFF control for the complete system
  pinMode(led, OUTPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  // Prepare the system variables for the controls
  digitalWrite(toggleTHPin, LOW);
  digitalWrite(toggleULPin, LOW);
  digitalWrite(togIncreasePin, LOW);
  digitalWrite(togDecreasePin, LOW);
  Serial.begin(9600); //Starting a Serial Connection to start transmitting values onto Display (or) Serial Monitor. WATCH OUT FOR TX BLINKING EVERY TIME THE Serial.println() IS EXECUTED
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(led, HIGH);
    digitalWrite(relayPin1, RELAY_ON);
    digitalWrite(relayPin2, RELAY_ON);
    Serial.println("Initializing...");
    delay(1000);
    digitalWrite(relayPin2, RELAY_OFF);
    digitalWrite(relayPin1, RELAY_OFF);
    digitalWrite(led, LOW);
    delay(1000);
  }
  Serial.println("Welcome Valadis");
  delay(2000);
  Serial.println("Ready for Action!");
  delay(2000);
  Serial.println("Started Monitor");
}
void loop() // LOOPS ETERNALLY
{
  delay(500);
  if (digitalRead(toggleTHPin) == HIGH) // toggleTHPin - Check for Button press
  {
    thFuncToggleHandler();
    thFuncDisplayHandler();
    delay(1000);
  }
  delay(500);
  if (digitalRead(toggleULPin) == HIGH) // toggleULPin - Check for Button press
  {
    ulFuncToggleHandler();
    ulFuncDisplayHandler();
    delay(1000);
  }
  delay(500);
  if (digitalRead(togIncreasePin) == HIGH || digitalRead(togDecreasePin) == HIGH) // Increase/Decrease Pin - Check for Button press
  {
    editFlag = 1;
    while (editFlag == 1)
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
      delay(1000);
      if (digitalRead(editPin) == HIGH)
      {
        editFlag = 0;
        delay(500);
      }
    }
  }
  checkDHT();
  checkTemp();
  checkHumid();
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
      else if (digitalRead(togDecreasePin) == HIGH)
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
      else if (digitalRead(togDecreasePin) == HIGH)
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
      else if (digitalRead(togDecreasePin) == HIGH)
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
      else if (digitalRead(togDecreasePin) == HIGH)
      {
        HL = valueDecreaser(HL);
      }
    }
  }
}
void checkDHT()
{

  if (editFlag == 0)
  {
    digitalWrite(led, HIGH);
    delay(500);
    // int chk = // UNCOMMENT TO ENABLE DHT11 CHECKSUM
    DHT.read11(DHT11_PIN);
    dhtTemp = DHT.temperature;
    dhtHumid = DHT.humidity;
    Serial.print("Temperature: ");
    Serial.print(dhtTemp);
    Serial.print(" Humidity: ");
    Serial.println(dhtHumid);
    digitalWrite(led, LOW);
    delay(1000);
    // DHT11 requires delay(2000); before everytime in execution
    // which is compensated by consequent delays in the previous blocks of execution that preceed this block
  }
  else
  {
    Serial.println("EDIT FLAG is TRUE");
  }
}
void checkTemp()
{
  if (dhtTemp > TU && dhtTemp < TL) // relayPin1 is Temperature Controller
  {
    digitalWrite(led, HIGH);
    digitalWrite(relayPin1, RELAY_ON);
    delay(400);
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
    digitalWrite(relayPin1, RELAY_OFF);
    delay(400);
    digitalWrite(led, LOW);
  }
}
void checkHumid()
{
  if (dhtHumid > HU && dhtHumid < HL) // relayPin2 is Humidity Controller
  {
    digitalWrite(led, HIGH);
    digitalWrite(relayPin2, RELAY_ON);
    delay(400);
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
    digitalWrite(relayPin2, RELAY_OFF);
    delay(400);
    digitalWrite(led, LOW);
  }
}

// CHECKSUM FOR DHT11
/*
switch (chk)
{
  case DHTLIB_OK:
  Serial.print("OK,\t");
  break;
  case DHTLIB_ERROR_CHECKSUM:
  Serial.print("Checksum error,\t");
  break;
  case DHTLIB_ERROR_TIMEOUT:
  Serial.print("Time out error,\t");
  break;
  case DHTLIB_ERROR_CONNECT:
      Serial.print("Connect error,\t");
      break;
  case DHTLIB_ERROR_ACK_L:
      Serial.print("Ack Low error,\t");
      break;
  case DHTLIB_ERROR_ACK_H:
      Serial.print("Ack High error,\t");
      break;
  default:
  Serial.print("Unknown error,\t");
  break;
}
*/
