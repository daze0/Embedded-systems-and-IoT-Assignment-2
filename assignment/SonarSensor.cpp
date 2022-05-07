#include "SonarSensor.h"
#include <Arduino.h>

/* valid for temperature of 20°C */
const double vs = 331.45 + 0.62*20;

SonarSensor::SonarSensor(int trigPin, int echoPin) : AbstractSensor(trigPin) {
  this->echoPin = echoPin;
}

void SonarSensor::sendImpulse() {
  digitalWrite(this->pin, LOW);
  delayMicroseconds(3);
  digitalWrite(this->pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->pin, LOW);
}

double SonarSensor::readValue() {
  /* sending impulse */
  this->sendImpulse();

  /* receiving the eco */
  float tUS = pulseIn(this->echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float d = t*vs;
  return (double) d; 
}