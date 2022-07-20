#ifndef __LCDSCREEN__
#define __LCDSCREEN__

#include "Screen.h"

#define MAX_PINS 6

class LCDScreen: public Screen {
public:
  void init();
  void print(char* msg);
  void setCursor(int rows, int cols);
  void backlight();
  void clear();
};

#endif