#include "SelfTestTask.h"
#include "Arduino.h"

#define T_CHECK 180000

int currPos = 0;
double tempValue;

SelfTestTask::SelfTestTask(SmartCoffeeMachine* machine, Sensor* tmpSensor, ServoMotor* motor, Screen* lcdScreen) : Task(machine) {
  this->temperatureSensor = tmpSensor;
  this->motor = motor;
  this->lcdScreen = lcdScreen;
}
  
void SelfTestTask::init(int period) {
  Task::init(period);
  this->elapsedTime = -1;
  this->state = ST0;
}
  
void SelfTestTask::tick() {
  switch(this->state) {
    case ST0:
      Serial.println("ST0");
      if (this->getMachine()->isReady()) {
        this->state = ST1;
        this->elapsedTime = 0;
      }
      break;
    case ST1:
      Serial.println("ST1");
      this->elapsedTime += this->myPeriod;
      if (this->elapsedTime >= T_CHECK) {
        this->state = ST2;
        this->getMachine()->setReady(false);
        this->motor->on();
        this->motor->setPosition(0);
      } else if (!this->getMachine()->isReady()) {
        this->elapsedTime = 0;
        this->state = ST0;
      } else {
        Serial.println("[Note: timer NOT expired]");
      }
      break;
    case ST2:
      Serial.println("ST2");
      {
        //currPos = this->motor->readPosition();
      }
      Serial.println("currPos: " + String(this->motor->readPosition()));
      if (this->motor->readPosition() < 180) {
        currPos += 5;
        this->motor->setPosition(currPos);
      } else {
        this->state = ST3;
      }
      break;
    case ST3:
      Serial.println("ST3");
      {
        //currPos = this->motor->readPosition();
      }
      if (this->motor->readPosition() > 0) {
        currPos -= 5;        
        this->motor->setPosition(currPos);
      } else {
        this->state = ST2;
      }
      break;
    case ST4:
      Serial.println("ST4");
      tempValue = this->temperatureSensor->readValue();
      if (tempValue < 17 || tempValue > 24) {
        this->state = AM;
        this->getMachine()->setAssistance(true);
        this->lcdScreen->clear();
        this->lcdScreen->print("Assistance required!");
      } else {
        this->state = ST0;
        this->getMachine()->setReady(true);
        this->motor->off();
      }
      break;
    case AM:
      Serial.println("AM");
      if (!this->getMachine()->isInAssistanceMode()) {
        this->state = ST0;
        this->getMachine()->setReady(true);
        this->motor->off();
      }
      break;
  }
}