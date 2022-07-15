#ifndef __PRODUCT__
#define __PRODUCT__

class Product {
public:
  Product(char* name, int quantity);
  char* getName();
  int getAvailability();
  void pickUp();
  void refill(int nMax);
private:
  char* name;
  int availability;
};

#endif