#include "InitializeTask.h"
#include "Arduino.h"
#define T_WELCOME 3000

InitializeTask::InitializeTask(SmartCoffeeMachine* machine, Screen* lcdScreen) : Task(machine) {
  this->lcdScreen = lcdScreen;
}

void InitializeTask::init(int period) {
  Task::init(period);
  this->state = I0;
  this->time0 = -1;
}

void InitializeTask::tick() {
  switch (state) {
    case I0:
      if (time0 == -1) {
        time0 = millis();
      } else {
        int elapsedTime = millis() - time0;
        if (elapsedTime >= T_WELCOME) {
          this->state = I1;
        } else {
          this->lcdScreen->print("Welcome!", 2, 1);
        }
      }
      break;
    case I1:
      this->getMachine()->setReady(true);
      this->lcdScreen->print("Ready.", 2, 1);
      break;
  }
}