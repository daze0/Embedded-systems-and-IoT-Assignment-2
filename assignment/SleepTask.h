#ifndef __SLEEPTASK__
#define __SLEEPTASK__

#include "Task.h"
#include "Sensor.h"

class SleepTask: Task {
public:
  SleepTask(SmartCoffeeMachine* machine, Sensor* pirSensor);
  void init(int period);
  void tick();
private:
  enum {SL0, SL1, SL2, SL3} state;
  Sensor* pir;
};

#endif