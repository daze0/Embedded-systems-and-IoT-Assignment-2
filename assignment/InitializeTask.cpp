#include "InitializeTask.h"
#include "Arduino.h"

InitializeTask::InitializeTask(SmartCoffeeMachine* machine, Screen* lcdScreen) : Task(machine) {
  this->lcdScreen = lcdScreen;
}

void InitializeTask::init(int period) {
  Task::init(period);
  this->state = I0;
}

void InitializeTask::tick() {
  switch (state) {
    case I0:
      this->lcdScreen->print("Welcome!", 2, 1);
      this->state = I1;
      break;
    case I1:
      this->getMachine()->setReady(true);
      this->lcdScreen->clear();
      this->lcdScreen->print("Ready.", 2, 1);
      this->setActive(false);
      break;
  }
}