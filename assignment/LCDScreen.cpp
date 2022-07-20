#include "LCDScreen.h"
#include <LiquidCrystal_I2C.h>
/*
* I2C address of the LCD: 0x27
*/
#define LCD_ADDRESS 0x27

/*
* Number of columns of LCD
*/
#define LCD_COLS 20

/*
* Number of rows of LCD
*/
#define LCD_ROWS 4

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

void LCDScreen::init() {
  lcd.init();
}

void LCDScreen::print(char* msg) {
  lcd.print(msg);
}

void LCDScreen::clear() {
  lcd.clear();
}

void LCDScreen::setCursor(int rows, int cols) {
    lcd.setCursor(rows, cols);
}

void LCDScreen::backlight() {
    lcd.backlight();
}