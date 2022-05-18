#ifndef __SLEEPTASK__
#define __SLEEPTASK__

#include "Task.h"
#include "Sensor.h"

class SleepTask: public Task {
public:
  SleepTask(SmartCoffeeMachine* machine, Sensor* pirSensor);
  void init(int period);
  void tick();
private:
  void goToSleep();
  enum {SL0, SL1} state;
  Sensor* pir;
  int elapsedTime;
  bool detected;
};

#endif