#ifndef __SELFTESTTASK__
#define __SELFTESTTASK__

#include "Task.h"
#include "Sensor.h"
#include "ServoMotor.h"
#include "Screen.h"

class SelfTestTask: Task {
public:
  SelfTestTask(int tmpPin, int servoPin, int rsLCDPin, int enableLCDPin, int d4LCDPin, int d5LCDPin, int d6LCDPin, int d7LCDPin);
  void init(int period);
  void tick();
  bool updateAndCheckTime(int basePeriod);
  bool isActive();
  void setActive(bool active);
  ~SelfTestTask();
private:
  enum {ST0, ST1, ST2, ST3, ST4, ST5, AM} state;
  Sensor* temperatureSensor;
  ServoMotor* motor;
  Screen* lcdScreen;
};

#endif