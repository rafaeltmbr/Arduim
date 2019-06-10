#include "../include/arduim.h"

#ifndef __UINT8_T__
#define __UINT8_T__
typedef unsigned char uint8_t;
#endif

#define MAX_DELAY 1000
#define PWM_LED 1
#define POTEN AA0

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