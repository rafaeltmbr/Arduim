#ifndef ARDUIM_H
#define ARDUIM_H

// Default config (Don't you dare change it)
#pragma config PLLDIV = 5
#pragma config USBDIV = 2
#pragma config VREGEN = ON
#pragma config FOSC = HSPLL_HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config WRTB = ON

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 48000000UL
#endif

#define ARDUIM_CYCLES_US ( (unsigned int) ((_XTAL_FREQ /4.0) /1000000.0 ) )

#include "../include/pins_arduim.h"
#include <stdint.h>

#include <xc.h>
#include <p18f4550.h>
#include <delays.h>
#include <adc.h>
#include <pwm.h>
#include <portb.h>

#define ARDUIM_ERROR -1
#define LOW  0x0
#define HIGH 0x1

#define OUTPUT 0x0
#define INPUT 0x1
//#define INPUT_PULLUP 0x2

//#define CHANGE  1 - NO AVAILABLE ON PIC18F chips
#define FALLING 2
#define RISING  3

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef abs
#define abs(x) ((x)>0?(x):-(x))
#endif

#ifndef constrain
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif 

#ifndef round
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#endif

#ifndef radians
#define radians(deg) ((deg)*DEG_TO_RAD)
#endif

#ifndef degrees
#define degrees(rad) ((rad)*RAD_TO_DEG)
#endif

#ifndef sq
#define sq(x) ((x)*(x))
#endif

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogWrite(uint8_t, int);

void attachInterrupt(uint8_t, void (*)(void), int);
void detachInterrupt(uint8_t);

void setup(void);
void loop(void);

long map(long, long, long, long, long);
void delay(unsigned long);
void delayMicrosseconds(unsigned int);

#ifndef ARDUIM_SOURCE
#define ARDUIM_SOURCE 1
#endif

#if ARDUIM_SOURCE == 1
#include "../src/arduim.c"
#endif

#endif // ARDUIM_H