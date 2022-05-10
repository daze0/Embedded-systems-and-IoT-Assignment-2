#ifndef __INITIALIZETASK__
#define __INITIALIZETASK__

#include "Task.h"

class InitializeTask {
public:
  InitializeTask(Sensor* pirSensor);
  void init(int period);
  void tick();
};

#endif