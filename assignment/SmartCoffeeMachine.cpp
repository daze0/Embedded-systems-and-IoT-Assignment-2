#include "SmartCoffeeMachine.h"
#define N_MAX 10

#define DIM_PROD 4
#include "Product.h"


SmartCoffeeMachine::SmartCoffeeMachine() {
    this->listOfProducts[0] = new Product("coffee", N_MAX);
    this->listOfProducts[1] = new Product("tea", N_MAX);
    this->listOfProducts[2] = new Product("chocolate", N_MAX);
    this->listOfProducts[3] = new Product("sugar", N_MAX);        
    this->assistance = false;
    // Sorry, I know. That's terrible
    this->productSelected = new Product(this->listOfProducts[0]->getName(), this->listOfProducts[0]->getAvailability());
    this->nSelfTests = 0;
    this->mode = "WORKING";//"ASSISTANCE";
    this->ready = false;
    this->make = false;
}

bool SmartCoffeeMachine::productsAvailable() {
    return (this->listOfProducts[0]->getAvailability() == 0) &&
        (this->listOfProducts[1]->getAvailability() == 0) &&
        (this->listOfProducts[2]->getAvailability() == 0);
}

bool SmartCoffeeMachine::isReady() {
    return this->ready;
}

bool SmartCoffeeMachine::isMaking() {
    return this->make;
}

void SmartCoffeeMachine::setReady(bool ready) {
    this->ready = ready;
    if (ready == true){
      this->make = false;
    }
}

void SmartCoffeeMachine::setMake(bool make) {
    this->make = make;
    if (make == true){
        this->ready = false;
    }
}

void SmartCoffeeMachine::refill() {
    for (int i = 0; i < DIM_PROD; i++){
        this->listOfProducts[i]->refill(N_MAX);
    }
}

void SmartCoffeeMachine::setAssistance(bool assistance) {
  this->assistance = assistance;
}

bool SmartCoffeeMachine::isInAssistanceMode() {
  return this->assistance;
}

void SmartCoffeeMachine::nextProduct() {
    //sorry again.
    if(productSelected == listOfProducts[0]){
        this->productSelected = listOfProducts[1];
    } else if(productSelected == listOfProducts[1]){
        this->productSelected = listOfProducts[2];
    } else if (productSelected == listOfProducts[2]) {
        this->productSelected = listOfProducts[3];
    } else {
        this->productSelected = listOfProducts[0];
    }
}

void SmartCoffeeMachine::previousProduct() {
      if(productSelected == listOfProducts[0]){
        this->productSelected = new Product(listOfProducts[3]->getName(), listOfProducts[3]->getAvailability());
    } else if(productSelected == listOfProducts[1]){
        this->productSelected = listOfProducts[0];
    } else if (productSelected == listOfProducts[2]) {
        this->productSelected = listOfProducts[1];
    } else {
        this->productSelected = listOfProducts[2];
    }
}

Product* SmartCoffeeMachine::getSelectedProduct(){
    return this->productSelected;
}

Product* SmartCoffeeMachine::getTea() {
  return this->listOfProducts[1];
}

Product* SmartCoffeeMachine::getCoffee() {
  return this->listOfProducts[0];
}

Product* SmartCoffeeMachine::getChocolate() {
  return this->listOfProducts[2];
}

Product* SmartCoffeeMachine::getSugar() {
  return this->listOfProducts[3];
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