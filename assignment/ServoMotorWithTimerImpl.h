#ifndef __SERVO_MOTOR_WITH_TIMER_IMPL__
#define __SERVO_MOTOR_WITH_TIMER_IMPL__

#include "ServoMotorWithTimer.h"
#include "AbstractServoMotor.h"
#include "ServoMotor.h"

class ServoMotorWithTimerImpl : AbstractServoMotor, ServoMotorWithTimer{

public:  
  ServoMotorWithTimerImpl(ServoMotor* motor);
  void setupTimer(int Tmaking);
  void startTimer();

private:
  void motorTick();
  void motorReset();
  int currentPosition;
};

#endif