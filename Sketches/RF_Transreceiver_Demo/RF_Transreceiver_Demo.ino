#include <VirtualWire.h>
int count;
void setup()
{
  Serial.begin(9600);    // Debugging only
  Serial.println("setup"); // Prints "Setup to the serial monitor"


  vw_set_tx_pin(11);          // Sets pin D12 as the TX pin
  vw_set_ptt_inverted(true);  // Required for DR3100
  vw_setup(4000);         // Bits per sec

  vw_set_rx_pin(12);       //Sets pin D12 as the RX Pin
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(4000);       // Bits per sec
  vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
  const char *msg = "hello";   // Message to be sent
  digitalWrite(13, true);      // Flash a light to show transmitting
  vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13, false);   // Turn the LED off.
  delay(50);                 // A short gap.

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int i;
    digitalWrite(13, true);  // Flash a light to show received good message
    // Message with a good checksum received, dump it.
    Serial.print("Got: ");

    for (i = 0; i < buflen; i++)
    {
      char c = (buf[i]);
      Serial.print(c);
      Serial.print(" ");
    }
    count++;
    // Serial.print(count);
    Serial.println("");
    digitalWrite(13, false);
  }
  delay(1000);
}
