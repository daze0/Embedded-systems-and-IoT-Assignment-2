#ifndef __SMARTCOFFEEMACHINE__
#define __SMARTCOFFEEMACHINE__

class SmartCoffeeMachine {
public:
  bool productsAvailable();
  bool isReady();
  bool isMaking();
  void setReady(bool ready);
  void setMake(bool make);
  void refill();
private:
  int coffee;
  int tea;
  int chocolate;
  int sugar;
  bool ready;
  bool make;
};

#endif