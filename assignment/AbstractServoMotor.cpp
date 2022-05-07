#include "AbstractServoMotor.h"
#include "ServoMotor.h"

AbstractServoMotor::AbstractServoMotor(ServoMotor motor){
  this->motor = motor;
}

AbstractServoMotor::on(){
  this->motor->on();    
}

AbstractServoMotor::off(){
  this->motor->off();    
}

AbstractServoMotor::setPosition(int angle){
  this->motor->setPosition(angle);    
}

AbstractServoMotor::readPosition(){
  return this->motor->readPosition();    
}
