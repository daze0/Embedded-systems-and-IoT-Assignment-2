#ifndef __SCHEDULER__
#define __SCHEDULER__

#define MAX_TASKS 50

#include "Task.h"

class Scheduler {
public:
  void init(int period);
  bool addTask(Task* task);
  void schedule();
private:
  int basePeriod;
  int nTasks;
  Task* taskList[MAX_TASKS];
};

#endif