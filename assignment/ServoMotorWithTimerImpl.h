#ifndef __SERVO_MOTOR_WITH_TIMER_IMPL__
#define __SERVO_MOTOR_WITH_TIMER_IMPL__

#include "ServoMotorWithTimer.h"
#include "AbstractServoMotor.h"
#include "ServoMotor.h"

class ServoMotorWithTimerImpl : AbstractServoMotor, ServoMotorWithTimer{

public:  
  ServoMotorWithTimerImpl(ServoMotor* motor);
  void setupTimer(int Tmaking, void (*isr)());
  void startTimer();
  void stopTimer();
  void motorReset();
  ServoMotor* getServoMotor();
};

#endif