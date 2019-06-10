// when debugging build with: gcc test1.c -Wall -g -std=c11 -o test1.exe
#define DEBUG
#include "../include/arduim.h"

#ifdef DEBUG
# define MAX_DELAY 5000
#else
# define MAX_DELAY 500
#endif

#define PWM_LED 1
#define POTEN A0

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PWM_LED, OUTPUT);
    pinMode(POTEN, INPUT);
}

void loop()
{
    char led = digitalRead(LED_BUILTIN);
    digitalWrite(LED_BUILTIN, !led);
    
    int pot = analogRead(POTEN);
    analogWrite(PWM_LED, pot/4);
    
    int time =  map(pot, 0, 1023, 0, MAX_DELAY);    
    delay(time);
}