#include "../include/lcd.h"

static lcd_t* lcd_selected = NULL;

void lcd_select(lcd_t* lcd_ptr)
{
	lcd_selected = lcd_ptr;
	lcd_init();
}

lcd_t lcd_get(uint8_t rs, uint8_t en, uint8_t port)
{
    lcd_t b = {
        lcd_print,
        lcd_printl,
        lcd_printi,
        lcd_printc,
		lcd_printf,
        lcd_clear,
        lcd_set_cursor
    };

    b.pins.rs = rs;
    b.pins.en = en;
    b.pins.port = port;
    return b;
}

void lcd_init(void)
{
	pinMode(lcd_selected->pins.rs, OUTPUT);
	pinMode(lcd_selected->pins.en, OUTPUT);
	digitalWrite(lcd_selected->pins.rs, LOW);
	digitalWrite(lcd_selected->pins.en, LOW);
	
	switch (lcd_selected->pins.port)
	{
		case LCD_PORTA: TRISA = 0x00; break;
		case LCD_PORTB: TRISB = 0x00; break;
		case LCD_PORTC: TRISC = 0x00; break;
		case LCD_PORTD: TRISD = 0x00; break;
		case LCD_PORTE: TRISE = 0x00; break;
	}

	lcd_cmd(0b00111000);	// 8-bit mode, 7x5 and 2 lines
	lcd_cmd(0b00010110); 	// Cursor advance right
	lcd_cmd(0b00001100); 	// Turn display on and shut the cursor
	lcd_clear();
}

void lcd_cmd(uint8_t cmd)
{
	digitalWrite(lcd_selected->pins.rs, LOW); // Instruction mode

	switch (lcd_selected->pins.port)		  // Write instruction
	{
		case LCD_PORTA: PORTA = cmd; break;
		case LCD_PORTB: PORTB = cmd; break;
		case LCD_PORTC: PORTC = cmd; break;
		case LCD_PORTD: PORTD = cmd; break;
		case LCD_PORTE: PORTE = cmd; break;
	}

	digitalWrite(lcd_selected->pins.en, HIGH);	// enable instruction read
	delayMicroseconds(80);						// wait operation to conclude (40 us)
	digitalWrite(lcd_selected->pins.en, LOW);	// disable instruction read
}

void lcd_data(uint8_t data)
{
	digitalWrite(lcd_selected->pins.rs, HIGH); // Data mode

	switch (lcd_selected->pins.port)		   // Write data
	{
		case LCD_PORTA: PORTA = data; break;
		case LCD_PORTB: PORTB = data; break;
		case LCD_PORTC: PORTC = data; break;
		case LCD_PORTD: PORTD = data; break;
		case LCD_PORTE: PORTE = data; break;
	}

	digitalWrite(lcd_selected->pins.en, HIGH);	// enable data read
	delayMicroseconds(80);						// wait operation to conclude (40 us)
	digitalWrite(lcd_selected->pins.en, LOW);	// disable data read
}

void lcd_print(const char* s)
{
	for (; *s; s++)
		lcd_data(*s);
}

void lcd_printl(long l)
{
	static char fmt[33];
    sprintf(fmt, "%ld", l);
	lcd_print(fmt);
}

void lcd_printi(int i)
{
	static char fmt[33];
    sprintf(fmt, "%d", i);
	lcd_print(fmt);
}

void lcd_printc(char c)
{
	static char fmt[2] = {0};
	fmt[0] = c;
	lcd_print(fmt);
}

void lcd_clear(void)
{
	lcd_cmd(0x01);
	delay(3);		// 1.6 ms to clear
}

void lcd_set_cursor(uint8_t column, uint8_t line)
{
	line = (line == 0) ? 0x80 : 0xC0;
	column &= 0x0F;
	lcd_cmd(line | column);
}

void lcd_printf(const char* s, ...)
{
	va_list ap;
	va_start(ap, s);
	char buffer[64];
	vsprintf(buffer, s, ap); //vsnprintf not supported
	lcd_print(buffer);
	va_end(ap);
}
