#include "../include/arduim.h"

void interrupt my_isr_high(void);
void interrupt low_priority my_isr_low(void);

static void init()
{
	OpenADC(
		ADC_FOSC_16 // Fosc=20MHz Fad=20MHz/16 Tad = 0,8us
		&ADC_RIGHT_JUST // Resultado justificado a direita
		&ADC_4_TAD, // Configuração do tempo automático (4*Tad=3,2us)

		ADC_INT_OFF // Interrupção desabilitada
		&ADC_REF_VDD_VSS // Vref+ = Vcc (5V) e Vref- = Vss
		&ADC_CH4, // Seleciona canal 0

		ADC_5ANA // Habilita entrada analógica AN0, digital AN1 a AN15
	);
}

void main(void)
{
	init();
	setup();
	for(;;)
		loop();
}

void pinMode(uint8_t pin, uint8_t mode)
{
	if ( (mode != INPUT && mode != OUTPUT) || pin > HIGHER_PIN )
		return;

	switch (pin)
	{
		case A0: TRISAbits.RA0 = mode; break;
		case A1: TRISAbits.RA1 = mode; break;
		case A2: TRISAbits.RA2 = mode; break;
		case A3: TRISAbits.RA3 = mode; break;
		case A4: TRISAbits.RA4 = mode; break;
		case A5: TRISAbits.RA5 = mode; break;

		case B0: TRISBbits.RB0 = mode; break;
		case B1: TRISBbits.RB1 = mode; break;
		case B2: TRISBbits.RB2 = mode; break;
		case B3: TRISBbits.RB3 = mode; break;
		case B4: TRISBbits.RB4 = mode; break;
		case B5: TRISBbits.RB5 = mode; break;
		case B6: TRISBbits.RB6 = mode; break;
		case B7: TRISBbits.RB7 = mode; break;

		case C0: TRISCbits.RC0 = mode; break;
		case C1: TRISCbits.RC1 = mode; break;
		case C2: TRISCbits.RC2 = mode; break;
		case C6: TRISCbits.RC6 = mode; break;
		case C7: TRISCbits.RC7 = mode; break;

		case D0: TRISDbits.RD0 = mode; break;
		case D1: TRISDbits.RD1 = mode; break;
		case D2: TRISDbits.RD2 = mode; break;
		case D3: TRISDbits.RD3 = mode; break;
		case D4: TRISDbits.RD4 = mode; break;
		case D5: TRISDbits.RD5 = mode; break;
		case D6: TRISDbits.RD6 = mode; break;
		case D7: TRISDbits.RD7 = mode; break;

		case E0: TRISEbits.RE0 = mode; break;
		case E1: TRISEbits.RE1 = mode; break;
		case E2: TRISEbits.RE2 = mode; break;

		default: break;
	}
}

int digitalRead(uint8_t pin)
{
	if (pin > HIGHER_PIN)
		return ARDUIM_ERROR;

	switch (pin)
	{
		case A0: return PORTAbits.RA0;
		case A1: return PORTAbits.RA1;
		case A2: return PORTAbits.RA2;
		case A3: return PORTAbits.RA3;
		case A4: return PORTAbits.RA4;
		case A5: return PORTAbits.RA5;

		case B0: return PORTBbits.RB0;
		case B1: return PORTBbits.RB1;
		case B2: return PORTBbits.RB2;
		case B3: return PORTBbits.RB3;
		case B4: return PORTBbits.RB4;
		case B5: return PORTBbits.RB5;
		case B6: return PORTBbits.RB6;
		case B7: return PORTBbits.RB7;

		case C0: return PORTCbits.RC0;
		case C1: return PORTCbits.RC1;
		case C2: return PORTCbits.RC2;
		case C6: return PORTCbits.RC6;
		case C7: return PORTCbits.RC7;

		case D0: return PORTDbits.RD0;
		case D1: return PORTDbits.RD1;
		case D2: return PORTDbits.RD2;
		case D3: return PORTDbits.RD3;
		case D4: return PORTDbits.RD4;
		case D5: return PORTDbits.RD5;
		case D6: return PORTDbits.RD6;
		case D7: return PORTDbits.RD7;

		case E0: return PORTEbits.RE0;
		case E1: return PORTEbits.RE1;
		case E2: return PORTEbits.RE2;

		default: return ARDUIM_ERROR;
	}
}

void digitalWrite(uint8_t pin, uint8_t level)
{
	if ( (level != HIGH && level != LOW) || pin > HIGHER_PIN )
		return;

	switch (pin)
	{
		case A0: PORTAbits.RA0 = level; break;
		case A1: PORTAbits.RA1 = level; break;
		case A2: PORTAbits.RA2 = level; break;
		case A3: PORTAbits.RA3 = level; break;
		case A4: PORTAbits.RA4 = level; break;
		case A5: PORTAbits.RA5 = level; break;

		case B0: PORTBbits.RB0 = level; break;
		case B1: PORTBbits.RB1 = level; break;
		case B2: PORTBbits.RB2 = level; break;
		case B3: PORTBbits.RB3 = level; break;
		case B4: PORTBbits.RB4 = level; break;
		case B5: PORTBbits.RB5 = level; break;
		case B6: PORTBbits.RB6 = level; break;
		case B7: PORTBbits.RB7 = level; break;

		case C0: PORTCbits.RC0 = level; break;
		case C1: PORTCbits.RC1 = level; break;
		case C2: PORTCbits.RC2 = level; break;
		case C6: PORTCbits.RC6 = level; break;
		case C7: PORTCbits.RC7 = level; break;

		case D0: PORTDbits.RD0 = level; break;
		case D1: PORTDbits.RD1 = level; break;
		case D2: PORTDbits.RD2 = level; break;
		case D3: PORTDbits.RD3 = level; break;
		case D4: PORTDbits.RD4 = level; break;
		case D5: PORTDbits.RD5 = level; break;
		case D6: PORTDbits.RD6 = level; break;
		case D7: PORTDbits.RD7 = level; break;

		case E0: PORTEbits.RE0 = level; break;
		case E1: PORTEbits.RE1 = level; break;
		case E2: PORTEbits.RE2 = level; break;

		default: break;
	}
}

int analogRead(uint8_t channel);
{
	SetChanADC(channel); //select channel
	ConvertADC();		 //start convertion
	while(BusyADC()) 	 //wait convertion ends
		;
	return ReadADC();
}

int map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
	return round( ( ((float) value - fromLow) / (fromHigh - fromLow) ) *
		(toHigh - toLow) + toLow );
}

void delay_(unsigned long time);
{
	for ( ; time > 0; time--)
		Delay1KTCYx(12);
}