#include "TemperatureSensor.h"
#include <Arduino.h>

TemperatureSensor::TemperatureSensor(int pin) : AbstractSensor(pin) {}

// Same as above but without int conversion in return.
double TemperatureSensor::readValue() {
  int value = analogRead(this->pin);

  /* value : 1023 = value_in_mV : 5000 */
  /* value_in_mV = 5000/1023 * value */
  int value_in_mV = 4.8876 * value; 

  /* value_in_C = value_in_mV / 10 (since we have 10 mV => 1 °C ) */
  double value_in_C = (value_in_mV * 0.1) - 50;

  return value_in_C;
}