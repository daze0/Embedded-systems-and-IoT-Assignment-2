#ifndef __TASK__
#define __TASK__

#include "SmartCoffeeMachine.h"

class Task {
public:
  Task(SmartCoffeeMachine* machine);
  virtual void init(int period);
  virtual void tick() = 0;
  bool updateAndCheckTime(int basePeriod);
  bool isActive();
  void setActive(bool active);
protected:
  SmartCoffeeMachine* getMachine();
private:
  int myPeriod;
  int timeElapsed;
  bool active;
  SmartCoffeeMachine* machine;
};

#endif