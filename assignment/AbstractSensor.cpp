#include "AbstractSensor.h"

AbstractSensor::AbstractSensor(int pin) {
  this->pin = pin;
}

int AbstractSensor::readValue() {
}