#ifndef __MAKEPRODUCTTASK__
#define __MAKEPRODUCTTASK__

#include "Task.h"
#include "Sensor.h"
#include "Screen.h"
#include "ServoMotor.h"

class MakeProductTask: public Task {
public:
  MakeProductTask(SmartCoffeeMachine* machine, Sensor* sonarSensor, Screen* lcdScreen, ServoMotor* motor);
  void init(int period);
  void tick();
private:
  enum {MP0, MP1, MP2, MP3} state;
  Sensor* sonar;
  Screen* lcdScreen;
  ServoMotor* motor;
  int elapsedTime;
};

#endif