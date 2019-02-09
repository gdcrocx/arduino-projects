int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;
int upButton = 8;
int downButton = 9;
char gearPos[6] = {'N','1','2','3','4','5'};
int gearCount = 0, upState = 0,downState = 0;

void setup() 
{
  pinMode(upButton,INPUT_PULLUP);
  pinMode(downButton,INPUT_PULLUP);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop() 
{
  Serial.begin(9600);
  while(1)
  {
    if((gearCount >= 0)&&(gearCount < 6))
    {
      if(digitalRead(upButton)==0) // check if the button is being pressed
      {
        gearCount ++; // Increase the gear Count variable
        upState =!upState; // toggle the state variable
        digitalWrite(ledPin3,upState); // write the value of the state variable to the led
        while(digitalRead(upButton)==0); // wait for the switch to be released - Part of Debounce
        delay(40); // give some time for the switch to settle back to normalcy - Part of Debounce
        digitalWrite(ledPin3,LOW);
        upState = 0;
      }   
      if(digitalRead(downButton) == 0)
      {
        gearCount --; // Increase the gear Count variable
        downState =!downState; // toggle the state variable
        digitalWrite(ledPin2,downState); // write the value of the state variable to the led
        while(digitalRead(downButton)==0); // wait for the switch to be released - Part of Debounce
        delay(40); // give some time for the switch to settle back to normalcy - Part of Debounce
        digitalWrite(ledPin2,LOW);
        downState = 0;
      }
    }
    else
    {
      digitalWrite(ledPin1,HIGH);
      digitalWrite(ledPin2,HIGH);
      digitalWrite(ledPin3,HIGH);
      delay(40);
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin3,LOW);
      Serial.println(digitalRead(upButton));
      Serial.println(digitalRead(downButton));
      Serial.println("Wrong Inputs !!");
      gearCount = 0;
      delay(40);
    }
    Serial.println(gearPos[gearCount]);
  }
}

