#include "../include/arduim.h"

#define INTERRUPT_PIN  B0
#define SWITCH_COUNT_MAX 10

static int switchCount = 0;

void switchLED(void)
{
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    switchCount++;
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT);
    attachInterrupt(INTERRUPT_PIN, switchLED, RISING);
}

void loop()
{
    if (switchCount >= SWITCH_COUNT_MAX)
        detachInterrupt(INTERRUPT_PIN);
}