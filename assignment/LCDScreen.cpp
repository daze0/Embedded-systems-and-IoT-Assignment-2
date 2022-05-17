#include "LCDScreen.h"
#include <LiquidCrystal.h>

/* pins must be passed in order */
LCDScreen::LCDScreen(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) {
  this->lcd = new LiquidCrystal(rs, enable, d4, d5, d6, d7);
}

void LCDScreen::init() {
  this->lcd->begin(16, 1);
}

void LCDScreen::print(char* msg, int row, int col) {
  this->lcd->setCursor(col, row);
  this->lcd->print(msg);
}

void LCDScreen::clear() {
  this->lcd->clear();
}