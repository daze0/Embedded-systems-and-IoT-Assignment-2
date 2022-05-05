#ifndef __ABSTRACTSENSOR__
#define __ABSTRACTSENSOR__

#include "Sensor.h"

class AbstractSensor: public Sensor {
public:
  AbstractSensor(int pin);
  int readValue();
  float readValue();
private:
  int pin;
}

#endif