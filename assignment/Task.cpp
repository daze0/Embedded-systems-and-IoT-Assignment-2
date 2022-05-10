#include "Task.h"

Task::Task(SmartCoffeeMachine* machine) {
  this->machine = machine;
}

void Task::init(int period) {
  this->myPeriod = period;
}

bool Task::updateAndCheckTime(int basePeriod) {
  this->timeElapsed += basePeriod;
  if (this->timeElapsed >= this->myPeriod) {
    this->timeElapsed = 0;
    return true;
  } else {
    return false;
  }
}

bool Task::isActive() {
  return this->active;
}

void Task::setActive(bool active) {
  this->active = active;
}

SmartCoffeeMachine* Task::getMachine() {
  return this->machine;
}