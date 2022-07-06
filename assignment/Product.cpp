#include "Product.h"

Product::Product(char* name, int quantity) {
    this->name = name;
    this->availability = quantity;
}

char* Product::getName() {
  return this->name;
}

int Product::getAvailability() {
  return this->availability;
}

void Product::pickUp() {
  this->availability--;
}

void Product::refill(int nMax) {
  this->availability = nMax;
}