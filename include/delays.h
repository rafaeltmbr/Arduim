#ifndef DELAYS_H
#define DELAYS_H

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 48000000
#endif //_XTAL_FREQ

#include <time.h>

void DelayTCY(void)
{
    unsigned long end = clock() + CLOCKS_PER_SEC / (_XTAL_FREQ /4.0);
    while (clock() < end)
        ;
}

void Delay10TCYx(unsigned long time)
{
    unsigned long end = clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /10.0 );
    while (clock() < end)
        ;
}

void Delay100TCYx(unsigned long time)
{
    unsigned long end = clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /100.0 );
    while (clock() < end)
        ;
}

void Delay1KTCYx(unsigned long time)
{
    unsigned long end = clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /1000.0 );
    while (clock() < end)
        ;
}

void Delay10KTCYx(unsigned long time)
{
    unsigned long end = clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /10000.0 );
    while (clock() < end)
        ;
}

#endif //DELAYS_H