/*
 * Please do not change the pin numbers, feel free to change the name of the constants!
 */

#define PIN_OPTICAL_LEFT 9
#define PIN_OPTICAL_RIGHT 8

#define PIN_ENABLE_LEFT  24
#define PIN_REVERSE_LEFT 7
#define PIN_FORWARD_LEFT 6

#define PIN_ENABLE_RIGHT  25
#define PIN_REVERSE_RIGHT 3
#define PIN_FORWARD_RIGHT 2

#define NO_OF_DIRECTIONS 4

#define MOTOR_CODE_RESET    0b0000
#define MOTOR_CODE_FORWARD  0b1100
#define MOTOR_CODE_REVERSE  0b0011
#define MOTOR_CODE_LEFT     0b0110
#define MOTOR_CODE_RIGHT    0b1001

/*
 * This function runs once and we have already implemented everything needed 
 * for the motors and the starting sensors. Be careful if you add/remove any
 * hardware. If you need more information please check:
 * 
 * https://www.arduino.cc/reference/en/language/structure/sketch/setup/
 */
void setup ()
{
  MotorSetup();
  SonarSetup();
  OpticalSetup();
  CommunicationSetup();
  Serial.begin(9600);
}

/*
 * Put the code here that you want to run repeatedly. 
 */
void loop () 
{
  Serial.println(digitalRead(PIN_OPTICAL_LEFT));
//  CommunicationUpdate();
//  CommunicationCheck();
}
