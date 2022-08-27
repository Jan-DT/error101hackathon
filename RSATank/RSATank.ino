/*
   Please do not change the pin numbers, feel free to change the name of the constants!
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
   This function runs once and we have already implemented everything needed
   for the motors and the starting sensors. Be careful if you add/remove any
   hardware. If you need more information please check:

   https://www.arduino.cc/reference/en/language/structure/sketch/setup/
*/
void setup ()
{
  MotorSetup();
  SonarSetup();
  OpticalSetup();
  CommunicationSetup();
  Serial.begin(9600);
 
  String LEFT_READ_STR;
  String RIGHT_READ_STR;
  int LEFT_READ = digitalRead(PIN_OPTICAL_LEFT);
  int RIGHT_READ = digitalRead(PIN_OPTICAL_RIGHT);
  if (LEFT_READ == 1) {LEFT_READ_STR = "T";} else {LEFT_READ_STR = "F";};
  if (RIGHT_READ == 1) {RIGHT_READ_STR = "T";} else {RIGHT_READ_STR = "F";};
  String sit = LEFT_READ_STR + RIGHT_READ_STR;
  Serial.println(sit);
  while (sit == "FF"){
    LEFT_READ = digitalRead(PIN_OPTICAL_LEFT);
    RIGHT_READ = digitalRead(PIN_OPTICAL_RIGHT);
    if (LEFT_READ == 1) {LEFT_READ_STR = "T";} else {LEFT_READ_STR = "F";};
    if (RIGHT_READ == 1) {RIGHT_READ_STR = "T";} else {RIGHT_READ_STR = "F";};
    sit = LEFT_READ_STR + RIGHT_READ_STR;
    Serial.println(sit);
    MoveForward(100);
  }
  Serial.println("FOUND LINE ONE " + sit);
  delay(3000);
  sit = "FF";
  while (sit == "FF"){
    LEFT_READ = digitalRead(PIN_OPTICAL_LEFT);
    RIGHT_READ = digitalRead(PIN_OPTICAL_RIGHT);
    if (LEFT_READ == 1) {LEFT_READ_STR = "T";} else {LEFT_READ_STR = "F";};
    if (RIGHT_READ == 1) {RIGHT_READ_STR = "T";} else {RIGHT_READ_STR = "F";};
    sit = LEFT_READ_STR + RIGHT_READ_STR;
    Serial.println(sit);
    MoveForward(100);
  }
  Serial.println("FOUND LINE TWO " + sit);
  MoveForward(0);
  TurnLeft(100);
  delay(1000);
}
/*
   Put the code here that you want to run repeatedly.
*/
void loop (){
  // 0 = white,  1 = black
  String LEFT_READ_STR;
  String RIGHT_READ_STR;
  int LEFT_READ = digitalRead(PIN_OPTICAL_LEFT);
  int RIGHT_READ = digitalRead(PIN_OPTICAL_RIGHT);
  if (LEFT_READ == 1) {LEFT_READ_STR = "T";} else {LEFT_READ_STR = "F";};
  if (RIGHT_READ == 1) {RIGHT_READ_STR = "T";} else {RIGHT_READ_STR = "F";};
  String sit = LEFT_READ_STR + RIGHT_READ_STR;
  Serial.println(sit);  


  //Forward (Black)
  if (sit=="TT") {
    analogWrite(PIN_REVERSE_LEFT,0);
    analogWrite(PIN_REVERSE_RIGHT,0);
    analogWrite(PIN_FORWARD_LEFT,200);
    analogWrite(PIN_FORWARD_RIGHT,200);
  }
  //Right
  else if (sit=="FT") {
    analogWrite(PIN_REVERSE_LEFT,0);
    analogWrite(PIN_FORWARD_RIGHT,0);
    analogWrite(PIN_FORWARD_LEFT,200);
    analogWrite(PIN_REVERSE_RIGHT,20);
  }
  //Left
  else if (sit=="TF") {
    analogWrite(PIN_REVERSE_RIGHT,0);
    analogWrite(PIN_FORWARD_LEFT,0);
    analogWrite(PIN_FORWARD_RIGHT,200);
    analogWrite(PIN_REVERSE_LEFT,20);
  }
  //Forward (Right) (White)
  else if (sit=="FF") {
    analogWrite(PIN_REVERSE_LEFT,0);
    analogWrite(PIN_REVERSE_RIGHT,0);
    analogWrite(PIN_FORWARD_LEFT,220);
    analogWrite(PIN_FORWARD_RIGHT,70);
  }
  delay(50);
  //  CommunicationUpdate();
  //  CommunicationCheck();
}
