#ifndef DELAYS_H
#define DELAYS_H

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 48000000
#endif //_XTAL_FREQ

#include <time.h>

void Delay1KTCYx(unsigned long time)
{
    unsigned long end = clock() + time * CLOCKS_PER_SEC / ( (_XTAL_FREQ /4.0) /1000.0 );
    while (clock() < end)
        ;
}

#endif //DELAYS_H