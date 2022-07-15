#ifndef __INITIALIZETASK__
#define __INITIALIZETASK__

#include "Task.h"
#include "LiquidCrystal_I2C.h"

class InitializeTask: public Task {
public:
  InitializeTask(SmartCoffeeMachine* machine, LiquidCrystal_I2C* lcdScreen);
  void init(int period);
  void tick();
private:
  enum {I0, I1} state;
  LiquidCrystal_I2C* lcdScreen;
};

#endif