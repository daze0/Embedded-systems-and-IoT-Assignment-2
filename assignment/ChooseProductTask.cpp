#include "ChooseProductTask.h"
#include "Button.h"
#include "Sensor.h"

ChooseProductTask::ChooseProductTask(SmartCoffeeMachine* machine, Button* upBtn, Button* downBtn, Button* makeBtn, Sensor* potPin, Screen* lcdScreen) : Task(machine) {
  this->upButton = upBtn;
  this->downButton = downBtn;
  this->makeButton = makeBtn;
  this->potSugar = potSugar;
  this->lcdScreen = lcdScreen;
}

void ChooseProductTask::init(int period) {
  Task::init(period);
  this->state = CP0;
}

void ChooseProductTask::tick() {
  switch(this->state){
    case CP0:
      this->getMachine()->setMake(false);      
      if(this->getMachine()->isReady()) {
        this->state = CP1;
      }
      break;
    case CP1:
      if(this->upButton->isPressed()) {

      }    
  }
}