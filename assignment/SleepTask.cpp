#include "SleepTask.h"
#include <Arduino.h>

#define T_IDLE 10000 //60000

SleepTask::SleepTask(SmartCoffeeMachine* machine, Sensor* pirSensor) : Task(machine) {
  this->pir = pirSensor;
}

void SleepTask::init(int period) {
  Task::init(period);
  this->elapsedTime = 0;
  this->detected = false;  // is it useful?
}

void SleepTask::tick() {
  switch (this->state) {
    case SL0:
      if (this->getMachine()->isReady()) {
        this->state = SL1;
      }
      break;
    case SL1:
      if (this->getMachine()->isReady()) {
        this->elapsedTime += this->myPeriod;
         if (this->pir->readValue() == 1.0) {
          this->elapsedTime = 0;
        } else if (this->elapsedTime >= T_IDLE) {
          this->state = SL2;
          this->getMachine()->setReady(false);
          //TODO: idle mode
          Serial.println("Sleep");
        }
      }
      break;
    case SL2:
      if (this->pir->readValue() == 1.0) {
        this->getMachine()->setReady(true);
        this->elapsedTime = 0;
        this->state = SL1;
      }
      break;
  }
}