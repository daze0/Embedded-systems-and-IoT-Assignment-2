#include "AbstractServoMotor.h"
#include "ServoMotorWithTimer.h"
#include "TimerOne.h"
#include "ServoMotor.h"
#define SEC_TO_USEC 1000000
#define MAX_PULSE 2750
const int maxAngle = 180;


ServoMotorWithTimerImpl::ServoMotorWithTimerImpl(ServoMotor motor) : AbstractServoMotor(motor){
  
  this->motor = motor;
}

ServoMotorWithTimerImpl::setupTimer(int Tmaking){
                
  long period = ((long) Tmaking / maxAngle) * SEC_TO_USEC;
  Timer1.initialize(period);
  Timer1.attachInterrupt(this->motorTick());
}

ServoMotorWithTimerImpl::startTimer(){
  
  Timer1.start();  
}

ServoMotorWithTimerImpl::motorTick(){
  
  if(!this->motor->isAttached()){
    motor->on();
  }
  motor->setPosition(this->currentPosition);
  this->currentPosition++;
  if(motor->readPosition()==MAX_PULSE){
    Tmaking = true;
    Timer1.stop();    
  }
}

ServoMotorWithTimerImpl::motorReset(){

  this->currentPosition = 0;
  this->motor->setPosiiton(this->currentPosition);
  this->motor->off();
}
