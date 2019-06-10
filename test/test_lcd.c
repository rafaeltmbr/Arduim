#include "../include/arduim.h"
#include "../include/lcd.h"

lcd_t lcd;

void setup()
{
    lcd = lcd_get(C6, C7, LCD_PORTD);
    lcd_select(&lcd);

    lcd.setCursor(0, 0);
    lcd.prints("  Debugging LCD ");
    lcd.setCursor(0, 1);
    lcd.prints("file: test_lcd.c");
    delay(1000);
}

void loop()
{
    static uint16_t count = 0;
    lcd.clear();
    lcd.setCursor(0, 5);
    lcd.prints("lcd.h");
    lcd.setCursor(0, 3);
    lcd.prints("count: ");
    lcd.printi(count++);
    delay(500);
}