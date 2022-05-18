#include "Scheduler.h"
//#include <TimerMs.h>
#include <TimerOne.h>

//TimerMs timer;
volatile bool timerFlag;

void timerHandler() {
  timerFlag = true;
}

void Scheduler::init(int basePeriod) {
  this->basePeriod = basePeriod;
  timerFlag = false;
  long period = 1000l*this->basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
  this->nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
  if (this->nTasks < MAX_TASKS-1) {
    this->taskList[nTasks] = task;
    this->nTasks++;
    return true;
  } else {
    return false;
  }
}

void Scheduler::schedule() {
  while (!timerFlag) {}
  timerFlag = false;
  for(int i = 0; i < this->nTasks; i++) {
    if (this->taskList[i]->isActive() && this->taskList[i]->updateAndCheckTime(this->basePeriod)) {     //IsActive() possibly useless
      //Serial.println("Executing task" + String(i));
      this->taskList[i]->tick();
    }
  }
}