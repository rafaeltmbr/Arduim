#include "../include/arduim.h"
#include <xc.h>
#include <p18f4550.h>
#include <delays.h>
#include <adc.h>

int analogRead(char channel);
int map(int value, int fromLow, int fromHigh, int toLow, int toHigh);
void delay(unsigned long time);
void interrupt my_isr_high(void);
void interrupt low_priority my_isr_low(void);

void init()
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

int analogRead(char channel)
{
	SetChanADC(channel); //Seleciona canal
	ConvertADC();		 //Inicia conversão
	while(BusyADC()) 	 //Aguarda fim da conversão
		;
	return ReadADC();
}

int map(int value, int fromLow, int fromHigh, int toLow, int toHigh)
{
        
}

void delay(unsigned long time)
{
	while(time-- > 0)
		Delay1KTCYx(12);
}