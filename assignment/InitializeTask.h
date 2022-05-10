#ifndef __INITIALIZETASK__
#define __INITIALIZETASK__

#include "Task.h"
#include "Screen.h"

class InitializeTask: Task {
public:
  InitializeTask(SmartCoffeeMachine* machine, Sensor* pirSensor);
  void init(int period);
  void tick();
private:
  enum {I0, I1} state;
  Screen* lcdScreen;
};

#endif