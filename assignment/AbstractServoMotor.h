#ifndef __ABSTRACT_SERVO_MOTOR__
#define __ABSTRACT_SERVO_MOTOR__

#include "ServoMotor.h"

class AbstractServoMotor: public ServoMotor {

public:
  AbstractServoMotor(ServoMotor* motor);
  virtual void on();
  virtual void off();
  virtual void setPosition(int angle);
  virtual int readPosition();
  virtual bool isAttached();

protected:
  ServoMotor* motor;
};

#endif