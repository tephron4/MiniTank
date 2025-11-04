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
#include "SoftwareSerial.h"
#include "MeMegaPi.h"
#include "MePS2.h"

MeMegaPiDCMotor motor1(PORT1B);
MeMegaPiDCMotor motor2(PORT2B);

MePS2 MePS2(PORT_15);

void move(int speed, int direction)
{
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

void setup()
{
  MePS2.begin(115200);
}

void loop()
{
  move(MePS2.MeAnalog(4), MePS2.MeAnalog(6));

  MePS2.loop();
}

