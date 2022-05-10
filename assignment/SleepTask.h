#ifndef __SLEEPTASK__
#define __SLEEPTASK__

#include "Task.h"
#include "Sensor.h"

class SleepTask: Task {
public:
  SleepTask(Sensor* pirSensor);
  void init(int period);
  bool updateAndCheckTime(int basePeriod);
  bool isActive();
  void setActive(bool active);
  ~SleepTask();
private:
  enum {SL0, SL1, SL2, SL3} state;
  Sensor* pir;
};

#endif