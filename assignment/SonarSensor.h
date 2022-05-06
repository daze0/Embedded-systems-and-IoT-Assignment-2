#ifndef __SONARSENSOR__
#define __SONARSENSOR__

#include "AbstractSensor.h"

class SonarSensor: public AbstractSensor {
public:
  SonarSensor(int trigPin, int echoPin);  
  double readValue();
private:
  int echoPin;
  void sendImpulse();
};

#endif