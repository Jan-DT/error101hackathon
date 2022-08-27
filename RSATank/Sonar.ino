/*
 * Pins used for the sonar (sensor to measure distance)
 */
#define PIN_SONAR_TRIGGER 23
#define PIN_SONAR_ECHO 22

const float SONAR_SPEED = 0.034 / 2.0; // in centimetres/second

/*
 * Setting up the pins related to the sonar sensor.
 */
void SonarSetup (void)
{
  pinMode(PIN_SONAR_TRIGGER, OUTPUT);
  pinMode(PIN_SONAR_ECHO, INPUT);
  
  digitalWrite(PIN_SONAR_TRIGGER, LOW);
}
