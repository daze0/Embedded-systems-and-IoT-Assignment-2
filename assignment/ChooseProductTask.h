#ifndef __CHOOSEPRODUCTTASK__
#define __CHOOSEPRODUCTTASK__

#include "Task.h"
#include "Button.h"
#include "Sensor.h"

class ChooseProductTask: Task{
public:
  ChooseProductTask(Button* upBtn, Button* downBtn, Button* makeBtn, Sensor* potSugar);
  void init(int period);
  void tick();
  ~ChooseProductTask();
private:
  enum {CP0, CP1, CP2, CP3, AM} state;
  Button* upButton;
  Button* downButton;
  Button* makeButton;
  Sensor* potSugar;    
};

#endif