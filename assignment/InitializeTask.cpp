#include "InitializeTask.h"
#include "Arduino.h"
#include "Screen.h"

InitializeTask::InitializeTask(SmartCoffeeMachine* machine, Screen* lcdScreen) : Task(machine) {
    this->lcdScreen = lcdScreen;
}

void InitializeTask::init(int period) {
    Task::init(period);
    this->state = I0;
}

void InitializeTask::tick() {
    switch (state) {
        case I0:
            Serial.println("I0");
            this->lcdScreen->setCursor(0, 1);
            this->lcdScreen->print("Welcome!");
            this->state = I1;
            break;
        case I1:
            Serial.println("I1");
            this->getMachine()->setReady(true);
            Serial.println("Ready -> true");
            this->lcdScreen->clear();
            this->lcdScreen->print("Ready.");
            this->setActive(false);
            break;
    }
}