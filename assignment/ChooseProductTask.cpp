#include "ChooseProductTask.h"
#include "Button.h"
#include "Sensor.h"

ChooseProductTask::ChooseProductTask(Button* upBtn, Button* downBtn, Button* makeBtn, Sensor* potPin, LCDScreen* screenLCd){

  this->upButton = upBtn;
  this->downButton = downBtn;
  this->makeButton = makeBtn;
  this->potSugar = potSugar;
  this->screen = screenLCD;
}

ChooseProductTask::init(int period){

  Task::init(period);
  this->state = CP0;
}

ChooseProductTask::tick(){

  switch(this->state){
    case CPO:
      this->getMachine()->setMake(false);      
      if(this->getMachine()->isReady()){
        this->state = CP1;
      }
      break;
    case CP1:
      if(this->upButton->isPressed())      
        
  }
}