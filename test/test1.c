#define DEBUG
#include "../include/arduim.h"

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
    
    int pwm = analogRead(POTEN)/4;
//    analogWrite(PWM_LED, pwm);
    
    int time =  map(analogRead(POTEN), 0, 1023, 0, 500);
    delay(time);
}