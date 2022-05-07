#ifndef __TEMPERATURESENSOR__
#define __TEMPERATURESENSOR__

#include "AbstractSensor.h"

class TemperatureSensor: public AbstractSensor {
public:
  TemperatureSensor(int pin);
  double readValue();
};

#endif