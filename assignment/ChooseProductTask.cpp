#include "ChooseProductTask.h"
#include "Button.h"
#include "Sensor.h"

ChooseProductTask::ChooseProductTask(Button* upBtn, Button* downBtn, Button* makeBtn, Sensor* potPin){

  this->upButton = upBtn;
  this->downButton = downBtn;
  this->makeButton = makeBtn;
  this->potSugar = potSugar;
}

ChooseProductTask::init(int period){

  Task::init(period);
  this->state = CP0;
}