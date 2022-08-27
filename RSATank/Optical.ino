/*
 * Pins used for the infrared sensors
 */
#define PIN_OPTICAL_LEFT 8
#define PIN_OPTICAL_RIGHT 9

// Setting up the pins related to the optical sensor. But pins are digital inputs.
void OpticalSetup (void)
{
  pinMode(PIN_OPTICAL_LEFT, INPUT);
  pinMode(PIN_OPTICAL_RIGHT, INPUT);
}
