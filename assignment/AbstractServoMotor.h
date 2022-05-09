#ifndef __ABSTRACT_SERVO_MOTOR__
#define __ABSTRACT_SERVO_MOTOR__

#include "ServoMotor.h"

class AbstractServoMotor: public ServoMotor {

public:
  AbstractServoMotor(ServoMotor* motor);
  void on();
  void off();
  void setPosition(int angle);
  int readPosition();
  bool isAttached();

protected:
  ServoMotor* motor;
};

#endif