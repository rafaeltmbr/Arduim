#include "../include/arduim.h"

#define HALL_SENSOR  B0

unsigned int count = 0;
lcd_t lcd;

void counter(void)
{
    count++;
}

void setup()
{
    lcd = lcd_get(C6, C7, LCD_PORTD);
    lcd_select(&lcd);
    pinMode(HALL_SENSOR, INPUT);
    attachInterrupt(HALL_SENSOR, counter, RISING);
}

void loop()
{
    delay(1000);

}