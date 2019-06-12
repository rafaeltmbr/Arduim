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
    attachInterrupt(HALL_SENSOR, counter, FALLING);

    lcd.setCursor(0, 0);
    lcd.printf("Tachometer (RPM)");
    
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    delay(1000);
    int rpm = count * 60 / 58;
    count = 0;
    lcd.setCursor(6, 1);
    lcd.printf("%4d", rpm);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}