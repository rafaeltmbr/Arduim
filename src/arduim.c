#include "../include/arduim.h"

//void interrupt my_isr_high(void);
//void interrupt low_priority my_isr_low(void);

static uint8_t getChannelADC(uint8_t); // map pin to ADC channel
static uint8_t getRangeChannelsADC(uint8_t); // select a channels range

static void init()
{

}

int main(void)
{
#ifdef DEBUG_CONSOLE
	
	printf("\n##################### DEBUG CONSOLE #####################\n"
		   "\n--------------------- setup ---------------------\n");
	
#endif
	
	init();
	setup();
	for( ; ; )
	{

#ifdef DEBUG_CONSOLE

		static unsigned long loop_count = 1;
    	printf("\n\n--------------------- loop %ld --------------------- \n", loop_count);
		loop_count++;
		
#endif

		loop();
	}
}

void pinMode(uint8_t pin, uint8_t mode)
{
	if ( (mode != INPUT && mode != OUTPUT) || pin > HIGHER_PIN )
		return;

#ifdef DEBUG_CONSOLE

	printf("pin %d = %s\n", pin, mode == INPUT ? "INPUT" : "OUTPUT");

#endif

	switch (pin)
	{
		case A0: TRISAbits.TRISA0 = mode; break;
		case A1: TRISAbits.TRISA1 = mode; break;
		case A2: TRISAbits.TRISA2 = mode; break;
		case A3: TRISAbits.TRISA3 = mode; break;
		case A4: TRISAbits.TRISA4 = mode; break;
		case A5: TRISAbits.TRISA5 = mode; break;

		case B0: TRISBbits.TRISB0 = mode; break;
		case B1: TRISBbits.TRISB1 = mode; break;
		case B2: TRISBbits.TRISB2 = mode; break;
		case B3: TRISBbits.TRISB3 = mode; break;
		case B4: TRISBbits.TRISB4 = mode; break;
		case B5: TRISBbits.TRISB5 = mode; break;
		case B6: TRISBbits.TRISB6 = mode; break;
		case B7: TRISBbits.TRISB7 = mode; break;

		case C0: TRISCbits.TRISC0 = mode; break;
		case C1: TRISCbits.TRISC1 = mode; break;
		case C2: TRISCbits.TRISC2 = mode; break;
		case C6: TRISCbits.TRISC6 = mode; break;
		case C7: TRISCbits.TRISC7 = mode; break;

		case D0: TRISDbits.TRISD0 = mode; break;
		case D1: TRISDbits.TRISD1 = mode; break;
		case D2: TRISDbits.TRISD2 = mode; break;
		case D3: TRISDbits.TRISD3 = mode; break;
		case D4: TRISDbits.TRISD4 = mode; break;
		case D5: TRISDbits.TRISD5 = mode; break;
		case D6: TRISDbits.TRISD6 = mode; break;
		case D7: TRISDbits.TRISD7 = mode; break;

		case E0: TRISEbits.TRISE0 = mode; break;
		case E1: TRISEbits.TRISE1 = mode; break;
		case E2: TRISEbits.TRISE2 = mode; break;

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
		case C4: return PORTCbits.RC4;
		case C5: return PORTCbits.RC5;
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

#ifdef DEBUG_CONSOLE

	printf("digital pin %d = %d\n", pin, level);

#endif

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
		case C4: PORTCbits.RC4 = level; break;
		case C5: PORTCbits.RC5 = level; break;
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

int analogRead(uint8_t channel)
{

#ifdef DEBUG_CONSOLE

	static uint8_t start_debug = 1;
	if (start_debug)
	{
		srand(time(NULL));
		start_debug = 0;
	}
	return rand() % 1024;

#endif

	uint8_t channel_flag = getChannelADC(channel);
	if (channel_flag == ARDUIM_ERROR)
		return 0;

	OpenADC(
		ADC_FOSC_16			// Tad = Fosc / 16
		& ADC_RIGHT_JUST	// Adjust to lsb
		& ADC_4_TAD, 		// Acquisition time = 4 * Tad

		ADC_INT_OFF 		// interrupts disabled
		& ADC_REF_VDD_VSS 	// Vref+ = Vcc (5V) e Vref- = Vss
		& channel_flag, 	// Select channel

		getRangeChannelsADC(channel) // Select analog channels range
	);

	SetChanADC( getChannelADC(channel) ); // Select channel input to be read
	ConvertADC();		 // start convertion
	while(BusyADC()) 	 // wait convertion ends
		;
	CloseADC();			 // disable AD converter
	return ReadADC();
}

void analogWrite(uint8_t pin, int value)
{

#ifdef DEBUG_CONSOLE

	printf("analog pin %d = %d\n", pin, value);
	
#endif

	value <<= 2; // adjust to 10 bits

	switch (pin)
	{
		case PWM1:
			OpenPWM1(0xff);
			SetOutputPWM1(SINGLE_OUT, PWM_MODE_1);
			SetDCPWM1(value);
			break;
//		case PWM2:
//			OpenPWM2(0xff);
//			SetOutputPWM2(SINGLE_OUT, PWM_MODE_1);
//			SetDCPWM2(value);
//			break;
	}
}

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
	return round( ( ((float) value - fromLow) / (fromHigh - fromLow) ) *
		(toHigh - toLow) + toLow );
}

void delay(unsigned long time)
{
	
#ifdef DEBUG_CONSOLE

	printf("delay %ld ms\n", time);

#endif

	for ( ; time > 0; time--)
		Delay1KTCYx( (unsigned long) ((_XTAL_FREQ /4.0) /1000000.0 ));
}

static uint8_t getChannelADC(uint8_t pin)
{
    switch (pin)
    {
        case AA0:  return ADC_CH0;
        case AA1:  return ADC_CH1;
        case AA2:  return ADC_CH2;
        case AA3:  return ADC_CH3;
        case AA4:  return ADC_CH4;
        case AA8:  return ADC_CH8;
        case AA9:  return ADC_CH9;
        case AA10: return ADC_CH10;
        case AA11: return ADC_CH11;
        case AA12: return ADC_CH12;
		default:   return ARDUIM_ERROR;
    }
}

static uint8_t getRangeChannelsADC(uint8_t pin)
{
    switch (pin)
    {
        case AA0:  return ADC_1ANA;
        case AA1:  return ADC_2ANA;
        case AA2:  return ADC_3ANA;
        case AA3:  return ADC_4ANA;
        case AA4:  return ADC_5ANA;
        case AA8:  return ADC_9ANA;
        case AA9:  return ADC_10ANA;
        case AA10: return ADC_11ANA;
        case AA11: return ADC_12ANA;
        case AA12: return ADC_13ANA;
		default:   return ADC_0ANA; 	// No channels are analog
    }
}
