#ifndef __SERVO_MOTOR_WITH_TIMER__
#define __SERVO_MOTOR_WITH_TIMER__

#include "ServoMotor.h"
class ServoMotor{

public:
  virtual void setupTimer(int Tmaking);
  virtual void startTimer();
};

#endif