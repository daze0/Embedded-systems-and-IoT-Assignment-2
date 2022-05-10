#ifndef __CHOOSEPRODUCTTASK__
#define __CHOOSEPRODUCTTASK__

#include "Task.h"
#include "Button.h"
#include "Sensor.h"

class ChooseProductTask: Task {
public:
  ChooseProductTask(int upBtnPin, int downBtnPin, int makeBtnPin, int potPin);
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