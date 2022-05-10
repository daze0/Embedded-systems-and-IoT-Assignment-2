#include "SleepTask.h"

SleepTask::SleepTask(SmartCoffeeMachine* machine, Sensor* pirSensor) : Task(machine) {
  this->pir = pirSensor;
}

void SleepTask::init(int period) {
  Task::init(period);
}

void SleepTask::tick() {}