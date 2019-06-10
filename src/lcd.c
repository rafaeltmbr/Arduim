#include "../include/lcd.h"

static lcd_t* lcd_selected = NULL;

void lcd_select(lcd_t* lcd_ptr)
{
	lcd_selected = lcd_ptr;
}

lcd_t lcd_get(uint8_t rs, uint8_t en, uint8_t port)
{
    lcd_t b = {
        lcd_print,
        lcd_printl,
        lcd_printi,
        lcd_printc,
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
	lcd_cmd(0b00000001); 	// Clear display
	delay(2);				// Wait operation conclude
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
	delay(1);									// wait operation to conclude
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
	delay(1);									// wait operation to conclude
	digitalWrite(lcd_selected->pins.en, LOW);	// disable data read
}

void lcd_print(const char* s)
{
	for (; *s; s++)
		lcd_data(*s);
}

void lcd_printl(const long l)
{
	static char fmt[33];
    sprintf(fmt, "%ld", l);
	lcd_print(fmt);
}

void lcd_printi(const int i)
{
	static char fmt[33];
    sprintf(fmt, "%d", i);
	lcd_print(fmt);
}

void lcd_printc(const char c)
{
	static char fmt[2] = {0};
	fmt[0] = c;
	lcd_print(fmt);
}

void lcd_clear(void)
{
	lcd_cmd(0x01);
	Delay1KTCYx(30);
};

void lcd_set_cursor(uint8_t column, uint8_t line)
{
	line = (line == 0) ? 0x80 : 0xC0;
	column &= 0x0F;
	lcd_cmd(line | column);
}

/*
#define LCD_RS PORTCbits.RC6 	  // Pino do PIC ligado no RS do LCD
#define LCD_EN PORTCbits.RC7 	  // Pino do PIC ligado no Enable do LCD
#define LCD_TRIS_RS TRISCbits.RC6 // Direção da Porta Porta do PIC ligado no RS do LCD
#define LCD_TRIS_EN TRISCbits.RC7 // Direção da Porta Porta do PIC ligado no EN do LCD
#define LCD_DB PORTD 		  // Porta do PIC ligado nos pinos DB0..DB7 do LCD
#define LCD_TRIS TRISD 		  // Direção da Porta do PIC ligado nos pinos DB0..DB7 do LCD

void lcd_init(void)
{
	LCD_TRIS = 0x00; 		// Configura porta do LCD de saída
	LCD_TRIS_EN = 0; 		// Configura pino EN como saída
	LCD_TRIS_RS = 0; 		// Configura pino RS como saída
	LCD_EN = 0; 			// EN = 0
	LCD_RS = 0; 			// RS = 0
	lcd_cmd(0b00111000);	// Modo 8 bits, 7x5 e 2 linhas
	lcd_cmd(0b00010110); 	// Cursor para a Direita
	lcd_cmd(0b00001100); 	// Liga display e desiga cursor
	lcd_cmd(0b00000001); 	// Limpa o display
	Delay1KTCYx(30);
}

void lcd_cmd(uint8_t cmd)
{
	LCD_RS = 0; 	// Comando
	LCD_DB = cmd;
	LCD_EN = 1;
	Delay1KTCYx(3);
	LCD_EN = 0;
}

void lcd_data(uint8_t data)
{
	LCD_RS = 1; 	// Dado
	LCD_DB = data;
	LCD_EN = 1;
	Delay1KTCYx(3);
	LCD_EN = 0;
}
*/
