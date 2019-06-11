#include "../include/arduim.h"
#include "../include/lcd.h"

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

    lcd.setCursor(0, 0);
    lcd.prints("Tachometer (RPM)");
}

void loop()
{
    delay(1000);
    int rpm = count * 60 * 60 / 58;
    count = 0;
    lcd.setCursor(6, 1);
    lcd.printi(rpm);
}