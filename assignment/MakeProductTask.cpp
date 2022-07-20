#include "MakeProductTask.h"
#include <Arduino.h>

#define T_TIMEOUT 5000 // 5000 ms
#define USER_DISTANCE 40 // 40 cm

String message_01;
String message_02;

MakeProductTask::MakeProductTask(SmartCoffeeMachine* machine, Sensor* sonarSensor, Screen* lcdScreen, ServoMotor* motor) : Task(machine) {
    this->sonar = sonarSensor;
    this->lcdScreen = lcdScreen;
    this->motor = motor;
    this->elapsedTime = 0;
    Serial.println("Aooo in constr MKPT");  
}

void MakeProductTask::init(int period) {
    Task::init(period);
    this->state = MP0;
    this->lcdScreen->init();
    this->lcdScreen->backlight();
    this->lcdScreen->setCursor(2, 1);
    this->lcdScreen->print("Hello: init");
}

void MakeProductTask::tick() {
    switch (this->state) {
        case MP0:
            Serial.println("MP0");
            this->getMachine()->setMake(true);
            if(this->getMachine()->isMaking()){
                // Necessary TEST
                message_01 = String("making a ");
                message_01 += this->getMachine()->getSelectedProduct()->getName();
                message_01 += "...";
                int totalSize = message_01.length();
                char* msg_01;
                message_01.toCharArray(msg_01, totalSize);
                this->lcdScreen->clear();
                //this->lcdScreen->setCursor(2, 1);
                this->lcdScreen->print(msg_01);
                this->state = MP1;
                if(!motor->isAttached()) {
                    this->motor->on();
                }              
            }
            break;
        case MP1:
            Serial.println("MP1");
            Serial.println(this->motor->readPosition());
            if(this->motor->readPosition() >= 180){
                this->state = MP2;
            } else {
                int nextPos = this->motor->readPosition() + 2;
                this->motor->setPosition(nextPos);
            }
            break;
        case MP2:
            Serial.println("MP2");
            this->state = MP3;
            message_02 = String("The ");
            message_02 += this->getMachine()->getSelectedProduct()->getName();
            message_02 +=" is ready.";            
            char* msg_02;
            int totalDim; 
            totalDim = message_02.length();
            message_02.toCharArray(msg_02, totalDim);
            this->lcdScreen->print(msg_02);            
            break;
        case MP3:
            Serial.println("MP3");
            this->elapsedTime += this->myPeriod;
            if (this->elapsedTime >= T_TIMEOUT || this->sonar->readValue() >= USER_DISTANCE) {
                this->motor->setPosition(0);
                this->motor->off();
                this->getMachine()->setReady(true);
                this->lcdScreen->print("Ready!");
                this->state = MP0;
            }
            break;
  }  
}