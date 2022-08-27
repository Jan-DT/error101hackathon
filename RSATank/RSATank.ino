/*
 * Please do not change the pin numbers, feel free to change the name of the constants!
 */

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
//  CommunicationSetup();
}

/*
 * Put the code here that you want to run repeatedly. 
 */
void loop () 
{
  delay(100)
//  CommunicationUpdate();
//  CommunicationCheck();
}
