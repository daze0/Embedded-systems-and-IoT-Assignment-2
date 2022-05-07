#include "AbstractServoMotor.h"
#include "ServoMotor.h"

AbstractServoMotor::AbstractServoMotor(ServoMotor* motor){
  this->motor = motor;
}

void AbstractServoMotor::on(){
  this->motor->on();    
}

void AbstractServoMotor::off(){
  this->motor->off();    
}

void AbstractServoMotor::setPosition(int angle){
  this->motor->setPosition(angle);    
}

int AbstractServoMotor::readPosition(){
  return this->motor->readPosition();    
}
