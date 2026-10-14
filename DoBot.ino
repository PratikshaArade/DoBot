#include <Servo.h>

Servo base_motor;
Servo arm_1;
Servo arm_2;
Servo claw;

// ---------------- Pin Assignment ----------------
#define BASE_PIN 9
#define ARM1_PIN 5
#define ARM2_PIN 6
#define CLAW_PIN 3

// Store Current Positions
int basePos = 90;
int arm1Pos = 90;
int arm2Pos = 90;
int clawPos = 90;

//------------------------------------------------
// Improved Smooth Movement
//------------------------------------------------
void smoothMoveServo(Servo &servo, int &currentPos, int targetPos, int speed)
{
  if (currentPos == targetPos) return;

  int step = (targetPos > currentPos) ? 1 : -1;

  while (currentPos != targetPos)
  {
    currentPos += step;

    // Ease-in / Ease-out motion
    servo.write(currentPos);

    int distance = abs(targetPos - currentPos);

    if (distance > 40)
      delay(speed);
    else if (distance > 20)
      delay(speed + 2);
    else if (distance > 10)
      delay(speed + 4);
    else
      delay(speed + 6);
  }
}

//------------------------------------------------
void calibration()
{
  smoothMoveServo(base_motor, basePos, 90, 8);
  delay(300);

  smoothMoveServo(arm_1, arm1Pos, 90, 8);
  delay(300);

  smoothMoveServo(arm_2, arm2Pos, 90, 8);
  delay(300);

  smoothMoveServo(claw, clawPos, 90, 8);
  delay(300);
}

//------------------------------------------------
void setup()
{
  Serial.begin(115200);

  base_motor.attach(BASE_PIN);
  arm_1.attach(ARM1_PIN);
  arm_2.attach(ARM2_PIN);
  claw.attach(CLAW_PIN);

  calibration();
}

//------------------------------------------------
void loop()
{
  calibration();
  delay(100);

  smoothMoveServo(claw, clawPos, 90, 15);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 150, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 32, 15);
  delay(500);

  smoothMoveServo(claw, clawPos, 150, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 60, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 120, 15);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 110, 15);
  delay(100);

  smoothMoveServo(base_motor, basePos, 80, 12);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 90, 10);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 90, 10);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 150, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 32, 15);
  delay(500);

  smoothMoveServo(claw, clawPos, 120, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 60, 20);
  delay(1000);

  smoothMoveServo(arm_1, arm1Pos, 120, 15);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 110, 15);
  delay(1000);

  smoothMoveServo(arm_1, arm1Pos, 90, 10);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 90, 10);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 150, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 32, 15);
  delay(500);

  smoothMoveServo(claw, clawPos, 150, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 60, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 120, 15);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 110, 15);
  delay(100);

  smoothMoveServo(arm_1, arm1Pos, 25, 15);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 120, 15);
  delay(500);

  smoothMoveServo(claw, clawPos, 150, 20);
  delay(500);

  smoothMoveServo(base_motor, basePos, 98, 12);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 90, 10);
  delay(500);

  smoothMoveServo(base_motor, basePos, 98, 10);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 150, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 32, 15);
  delay(500);

  smoothMoveServo(claw, clawPos, 90, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 60, 15);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 120, 15);
  delay(500);

  smoothMoveServo(arm_2, arm2Pos, 110, 15);
  delay(100);

  smoothMoveServo(arm_2, arm2Pos, 90, 10);
  delay(500);

  smoothMoveServo(base_motor, basePos, 98, 10);
  delay(500);

  smoothMoveServo(arm_1, arm1Pos, 90, 10);

  delay(3000);
}


dobot