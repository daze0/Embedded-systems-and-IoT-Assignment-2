#include "Servo2MotorImpl.h"
#include "Arduino.h"

const float coeff = (2750.0 - 400.0)/180;

Servo2MotorImpl::Servo2MotorImpl(int pin){
  this->pin = pin;
}

void Servo2MotorImpl::on(){
  this->motor.attach(pin);
}

void Servo2MotorImpl::off(){
  this->motor.detach();
}

void Servo2MotorImpl::setPosition(int angle){
  this->motor.write(400 + angle*coeff);    
}

int Servo2MotorImpl::readPosition(){
  return (int) ((this->motor.read() - 400) / coeff);
}

bool Servo2MotorImpl::isAttached(){
  return this->motor.attached();
}