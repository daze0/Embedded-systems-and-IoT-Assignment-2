#ifndef __SMARTCOFFEEMACHINE__
#define __SMARTCOFFEEMACHINE__

class SmartCoffeeMachine {
public:
  SmartCoffeeMachine();
  int getCoffee();
  int getTea();
  int getChocolate();
  int getSugar();
  /* getter and increaser for n self tests of machine */
  int getNSelfTests();
  void selfTest();
  /* Setter and getter for current machine mode */
  void setMode(char* mode);
  char* getMode();
  bool productsAvailable();
  bool isReady();
  bool isMaking();
  void setReady(bool ready);
  void setMake(bool make);
  void refill();
  void setAssistance(bool assistance);
  bool isInAssistanceMode();
private:
  int coffee;
  int tea;
  int chocolate;
  int sugar;
  int nSelfTests;
  char* mode;
  volatile bool ready;
  volatile bool make;
  volatile bool assistance;
};

#endif