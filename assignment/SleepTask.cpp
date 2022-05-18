#include "SleepTask.h"
#include <Arduino.h>
#include <avr/sleep.h>

#define T_IDLE 10000 //60000

bool detection = false;

SleepTask::SleepTask(SmartCoffeeMachine* machine, Sensor* pirSensor) : Task(machine) {
  this->pir = pirSensor;
}

void SleepTask::init(int period) {
  Task::init(period);
  this->elapsedTime = 0;
  this->state = SL0;
  this->detected = false;  // is it useful?
}

void wakeUp() {
  sleep_disable();
  detachInterrupt(0);
  detection = true;
  Serial.println("Wake up");
}

void SleepTask::tick() {
  switch (this->state) {
    case SL0:
      Serial.println("We're in SL0.");
      if (this->getMachine()->isReady()) {
        double value = this->pir->readValue();
        this->elapsedTime += this->myPeriod;
        if (value == 1.0) {
          Serial.println("SL0: detected, not going to sleep.");
          this->elapsedTime = 0;
          this->detected = true;
        } else if (this->elapsedTime >= T_IDLE) {
          Serial.println("SL0: T_IDLE expired, going to sleep.");
          this->elapsedTime = 0;
          this->state = SL1;
          this->detected = false;
          this->getMachine()->setReady(false);
          this->goToSleep();
        }
      }
      break;
    case SL1:
      Serial.println("SL1: sleeping");
      this->detected = detection;
      if (this->detected) {
        Serial.println("SL1: just woken up");
        this->getMachine()->setReady(true);
        this->elapsedTime = 0;
        this->state = SL0;
      }
      break;
  }
}

void SleepTask::goToSleep() {
  Serial.println("Going to Sleep");
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  attachInterrupt(0, wakeUp, HIGH);
  sleep_mode();
}