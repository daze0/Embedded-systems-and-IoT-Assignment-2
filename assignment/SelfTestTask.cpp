#include "SelfTestTask.h"

SelfTestTask::SelfTestTask(SmartCoffeeMachine* machine, Sensor* tmpSensor, ServoMotor* motor, Screen* lcdScreen) : Task(machine) {
  this->temperatureSensor = tmpSensor;
  this->motor = motor;
  this->lcdScreen = lcdScreen;
}
  
void SelfTestTask::init(int period) {
  Task::init(period);
  this->rotationCounter = 0;
}
  
void SelfTestTask::tick() {
  switch(this->state) {
    case ST0:
      if (this->getMachine()->isReady()) {
        this->state = ST1;
      }
      break;
    case ST1:
      this->getMachine()->setReady(false);
      if (this->rotationCounter == 0) {
        this->state = ST2;
      } else if (this->rotationCounter == 1) {
        this->state = ST3;
      } else if (this->rotationCounter >= 2) {
        this->state = ST4;
      } else {
        Serial.println("[Error: wrong value for this->rotationCounter]");
      }
      break;
    case ST2:
      this->motor->setPosition(180);
      this->rotationCounter++;
      this->state = ST1;
      break;
    case ST3:
      this->motor->setPosition(0);
      this->rotationCounter++;
      this->state = ST1;
      break;
    case ST4:
      
      break;
  }
}