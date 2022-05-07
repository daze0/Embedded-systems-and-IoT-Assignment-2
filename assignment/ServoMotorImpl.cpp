#include "ServoMotorImpl.h"
#include "Arduino.h"

ServoMotorImpl::ServoMotorImpl(int pin){
  this->pin = pin;
}

void ServoMotorImpl::on(){
  motor.attach(pin);
}

void ServoMotorImpl::off(){
  motor.detach();
}

void ServoMotorImpl::setPosition(int angle){
  float coeff = (2750.0-400.0)/180;
  motor.write(400 + angle*coeff);    
}

int ServoMotorImpl::readPosition(){
  return motor.read();
}

bool ServoMotorImpl::isAttached(){
  return motor.attached();
}