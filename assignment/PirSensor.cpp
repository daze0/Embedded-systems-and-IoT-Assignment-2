#include "PirSensor.h"
#include <Arduino.h>

const int calibrationTimeInSec = 10;

PirSensor::PirSensor(int pin) : AbstractSensor(pin) {
  this->calibrate(calibrationTimeInSec);
}

void PirSensor::calibrate(int calibrationTime) {
  Serial.println("Calibration starting..");
  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Calibration complete..");
}

double PirSensor::readValue() {
  int value = digitalRead(this->pin);
  return (double) value;
}