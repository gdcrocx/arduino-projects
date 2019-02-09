/*
Adafruit Arduino - RGB LED
*/
const int redPin = 5;
const int greenPin = 3;
const int bluePin = 6;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  colorLineUp();
}

void loop()
{
  //colorLineUp();
}

void colorLineUp()
{
  Serial.begin(9600);
  /*red();
  noColor();
  green();
  noColor();
  blue();
  noColor();
  yellow();
  noColor();
  magenta();
  noColor();
  cyan();
  noColor();*/
  orange();
  noColor();
  Serial.end();
}
void red() {
  Serial.println("RED");
  setColor(0, 255, 255);  // red
  delay(1000);
}
void green() {
  Serial.println("GREEN");
  setColor(255, 0, 255);  // green
  delay(1000);
}
void blue() {
  Serial.println("BLUE");
  setColor(255, 255, 0);  // blue
  delay(1000);
}
void yellow() {
  Serial.println("YELLOW");
  setColor(0, 0, 255);  // yellow
  delay(1000);
}
void magenta() {
  Serial.println("MAGENTA");
  setColor(0, 255, 0);  // magenta
  delay(1000);
}
void cyan() {
  Serial.println("CYAN");
  setColor(255, 0, 0);  // cyan
  delay(1000);
}
void orange() {
  Serial.println("ORANGE");
  setColor(0, 200, 255);  // orange
  delay(1000);
}
void noColor() {
  Serial.println("NO COLOR");
  setColor(255, 255, 255);  // null
}

void setColor(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  Serial.println();
  Serial.print(red);
  Serial.print(green);
  Serial.println(blue);
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
