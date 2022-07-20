#include "ChooseProductTask.h"
#include "Button.h"
#include "Sensor.h"
#include <EnableInterrupt.h>

#define T_CHOOSE 5000 // ms

ChooseProductTask::ChooseProductTask(SmartCoffeeMachine* machine, Button* upBtn, Button* downBtn, Button* makeBtn, Sensor* potSugar, Screen* lcdScreen) : Task(machine) {
    this->upButton = upBtn;
    this->downButton = downBtn;
    this->makeButton = makeBtn;
    this->potSugar = potSugar;
    this->lcdScreen = lcdScreen;
    this->elapsedTime = 0;
}

void ChooseProductTask::init(int period) {
    Task::init(period);
    this->state = CP0;
    // This istruction may be superflous
    this->lcdScreen->init();
}

void ChooseProductTask::tick() {
    this->upButton->sync();
    this->downButton->sync();
    this->makeButton->sync();
    switch(this->state){
        case CP0:     
            if(this->getMachine()->isReady()) {
                this->state = CP1;
            }
            break;
        case CP1:
            this->elapsedTime += this->myPeriod;
            if(this->upButton->isPressed()) {
                this->elapsedTime = 0;
                this->getMachine()->nextProduct();
                this->lcdScreen->print(this->getMachine()->getSelectedProduct()->getName());
            } else if(this->downButton->isPressed()) {
                this->getMachine()->previousProduct();
                this->lcdScreen->print(this->getMachine()->getSelectedProduct()->getName());
            } else if(this->makeButton->isPressed()) {
                if (this->getMachine()->productsAvailable() && this->getMachine()->getSelectedProduct()->getAvailability() > 0) {
                    this->getMachine()->setMake(true);
                    int totSugar = (int) this->potSugar->readValue();
                    for (int i = 0; i <= totSugar; i++) {
                        if(this->getMachine()->getSugar()->getAvailability() > 0) {
                            this->getMachine()->getSugar()->pickUp();
                        } else {
                          break;
                        }   
                    }
                    this->state = CP0;
                } else {
                    this->state = AM;
                    this->getMachine()->setReady(false);
                }
            } else if(this->elapsedTime >= T_CHOOSE){
                this->lcdScreen->clear();
                this->lcdScreen->print("Ready!");
                this->elapsedTime = 0;
            }
            break;
        case AM:
            if (this->getMachine()->productsAvailable()){
              this->state = CP1;
              this->getMachine()->setReady(true);
            }

    }
}