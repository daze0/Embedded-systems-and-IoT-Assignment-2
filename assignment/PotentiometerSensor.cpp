#include "PotentiometerSensor.h"
#include <Arduino.h>

PotentiometerSensor::PotentiometerSensor(int pin) : AbstractSensor(pin) {}

double PotentiometerSensor::readValue() {
  int value = analogRead(this->pin);
  return (double) value;
}