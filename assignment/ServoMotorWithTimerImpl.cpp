#include "AbstractServoMotor.h"
#include "ServoMotorWithTimer.h"
#include "ServoMotorWithTimerImpl.h"
#include "TimerOne.h"
#include "ServoMotor.h"
#define SEC_TO_USEC 1000000
#define MAX_PULSE 2750
const int maxAngle = 180;


ServoMotorWithTimerImpl::ServoMotorWithTimerImpl(ServoMotor* motor) : AbstractServoMotor(motor){
  
  this->motor = motor;
}

void ServoMotorWithTimerImpl::motorTick(){
  
  if(!this->motor->isAttached()){
    motor->on();
  }
  motor->setPosition(this->currentPosition);
  this->currentPosition++;
  if(motor->readPosition()==MAX_PULSE){
    Timer1.stop();  
    this->motorReset();      
  }
}

void ServoMotorWithTimerImpl::setupTimer(int Tmaking){
                
  long period = ((long) Tmaking / maxAngle) * SEC_TO_USEC;
  Timer1.initialize(period);
  Timer1.attachInterrupt( &motorTick );
}

void ServoMotorWithTimerImpl::startTimer(){
  
  Timer1.start();  
}

void ServoMotorWithTimerImpl::motorReset(){

  this->currentPosition = 0;
  this->motor->setPosition(this->currentPosition);
  this->motor->off();
}
