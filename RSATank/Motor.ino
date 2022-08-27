/*
 * Pins used for the Left motor
 */
#define PIN_ENABLE_LEFT  24
#define PIN_REVERSE_LEFT 7
#define PIN_FORWARD_LEFT 6

/*
 * Pins used for the right motor
 */
#define PIN_ENABLE_RIGHT  25
#define PIN_REVERSE_RIGHT 3
#define PIN_FORWARD_RIGHT 2

#define NO_OF_DIRECTIONS 4

#define MOTOR_CODE_RESET    0b0000
#define MOTOR_CODE_FORWARD  0b1100
#define MOTOR_CODE_REVERSE  0b0011
#define MOTOR_CODE_LEFT     0b0110
#define MOTOR_CODE_RIGHT    0b1001

uint8_t motor_directions[NO_OF_DIRECTIONS];

/*
 * Function Prototypes
 */
//void StartMotors (void);
//void SetMotors (uint8_t motor_code, uint8_t motor_power);
//bool VerifyPower (String motor_direction, uint8_t motor_power);

/*
 * Setting up the pins related to the motors and initiate the array of motor pins responsible for the motor speed.
 */
void MotorSetup (void)
{
  // Setup left motor
  pinMode(PIN_ENABLE_LEFT, OUTPUT);
  pinMode(PIN_REVERSE_LEFT, OUTPUT);
  pinMode(PIN_FORWARD_LEFT, OUTPUT);

  // Setup right motor
  pinMode(PIN_ENABLE_RIGHT, OUTPUT);
  pinMode(PIN_REVERSE_RIGHT, OUTPUT);
  pinMode(PIN_FORWARD_RIGHT, OUTPUT);

  motor_directions[3] = PIN_FORWARD_LEFT;
  motor_directions[2] = PIN_FORWARD_RIGHT;
  motor_directions[1] = PIN_REVERSE_LEFT;
  motor_directions[0] = PIN_REVERSE_RIGHT;

  // Default for now:
  StartMotors();
}

/*
 * Function that moves the tank forward
 * 
 * <param name='power'> Power between 0 and 255, which will be used to move the motors</param>
 */
 
// TODO: parameter datatype to uint8_t
void MoveForward (uint8_t power)
{
//  if (VerifyPower("Forward", power)) return;
  SetMotors(MOTOR_CODE_FORWARD, power);
  StartMotors();
}

/*
 * Function that moves the tank backward
 * 
 * <param name='power'> Power between 0 and 255, which will be used to move the motors</param>
 */
void MoveBackward (uint8_t power)
{
//  if (VerifyPower("REVERSE", power)) return;
  SetMotors(MOTOR_CODE_REVERSE, power);
  StartMotors();
}

/*
 * Function that turns the tank to the left in place
 * 
 * <param name='power'> Power between 0 and 255, which will be used to move the motors</param>
 */
void TurnLeft (uint8_t power)
{
//  if (VerifyPower("Left", power)) return;
  SetMotors(MOTOR_CODE_LEFT, power);
  StartMotors();
}

/*
 * Function that turns the tank to the right in place
 * 
 * <param name='power'> Power between 0 and 255, which will be used to move the motors</param>
 */
void TurnRight (uint8_t power)
{
//   if (VerifyPower("Right", power)) return;
  SetMotors(MOTOR_CODE_RIGHT, power);
  StartMotors();
}

// Set the enable pins of both motors to LOW, abruptly stopping the motors. Then reset the motor speed of both motors to zero.
void StopMotors (void)
{
  digitalWrite(PIN_ENABLE_LEFT, LOW);
  digitalWrite(PIN_ENABLE_RIGHT, LOW);
  SetMotors(MOTOR_CODE_RESET, 0);
}

// Set the enable pins of both motors to HIGH so that it may run.
void StartMotors (void)
{
  digitalWrite(PIN_ENABLE_LEFT, HIGH);
  digitalWrite(PIN_ENABLE_RIGHT, HIGH);
}

// Set the motor speeds as function of the direction (as motor code MOTOR_CODE_*) and the power.
void SetMotors (uint8_t motor_code, uint8_t motor_power)
{
  for (uint8_t i = 0; i < NO_OF_DIRECTIONS; i++)
  {
    uint8_t motor_speed = ((motor_code >> i) & 0b1) * motor_power;
    analogWrite(motor_directions[i], motor_speed);
  }
}

// Verify whether the inputted value as power is admittable, therefore not lower than zero or higher than 255.
// Not necessary when the input has datatype uint8_t/8-bit, meaning the value is never higher than 255.
bool VerifyPower (String motor_direction, uint8_t motor_power)
{
  Serial.println("Invalid speed for moving " + motor_direction + ": " + motor_power); // Move to Communication Tab
  return (motor_power < 0 || motor_power > 255);
}
