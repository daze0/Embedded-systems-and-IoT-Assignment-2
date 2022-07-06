#include "AbstractServoMotor.h"
#include "ServoMotorWithTimer.h"
#include "ServoMotorWithTimerImpl.h"
#include <TimerOne.h>                   // TODO: change timer
#include "ServoMotor.h"
#define SEC_TO_USEC 1000000
#define MAX_PULSE 2750
const int maxAngle = 180;


ServoMotorWithTimerImpl::ServoMotorWithTimerImpl(ServoMotor* motor) : AbstractServoMotor(motor) {
  this->motor = motor;
}

void ServoMotorWithTimerImpl::setupTimer(int Tmaking, void (*isr)()) { 
  long period = ((long) Tmaking / maxAngle) * SEC_TO_USEC;
  Timer1.initialize(period);
  Timer1.attachInterrupt(isr);
}

void ServoMotorWithTimerImpl::startTimer() {
  Timer1.start();  
}

void ServoMotorWithTimerImpl::stopTimer() {
  Timer1.stop();
}

void ServoMotorWithTimerImpl::motorReset() {
  this->motor->setPosition(0);
  this->motor->off();
}

ServoMotor* ServoMotorWithTimerImpl::getServoMotor() {
  return this->motor;
}