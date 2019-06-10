#ifndef P18F4550_H
#define P18F4550_H

struct {
    unsigned RA0 : 1;
    unsigned RA1 : 1;
    unsigned RA2 : 1;
    unsigned RA3 : 1;
    unsigned RA4 : 1;
    unsigned RA5 : 1;
    unsigned RA6 : 1;
} PORTAbits;

struct {
    unsigned RB0 : 1;
    unsigned RB1 : 1;
    unsigned RB2 : 1;
    unsigned RB3 : 1;
    unsigned RB4 : 1;
    unsigned RB5 : 1;
    unsigned RB6 : 1;
    unsigned RB7 : 1;
} PORTBbits;

struct {
    unsigned RC0 : 1;
    unsigned RC1 : 1;
    unsigned RC2 : 1;
    unsigned RC4 : 1;
    unsigned RC5 : 1;
    unsigned RC6 : 1;
    unsigned RC7 : 1;
} PORTCbits;

struct {
    unsigned RD0 : 1;
    unsigned RD1 : 1;
    unsigned RD2 : 1;
    unsigned RD3 : 1;
    unsigned RD4 : 1;
    unsigned RD5 : 1;
    unsigned RD6 : 1;
    unsigned RD7 : 1;
} PORTDbits;

struct {
    unsigned RE0 : 1;
    unsigned RE1 : 1;
    unsigned RE2 : 1;
} PORTEbits;

struct {
    unsigned TRISA0 : 1;
    unsigned TRISA1 : 1;
    unsigned TRISA2 : 1;
    unsigned TRISA3 : 1;
    unsigned TRISA4 : 1;
    unsigned TRISA5 : 1;
    unsigned TRISA6 : 1;
} TRISAbits;

struct {
    unsigned TRISB0 : 1;
    unsigned TRISB1 : 1;
    unsigned TRISB2 : 1;
    unsigned TRISB3 : 1;
    unsigned TRISB4 : 1;
    unsigned TRISB5 : 1;
    unsigned TRISB6 : 1;
    unsigned TRISB7 : 1;
} TRISBbits;

struct {
    unsigned TRISC0 : 1;
    unsigned TRISC1 : 1;
    unsigned TRISC2 : 1;
    unsigned TRISC6 : 1;
    unsigned TRISC7 : 1;
} TRISCbits;

struct {
    unsigned TRISD0 : 1;
    unsigned TRISD1 : 1;
    unsigned TRISD2 : 1;
    unsigned TRISD3 : 1;
    unsigned TRISD4 : 1;
    unsigned TRISD5 : 1;
    unsigned TRISD6 : 1;
    unsigned TRISD7 : 1;
} TRISDbits;

struct {
    unsigned TRISE0 : 1;
    unsigned TRISE1 : 1;
    unsigned TRISE2 : 1;
} TRISEbits;

uint8_t TRISA, TRISB, TRISC, TRISD, TRISE;
uint8_t PORTA, PORTB, PORTC, PORTD, PORTE;

#endif // P18F4450_H