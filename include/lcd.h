#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include <stdio.h>
#include <xc.h>
#include <p18f4550.h>
#include "../include/arduim.h"
#include <delays.h>

//  LCD DATA PORT
#define LCD_PORTA  0x00
#define LCD_PORTB  0x01
#define LCD_PORTC  0x02
#define LCD_PORTD  0x03
#define LCD_PORTE  0x04

typedef struct {
    void (*prints) (const char*);
    void (*printl) (long);
    void (*printi) (int);
    void (*printc) (char);
    void (*clear) (void);
    void (*setCursor) (uint8_t, uint8_t);
    struct {
        uint8_t rs;
        uint8_t en;
        uint8_t port;
    } pins;
} lcd_t;

lcd_t lcd_get(uint8_t rs, uint8_t en, uint8_t port);
void lcd_select(lcd_t*);
void lcd_init(void);            //begin configuration
void lcd_cmd(uint8_t cmd);      //send a instruction
void lcd_data(uint8_t data);    //print a character
void lcd_number(int number);    //print a number in 4 digits format
void lcd_print(const char* s);  //print a string
void lcd_printl(long);          //print a long integer
void lcd_printi(int);           //print an integer
void lcd_printc(char);          //print a character
void lcd_clear(void);           //clear the display
void lcd_set_cursor(uint8_t line, uint8_t column); //position the cursor

#ifndef LCD_SOURCE
#define LCD_SOURCE 1
#endif

#if LCD_SOURCE == 1
#include "../src/lcd.c"
#endif

#endif // LCD_H