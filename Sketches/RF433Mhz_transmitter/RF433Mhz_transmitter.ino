// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

const int led = 13;

//RH_ASK driver;
RH_ASK driver(2000, 4, 2, 5, false);

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println("init Successful");
}

void loop()
{
  const char *msg = "hello";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();

  Serial.println(msg);

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);  
  delay(1000);
}
