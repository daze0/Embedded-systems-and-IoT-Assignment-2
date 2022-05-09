#ifndef __MAKEPRODUCTTASK__
#define __MAKEPRODUCTTASK__

#include "Task.h"
#include "Sensor.h"
#include "Screen.h"
#include "ServoMotor.h"

class MakeProductTask {
public:
  MakeProductTask(int sonarPin, int rsLCDPin, int enableLCDPin, int d4LCDPin, int d5LCDPin, int d6LCDPin, int d7LCDPin, int motorPin);
  void init(int period);
  void tick();
  bool updateAndCheckTime(int basePeriod);
  bool isActive();
  void setActive(bool active);
  ~MakeProductTask();
private:
  enum {MP0, MP1, MP2, MP3, MP4, MP5} state;
  Sensor* sonar;
  Screen* lcdScreen;
  ServoMotor* motor;
};

#endif