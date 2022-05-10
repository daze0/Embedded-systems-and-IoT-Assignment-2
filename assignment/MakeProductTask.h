#ifndef __MAKEPRODUCTTASK__
#define __MAKEPRODUCTTASK__

#include "Task.h"
#include "Sensor.h"
#include "Screen.h"
#include "ServoMotor.h"

class MakeProductTask: Task {
public:
  MakeProductTask(SmartCoffeeMachine* machine, Sensor* sonarSensor, Screen* lcdScreen, ServoMotor* motor);
  void init(int period);
  void tick();
  ~MakeProductTask();
private:
  enum {MP0, MP1, MP2, MP3, MP4, MP5} state;
  Sensor* sonar;
  Screen* lcdScreen;
  ServoMotor* motor;
};

#endif