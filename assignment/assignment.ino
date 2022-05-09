#include "ServoMotorWithTimerImpl.h"
#include "ServoMotorImpl.h"

#define TMAKING 5
#define MAX_PULSE 2750

ServoMotorWithTimerImpl* motorWithTimer = new ServoMotorWithTimerImpl(new ServoMotorImpl(2));
int currPos = 0;

void setup() {
  Serial.begin(9600);
  motorWithTimer->setupTimer(TMAKING, motorTick);
  motorWithTimer->startTimer();
}

void loop() {

}

void motorTick() {
  if(!motorWithTimer->getServoMotor()->isAttached()){
    motorWithTimer->getServoMotor()->on();
  }
  motorWithTimer->getServoMotor()->setPosition(currPos++);
  if(motorWithTimer->getServoMotor()->readPosition()==MAX_PULSE){
    motorWithTimer->stopTimer();  
    motorWithTimer->motorReset();     
    currPos = 0; 
  }
}