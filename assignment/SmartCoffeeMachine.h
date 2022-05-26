#ifndef __SMARTCOFFEEMACHINE__
#define __SMARTCOFFEEMACHINE__

class SmartCoffeeMachine {
public:
  SmartCoffeeMachine();
  bool productsAvailable();
  bool isReady();
  bool isMaking();
  void setReady(bool ready);
  void setMake(bool make);
  void refill();
  void setAssistance(bool assistance);
  bool IsInAssistanceMode();
private:
  int coffee;
  int tea;
  int chocolate;
  int sugar;
  volatile bool ready;
  volatile bool make;
  volatile bool assistance;
};

#endif