#include "../include/arduim.h"
#include "../include/lcd.h"

lcd_t lcd;
uint16_t count = 0;

void setup()
{
    lcd = lcd_get(C6, C7, LCD_PORTD);
    lcd_select(&lcd);
    
    lcd.setCursor(2, 0);
    lcd.prints("Debugging LCD");
    lcd.setCursor(0, 1);
    lcd.prints("file: test_lcd.c");
    delay(1000);
}

void loop()
{
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.prints("lcd.h");
    lcd.setCursor(3, 1);
    lcd.prints("count: ");
    lcd.printi(count++);
    delay(1000);
}