#ifndef __ABSTRACTBUTTON__
#define __ABSTRACTBUTTON__

#include "Button.h"

class AbstractButton: public Button{

public:
  AbstractButton(int pin);
  bool isPressed();
  void sync();

private:
  int pin;
  bool pressed;

};

#endif