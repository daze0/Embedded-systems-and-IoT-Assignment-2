#ifndef __POTENTIOMETERSENSOR__
#define __POTENTIOMETERSENSOR__

#include "AbstractSensor.h"

class PotentiometerSensor: public AbstractSensor {
public:
  PotentiometerSensor(int pin);
  double readValue();
};

#endif