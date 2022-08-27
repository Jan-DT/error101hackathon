/*
 * Pins used for the bluetooth communication
 */

const uint8_t DEF_MAX_SPEED = 240;

void MotorSpeed (char key);

bool manualEnabled = false;

// Setting up the pins related to the bluetooth module and start the Serial.
void CommunicationSetup (void)
{
  Serial1.begin(57600);
//  Serial.begin(9600); //Cable communication
}

// Update the tank as function of the inputted char in serial.
void CommunicationUpdate (void)
{
//  // Get keypress sent by python ( for wired communication only ) comment it out if not needed.
  if(Serial1.available() > 0)
  {
    int key = Serial1.read();
    Serial1.println(char(key));  // DEBUG
    MotorSpeed(key);
  }

//  // Get keypress sent by python ( for wired communication only ) comment it out if not needed.
//if(Serial.available() > 0)
//  {
//    int key = Serial1.read();
//    Serial1.println(char(key));  // DEBUG
//    MotorSpeed(key);
//  }
//  
}

// Change the motor speed depending on the inputted cchar.
void MotorSpeed (char key)
{
 switch (key)
 {
   case 'w':
//     Serial.println("Moving forward");
     if manualEnabled {
       MoveForward(DEF_MAX_SPEED);
       break;
     }
   case 's':
//     Serial.println("Moving backward");
     if manualEnabled {
       MoveBackward(DEF_MAX_SPEED);
       break;
     }
   case 'a':
//     Serial.println("Turning left");
     if manualEnabled {
       TurnLeft(DEF_MAX_SPEED);
       break;
     }
   case 'd':
//     Serial.println("Turning right");
     if manualEnabled {
       TurnRight(DEF_MAX_SPEED);
       break;
     }
   case 'z':
     manualEnabled = not(manualEnabled);
     if manualEnabled {String manualText = "ENABLED"} else {String manualText = "DISABLED"}
     Serial.println("MANUAL " + manualText);
   default:
//     Serial.println("Invalid char was received");
     StopMotors();
     //break;
  }
}

//void CommunicationCheck(void)
//{
//  if (OpticalLeftAbsorbed()) 
////    Serial.println("LEFT");
//  if (OpticalRightAbsorbed()) 
////  Serial.println("RIGHT");
//}
