#ifndef __LCDSCREEN__
#define __LCDSCREEN__

#include "Screen.h"
#include <LiquidCrystal.h>

#define MAX_PINS 6

class LCDScreen: public Screen {
public:
  LCDScreen(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  void init();
  void print(char* msg, int row, int col);
  void clear();
private:
  LiquidCrystal* lcd;
};

#endif