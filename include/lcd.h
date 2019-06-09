#ifndef LCD_H
#define LCD_H

struct lcd_t {
    void (*print) (const char*);
}

void lcd_init();                //begin configuration
void lcd_cmd(char cmd);         //send a instruction
void lcd_data(char data);       //print a character
void lcd_number(int number);    //print a number in 4 digits format
void lcd_print(const char* s);  //print a string
void lcd_clear(void);           //clear the display
void lcd_set_cursor(char line, char column); //position the cursor

#ifdef LCD_SOURCE
#include "../src/lcd.c"
#endif

#endif // LCD_H