#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "ServoMotor.h"
#include "Arduino.h"
#include "ServoTimer2.h"

class Servo2MotorImpl: public ServoMotor{

public:
  Servo2MotorImpl(int pin);

  void on();
  void off();
  void setPosition(int angle);
  int readPosition();
  bool isAttached();

private:
  int pin;
  ServoTimer2 motor;
};

#endif