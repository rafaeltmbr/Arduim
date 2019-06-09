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


#endif // P18F4450_H