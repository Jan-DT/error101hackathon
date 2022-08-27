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

void LeftTrack(int power) {
    if (power > 0) {
      digitalWrite(PIN_REVERSE_LEFT,0);
      digitalWrite(PIN_FORWARD_LEFT,1);
      SetMotors(MOTOR_CODE_FORWARD,power);
    };
    else if (power = 0) {
      digitalWrite(PIN_FORWARD_LEFT,0);
      digitalWrite(PIN_REVERSE_LEFT,0)
    };
    else if (power < 0) {
      digitalWrite(PIN_FORWARD_LEFT,0);
      digitalWrite(PIN_REVERSE_LEFT,1);
      SetMotors(MOTOR_CODE_REVERSE,-1*power);
    };
  }

void RightTrack(int power) {
  
}
