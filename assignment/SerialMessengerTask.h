#ifndef __SERIALMESSENGERTASK__
#define __SERIALMESSENGERTASK__

#include "Task.h"
#include "SmartCoffeeMachine.h"

class SerialMessengerTask: public Task {
public:
  SerialMessengerTask(SmartCoffeeMachine* machine);
  void init(int period);
  void tick();
private:
  enum {SEND, RECV} state;
};

#endif