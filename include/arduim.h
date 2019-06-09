#ifndef ARDUIM_H
#define ARDUIM_H

#include "pins_arduim.h"
#include <stdint.h>

#ifdef DEBUG
# include "p18f4550.h"
# include "delays.h"
# include "adc.h"
#else
# include <xc.h>
# include <p18f4550.h>
# include <delays.h>
#include <adc.h>
#endif

#define ARDUIM_ERROR -1
#define LOW  0x0
#define HIGH 0x1

#define OUTPUT 0x0
#define INPUT 0x1
//#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

void pinMode(uint8_t, uint8_t); //done
void digitalWrite(uint8_t, uint8_t); //done
int digitalRead(uint8_t); //done
int analogRead(uint8_t); //done
void analogWrite(uint8_t, int);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void setup(void); //done
void loop(void); //done

long map(long, long, long, long, long); //done
void delay(unsigned long);

#ifndef ARDUIM_SOURCE
#define ARDUIM_SOURCE 1
#endif

#if ARDUIM_SOURCE == 1
#include "../src/arduim.c"
#endif

#endif // ARDUIM_H
