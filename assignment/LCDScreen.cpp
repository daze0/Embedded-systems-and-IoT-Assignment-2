#include "LCDScreen.h"

/* pins must be passed in order */
LCDScreen::LCDScreen(int address,int cols, int rows) {
  this->lcd = new LiquidCrystal_I2C(address, cols, rows);
}

void LCDScreen::init() {
  this->lcd->init();
}

void LCDScreen::print(char* msg) {
  this->lcd->print(msg);
}

void LCDScreen::clear() {
  this->lcd->clear();
}

void LCDScreen::setCursor(int rows, int cols) {
    this->lcd->setCursor(rows, cols);
}

void LCDScreen::backlight() {
    this->lcd->backlight();
}