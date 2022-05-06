#ifndef __PIRSENSOR__
#define __PIRSENSOR__

#include "AbstractSensor.h"

class PirSensor: public AbstractSensor {
public: 
  PirSensor(int pin);
  double readValue();
private:
  void calibrate(int calibrationTime);
};

#endif