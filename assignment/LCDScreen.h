#ifndef __LCDSCREEN__
#define __LCDSCREEN__

#include "Screen.h"
#include <LiquidCrystal_I2C.h>

#define MAX_PINS 6

class LCDScreen: public Screen {
public:
  LCDScreen(int address,int cols, int rows);
  void init();
  void print(char* msg);
  void setCursor(int rows, int cols);
  void backlight();
  void clear();
private:
  LiquidCrystal_I2C* lcd;
};

#endif