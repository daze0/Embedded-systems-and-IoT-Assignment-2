#include "SmartCoffeeMachine.h"
#define N_MAX 5

bool SmartCoffeeMachine::productsAvailable() {
  return (this->coffee == 0) && (this->tea == 0) && (this->chocolate == 0);
}

bool SmartCoffeeMachine::isReady() {
  return this->ready;
}

bool SmartCoffeeMachine::isMaking() {
  return this->make;
}

void SmartCoffeeMachine::setReady(bool ready) {
  this->ready = ready;
}

void SmartCoffeeMachine::setMake(bool make) {
  this->make = make;
}

void SmartCoffeeMachine::refill() {
  this->coffee = N_MAX;
  this->tea = N_MAX;
  this->chocolate = N_MAX;
}