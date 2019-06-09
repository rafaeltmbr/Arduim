#ifndef LCD_H
#define LCD_H

typedef struct {
    void (*print) (const char*);
    void (*clear) (void);
    void (*setCursor) (uint8_t, uint8_t);
} lcd_t;

void lcd_init();                //begin configuration
void lcd_cmd(uint8_t cmd);      //send a instruction
void lcd_data(uint8_t data);    //print a character
void lcd_number(int number);    //print a number in 4 digits format
void lcd_print(const char* s);  //print a string
void lcd_clear(void);           //clear the display
void lcd_set_cursor(uint8_t line, uint8_t column); //position the cursor

#ifndef LCD_SOURCE
#define LCD_SOURCE 1
#endif

#if LCD_SOURCE == 1
#include "../src/lcd.c"
#endif

#endif // LCD_H