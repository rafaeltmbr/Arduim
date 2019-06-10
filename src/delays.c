#include "../include/delays.h"

void DelayTCY(void)
{
    unsigned long end = (unsigned long) (clock() + CLOCKS_PER_SEC / (_XTAL_FREQ /4.0));
    while (clock() < end)
        ;
}

void Delay10TCYx(unsigned long time)
{
    unsigned long end = (unsigned long) (clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /10.0 ));
    while (clock() < end)
        ;
}

void Delay100TCYx(unsigned long time)
{
    unsigned long end = (unsigned long) (clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /100.0 ));
    while (clock() < end)
        ;
}

void Delay1KTCYx(unsigned long time)
{
    unsigned long end = (unsigned long) (clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /1000.0 ));
    while (clock() < end)
        ;
}

void Delay10KTCYx(unsigned long time)
{
    unsigned long end = (unsigned long) (clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /10000.0 ));
    while (clock() < end)
        ;
}
