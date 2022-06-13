#include "SmartCoffeeMachine.h"
#define N_MAX 5

SmartCoffeeMachine::SmartCoffeeMachine() {
  this->coffee = 0;//N_MAX;
  this->tea = 0;//N_MAX;
  this->chocolate = 0;//N_MAX;
  this->sugar = 0;//N_MAX;
  this->nSelfTests = 0;
  this->mode = "WORKING";
  this->ready = false;
  this->make = false;
  this->assistance = true;//false;
}

int SmartCoffeeMachine::getTea() {
  return this->tea;
}

int SmartCoffeeMachine::getCoffee() {
  return this->coffee;
}

int SmartCoffeeMachine::getChocolate() {
  return this->chocolate;
}

int SmartCoffeeMachine::getSugar() {
  return this->sugar;
}

int SmartCoffeeMachine::getNSelfTests() {
  return this->nSelfTests;
}

void SmartCoffeeMachine::selfTest() {
  this->nSelfTests++;
}

void SmartCoffeeMachine::setMode(char* mode) {
  this->mode = mode;
}

char* SmartCoffeeMachine::getMode() {
  return this->mode;
}

bool SmartCoffeeMachine::productsAvailable() {
  return !((this->coffee == 0) && (this->tea == 0) && (this->chocolate == 0));
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

void SmartCoffeeMachine::setAssistance(bool assistance) {
  this->assistance = assistance;
}

bool SmartCoffeeMachine::isInAssistanceMode() {
  return this->assistance;
}