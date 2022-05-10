#include "MakeProductTask.h"

MakeProductTask::MakeProductTask(SmartCoffeeMachine* machine, Sensor* sonarSensor, Screen* lcdScreen, ServoMotor* motor) : Task(machine) {
  this->sonar = sonarSensor;
  this->lcdScreen = lcdScreen;
  this->motor = motor;
}
 
void MakeProductTask::init(int period) {
  Task::init(period);
} 

void MakeProductTask::tick() {}