#ifndef __ABSTRACTSENSOR__
#define __ABSTRACTSENSOR__

#include "Sensor.h"

class AbstractSensor: public Sensor {
public:
  AbstractSensor(int pin);
  virtual double readValue() = 0;
protected:
  int pin;
};

#endif