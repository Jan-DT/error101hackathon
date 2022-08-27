/*
 * Pins used for the bluetooth communication
 */
#define PIN_ENABLE_LEFT  24
#define PIN_REVERSE_LEFT 7
#define PIN_FORWARD_LEFT 6

#define PIN_ENABLE_RIGHT  25
#define PIN_REVERSE_RIGHT 3
#define PIN_FORWARD_RIGHT 2


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
     if (manualEnabled) {
       analogWrite(PIN_REVERSE_LEFT,0);
       analogWrite(PIN_REVERSE_RIGHT,0);
       analogWrite(PIN_FORWARD_LEFT,100);
       analogWrite(PIN_FORWARD_RIGHT,100);
       break;
     }
   case 's':
//     Serial.println("Moving backward");
     if (manualEnabled) {
       analogWrite(PIN_FORWARD_LEFT,0);
       analogWrite(PIN_FORWARD_RIGHT,0);
       analogWrite(PIN_REVERSE_LEFT,100);
       analogWrite(PIN_REVERSE_RIGHT,100);
       break;
     }
   case 'a':
//     Serial.println("Turning left");
     if (manualEnabled) {
       analogWrite(PIN_REVERSE_RIGHT,0);
       analogWrite(PIN_FORWARD_LEFT,0);
       analogWrite(PIN_REVERSE_LEFT,100);
       analogWrite(PIN_FORWARD_RIGHT,100);
       break;
     }
   case 'd':
//     Serial.println("Turning right");
     if (manualEnabled) {
       analogWrite(PIN_REVERSE_LEFT,0);
       analogWrite(PIN_FORWARD_RIGHT,0);
       analogWrite(PIN_REVERSE_RIGHT,100);
       analogWrite(PIN_FORWARD_LEFT,100);
       break;
     }
   case 'x':
       analogWrite(PIN_REVERSE_LEFT,0);
       analogWrite(PIN_FORWARD_RIGHT,0);
       analogWrite(PIN_REVERSE_RIGHT,0);
       analogWrite(PIN_FORWARD_LEFT,0);
       break;
   case 'y':
     manualEnabled = true;
     break;
   case 'n':
     manualEnabled = false;
     break;
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
