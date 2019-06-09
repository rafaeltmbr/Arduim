#ifndef DELAYS_H
#define DELAYS_H

#ifndef _XTAL_FREQ
# define _XTAL_FREQ 48000000
#endif

#include <time.h>

void DelayTCY(void);
void Delay10TCYx(unsigned long);
void Delay100TCYx(unsigned long);
void Delay1KTCYx(unsigned long);
void Delay10KTCYx(unsigned long);

#if DELAYS_SOURCE == 1
# include "../src/delays.c"
#endif

#endif //DELAYS_H