#ifndef __CHOOSEPRODUCTTASK__
#define __CHOOSEPRODUCTTASK__

#include "Task.h"
#include "Button.h"
#include "Sensor.h"
#include "Screen.h"

class ChooseProductTask: Task {
public:
  ChooseProductTask(SmartCoffeeMachine* machine, Button* upBtn, Button* downBtn, Button* makeBtn, Sensor* potSugar, Screen* screenLCD);
  void init(int period);
  void tick();
private:
  enum {CP0, CP1, CP2, CP3, AM} state;
  Button* upButton;
  Button* downButton;
  Button* makeButton;
  Sensor* potSugar;    
  Screen* lcdScreen;
};

#endif