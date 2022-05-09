#ifndef __SERVO_MOTOR_WITH_TIMER__
#define __SERVO_MOTOR_WITH_TIMER__

#include "ServoMotor.h"
class ServoMotorWithTimer {

public:
  virtual void setupTimer(int Tmaking, void (*isr)());
  virtual void startTimer();
  virtual void stopTimer();
};

#endif