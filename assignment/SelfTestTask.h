#ifndef __SELFTESTTASK__
#define __SELFTESTTASK__

#include "Task.h"
#include "Sensor.h"
#include "ServoMotor.h"
#include <LiquidCrystal_I2C.h>

class SelfTestTask: public Task {
public:
  SelfTestTask(SmartCoffeeMachine* machine, Sensor* tmpSensor, ServoMotor* motor, LiquidCrystal_I2C* lcdScreen);
  void init(int period);
  void tick();
  ~SelfTestTask();
private:
  enum {ST0, ST1, ST2, ST3, ST4, AM} state;
  Sensor* temperatureSensor;
  ServoMotor* motor;
  LiquidCrystal_I2C* lcdScreen;
  int elapsedTime;
};

#endif