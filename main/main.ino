//Source Code to a Smart-Car-Robot
//Tasks:
/* Make the library; Idea: MotorA(speedPin, Pin1, Pin2); UltrasonicSensor(trigPin, EchoPin);
   Organize the modes;
   Realize tests to verify the angle for time (Motors);
   Put new function "TurnAround();"
*/
#include <IRremote.h>
#include <RobotCar.h>
#include <Servo.h>

Servo servo;

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

float code;
unsigned char mode, on = 0, n = 1;

unsigned long last = millis();

#define echoPin 7
#define trigPin 8
#define ledPin  13

#define speedPinA 6
#define pinI1 4
#define pinI2 5

#define speedPinB 9
#define pinI3 10
#define pinI4 11

#define speedMotor 150
#define minDistance 5

#define forward 0xFF02FD
#define backward 0xFF9867
#define right 0xFF906F
#define left 0xFFE01F
#define brake 0xFFA857

#define modeIR 0xFF30CF
#define modeUltra 0xFF18E7
#define back 0xFFC23D

int ledStatus = 0;

int maxRange = 200;
int minRange = 0;
long distance;

Motors Robot(speedPinA, pinI1, pinI2, speedPinB, pinI3, pinI4);

void setup() {
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(speedPinA, OUTPUT);
  pinMode(pinI1, OUTPUT);
  pinMode(pinI2, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  pinMode(pinI3, OUTPUT);
  pinMode(pinI4, OUTPUT);

  servo.attach(3, 750, 2730);

  servo.write(88);
  delay(3000);

  irrecv.enableIRIn();
}

void loop() {
  /*Robot.Off();
  mode = SelectMode();

  switch (mode) {
    case 1:
      IRremoteMode();
      break;

    case 2:
      UltrasonicMode(minDistance);
      break;
  }
  n = 1;*/
  UltrasonicMode(minDistance);
}
