#include "InitializeTask.h"
#include "Arduino.h"
#include "LiquidCrystal_I2C.h"

InitializeTask::InitializeTask(SmartCoffeeMachine* machine, LiquidCrystal_I2C* lcdScreen) : Task(machine) {
  this->lcdScreen = lcdScreen;
}

void InitializeTask::init(int period) {
  Task::init(period);
  this->state = I0;
}

void InitializeTask::tick() {
  switch (state) {
    case I0:
      this->lcdScreen->print("Welcome!");
      this->state = I1;
      break;
    case I1:
      this->getMachine()->setReady(true);
      this->lcdScreen->clear();
      this->lcdScreen->print("Ready.");
      this->setActive(false);
      break;
  }
}