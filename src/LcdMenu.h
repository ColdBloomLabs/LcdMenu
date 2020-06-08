#ifndef LcdMenu_H
#define LcdMenu_H
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "MenuItem.h"
//
// the LcdMenu class
//
class LcdMenu {
   private:
    //
    // cursor position
    //
    uint8_t cursorPosition = 1;
    //
    // first visible item's position in the menu array
    //
    uint8_t top = 1;
    //
    // last visible item's position in the menu array
    //
    uint8_t bottom;
    //
    // rows of LCD Display
    //
    uint8_t maxRows;
    //
    // columns of LCD Display
    //
    uint8_t maxCols;
    //
    // array of menu items
    //
    MenuItem* currentMenuTable;
    //
    // down arrow (↓)
    //
    byte downArrow[8] = {
        0b00100,  //   *
        0b00100,  //   *
        0b00100,  //   *
        0b00100,  //   *
        0b00100,  //   *
        0b10101,  // * * *
        0b01110,  //  ***
        0b00100   //   *
    };
    //
    // up arrow (↑)
    //
    byte upArrow[8] = {
        0b00100,  //   *
        0b01110,  //  ***
        0b10101,  // * * *
        0b00100,  //   *
        0b00100,  //   *
        0b00100,  //   *
        0b00100,  //   *
        0b00100   //   *
    };
    //
    // this function draws the cursor
    //
    void drawCursor();
    //
    // this function draws the menu items with up and down indicators
    //
    void drawMenu();
    //
    // this function checks if the cursor is at the start of the menu items
    //
    boolean isAtTheStart();
    //
    // this function checks if the cursor is at the end of the menu items
    //
    boolean isAtTheEnd();
    //
    // call this function to draw the menu items and cursor
    //
    void paint();
    //
    // call this function to reset the display
    //
    void reset();
    //
    // place cursor at end of text
    //  item: MenuItem = menu item which contains an input value
    //
    void placeCursorAtEnd(MenuItem* item);

   public:
    //
    // LCD Display
    //
    LiquidCrystal_I2C* lcd;
    //
    // constructor for the LcdMenu class
    //  Enter:  maxRows = rows on lcd display e.g. 4
    //          maxCols = columns on lcd display e.g. 20
    //
    LcdMenu(uint8_t maxRows, uint8_t maxCols);
    //
    // call this function in setup() to initialize the LCD and the custom
    // characters used as up and down arrows
    //  Enter:  lcd_Addr = address of the LCD on the I2C bus (default 0x27)
    //          menu     = menu to display
    //
    void setupLcdWithMenu(uint8_t lcd_Addr, MenuItem* menu);
    //
    // TODO: Rename setMenuItemsAt function
    //
    void setMenuItemsAt(uint8_t position, MenuItem* items);
    //
    // builder function for a sub menu
    // this functions appends a header and a footer to the final item list
    //  items = array of MenuItems for the sub menu
    //  size  = size of items array
    //
    MenuItem* buildSubMenu(MenuItem* items, uint8_t size);
    //
    // call this function to execute an "up press"
    //
    void up();
    //
    // call this function to execute a "down press"
    //
    void down();
    //
    // call this function to execute a "enter"
    //
    void enter();
    //
    // call this function to execute a "backpress"
    //
    void back();
    //
    // display text at the cursor position
    //  text: String        = text to display
    //
    void setText(String text);
};
#endif