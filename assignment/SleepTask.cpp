#include "SleepTask.h"
#include <Arduino.h>
#include <avr/sleep.h>

#define T_IDLE 60000

SleepTask::SleepTask(SmartCoffeeMachine* machine, Sensor* pirSensor) : Task(machine) {
  this->pir = pirSensor;
}

void SleepTask::init(int period) {
  Task::init(period);
  this->elapsedTime = 0;
  this->state = SL0;
  this->detected = false;
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
          this->getMachine()->setReady(false);
          this->goToSleep();
        }
      }
      break;
    case SL1:
      double value = this->pir->readValue();
      this->detected = (value == 1.0) ? true : false;
      Serial.println("SL1: sleeping; detected="+String(this->detected));
      if (this->detected) {
        sleep_disable();
        Serial.println("Wake up");
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
  sleep_mode();
}