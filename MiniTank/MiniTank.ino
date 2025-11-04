/**
 * @file    MiniTank.ino
 * @author  Tobias Ephron
 * @version V1.0.0
 * @date    11/03/2025
 * @brief   Description: this file is control code for a mini tank built
 *            from MakeBlock Ultimate 2.0
 *
 * \par History:
 * <pre>
 * <Author>         <Time>        <Version>      <Descr>
 * Tobias Ephron    11/03/2025    1.0.0          Control logic for mini tank built
 *                                                 from MakeBlock Ultimate 2.0
 * </pre>
 */
#include "MeMegaPi.h"
#include "MePS2.h"
#include "SoftwareSerial.h"

MeMegaPiDCMotor motor1(PORT1B);
MeMegaPiDCMotor motor2(PORT2B);

MePS2 MePS2(PORT_15);

MeUltrasonicSensor ultraSensor(PORT_6);

/**
 * Move the tank
 *
 * @param speed the base speed of the movement (pos = forward; neg = backward)
 * @param direction the right (pos) or left (neg) turn offset speed
 */
void move(int speed, int direction)
{
  // Serial.print("Moving with speed: ");
  // Serial.print(speed);
  // Serial.print(" and direction: ");
  // Serial.println(direction);
  int e1_speed = 0;
  int e2_speed = 0;
  if (speed != 0) {
    e1_speed += speed;
    e2_speed -= speed;
  }
  if (direction != 0) {
    e1_speed += direction;
    e2_speed += direction;
  }

  motor1.run(e1_speed);
  motor2.run(e2_speed);
}

/**
 * Check if there is an object in from of the tank
 *   and back away from the object if too close.
 */
bool checkFront() 
{
  // Serial.println(ultraSensor.distanceCm());
  if (ultraSensor.distanceCm() < 7.5) {
    // Serial.println("TOO CLOSE");
    return true;
  }

  return false;
}

void setup()
{
  MePS2.begin(115200);
  Serial.begin(9600);
}

void loop()
{
  if (!checkFront()) {
    move(MePS2.MeAnalog(4) * 0.7, MePS2.MeAnalog(6) * 0.70);
  } else {
    move(-180, 0);
  }

  MePS2.loop();
}

