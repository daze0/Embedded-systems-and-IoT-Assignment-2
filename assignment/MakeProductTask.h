#ifndef __MAKEPRODUCTTASK__
#define __MAKEPRODUCTTASK__

#include "Task.h"
#include "Sensor.h"
#include <LiquidCrystal_I2C.h>
#include "ServoMotor.h"

class MakeProductTask: public Task {
public:
  MakeProductTask(SmartCoffeeMachine* machine, Sensor* sonarSensor, LiquidCrystal_I2C* lcdScreen, ServoMotor* motor);
  void init(int period);
  void tick();
private:
  enum {MP0, MP1, MP2, MP3, MP4, MP5} state;
  Sensor* sonar;
  LiquidCrystal_I2C* lcdScreen;
  ServoMotor* motor;
  int elapsedTime;
};

#endif