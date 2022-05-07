#ifndef __ABSTRACT_SERVO_MOTOR__
#define __ABSTRACT_SERVO_MOTOR__

#include "ServoMotor.h"
#include "Arduino.h"
#include "ServoTimer2.h"

class AbstractServoMotor: public ServoMotor{

public:
  AbstractServoMotor(ServoMotor* motor);

  void on();
  void off();
  void setPosition(int angle);
  int readPosition();

protected:
  ServoMotor* motor;
};

#endif