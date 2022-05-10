#include "SelfTestTask.h"

SelfTestTask::SelfTestTask(SmartCoffeeMachine* machine, Sensor* tmpSensor, ServoMotor* motor, Screen* lcdScreen) : Task(machine) {
  this->temperatureSensor = tmpSensor;
  this->motor = motor;
  this->lcdScreen = lcdScreen;
}
  
void SelfTestTask::init(int period) {
  Task::init(period);
}
  
void SelfTestTask::tick() {

}