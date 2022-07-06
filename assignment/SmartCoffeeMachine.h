#ifndef __SMARTCOFFEEMACHINE__
#define __SMARTCOFFEEMACHINE__

#include "Product.h"

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
    bool isInAssistanceMode();
    void nextProduct();
    void previousProduct();
    Product* getSelectedProduct();
    Product* getSugar();
    Product* getCoffee();
    Product* getTea();
    Product* getChocolate();
    /* getter and increaser for n self tests of machine */
    int getNSelfTests();
    void selfTest();
    /* Setter and getter for current machine mode */
    void setMode(char* mode);
    char* getMode();

private:
  Product* listOfProducts[4];
  volatile bool ready;
  volatile bool make;
  volatile bool assistance;
  Product* productSelected;
  int nSelfTests;
  char* mode;
};

#endif