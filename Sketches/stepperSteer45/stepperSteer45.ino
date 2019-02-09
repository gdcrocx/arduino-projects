#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // set the speed at 60 rpm:

  //myStepper.step(45);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
left();
delay(500);
revleft();
delay(2000);
right();
delay(500);
revright();
delay(2000);
}
void revleft()
{
   myStepper.setSpeed(45);
   myStepper.step(25);
}
void left()
{
  myStepper.step(-25);
}
  void right()
{
  myStepper.step(25);
}
void revright()
{
  myStepper.step(-25);
}
