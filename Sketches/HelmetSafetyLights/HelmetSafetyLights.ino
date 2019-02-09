const int defaultDelay = 300;
const int inputPin = 7;
const int stopLight = 10;
const int leftIndicator = 11;
const int rightIndicator = 12;
const int processIndicator = 13;

int inputCounter = 0;
int lastInputCounter = 0;
int numModes = 4;

int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 200;    // the debounce time; increase if the output flickers

void setup() {  
  pinMode(inputPin, INPUT); 
  pinMode(stopLight, OUTPUT);
  pinMode(leftIndicator, OUTPUT);
  pinMode(rightIndicator, OUTPUT);
  pinMode(processIndicator, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  counterGovernor();
  if(inputCounter != lastInputCounter)
  {
    flushLights(); 
    if(inputCounter == 0) {
      if(!digitalRead(stopLight)) {
        Serial.println("Stop Lights ON");
        digitalWrite(stopLight, HIGH);
        digitalWrite(processIndicator, HIGH);
      }
    }
    if(inputCounter == 1) {
      //Power Saver Mode
      Serial.println("Blinking Stop Lights ON");
      toggleBulb(stopLight, 700);
    }
    if(inputCounter == 2) {
      Serial.println("Left Indicator ON");
      toggleBulb(leftIndicator, defaultDelay);
    }
    if(inputCounter == 3) {
      Serial.println("Right Indicator ON");
      toggleBulb(rightIndicator, defaultDelay);  
    }
    if(inputCounter == 4) {
      //EmergencyLights
      Serial.println("Emergency Lights ON");
      toggleBulb(leftIndicator, defaultDelay);
      toggleBulb(rightIndicator, defaultDelay);
    }
    lastInputCounter = inputCounter;
  }
}

void counterGovernor() {  
  int input = buttonDebounce();
  if(input == 0) {
      Serial.println("Button Pressed: " + input);
      inputCounter++;
      if(inputCounter > numModes) {
        inputCounter = 0;
        Serial.println("---------- Counter Reset ----------");
      }
  }
}  

int buttonDebounce() {
  int reading = digitalRead(inputPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonState = reading;
    Serial.println("Input Status -" + reading);
  }
  digitalWrite(processIndicator, buttonState);
  lastButtonState = reading;
  return buttonState;
}

void flushLights() {
  Serial.println("Flushing lights");
  digitalWrite(stopLight, LOW);
  digitalWrite(leftIndicator, LOW);
  digitalWrite(rightIndicator, LOW);
  digitalWrite(processIndicator, LOW);
  delay(defaultDelay);
}

void toggleBulb(int bulbPin, int delayTime) {
  //flushLights();
  digitalWrite(bulbPin, !digitalRead(bulbPin));
  digitalWrite(processIndicator, !digitalRead(bulbPin));
  delay(delayTime);
}
