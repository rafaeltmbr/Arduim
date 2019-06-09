#include "../include/lcd.h"

#define LCD_RS PORTCbits.RC6 	  // Pino do PIC ligado no RS do LCD
#define LCD_EN PORTCbits.RC7 	  // Pino do PIC ligado no Enable do LCD
#define LCD_TRIS_RS TRISCbits.RC6 // Direção da Porta Porta do PIC ligado no RS do LCD
#define LCD_TRIS_EN TRISCbits.RC7 // Direção da Porta Porta do PIC ligado no EN do LCD
#define LCD_DB PORTD 		  // Porta do PIC ligado nos pinos DB0..DB7 do LCD
#define LCD_TRIS TRISD 		  // Direção da Porta do PIC ligado nos pinos DB0..DB7 do LCD

void lcd_init()
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

void lcd_print(const char* s)
{
	for (; *s; s++)
		lcd_data(*s);
}

void lcd_clear(void)
{
	lcd_cmd(0x01);
	Delay1KTCYx(30);
};

void lcd_set_cursor(uint8_t line, uint8_t column)
{
	line = (line == 0) ? 0x80 : 0xC0;
	column &= 0x0F;
	lcd_cmd(line | column);
}