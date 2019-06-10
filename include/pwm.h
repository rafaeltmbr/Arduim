#ifndef PWM_H
#define PWM_H

void ClosePWM1(void);
void ClosePWM2(void);
void ClosePWM3(void);
void ClosePWM4(void);
void ClosePWM5(void);

// PWM period =[(period ) + 1] x 4 x TOSC x TMR2 prescaler
void OpenPWM1(char period);
void OpenPWM2(char period);
void OpenPWM3(char period);
void OpenPWM4(char period);
void OpenPWM5(char period);

void SetDCPWM1(unsigned int dutycycle);
void SetDCPWM2(unsigned int dutycycle);
void SetDCPWM3(unsigned int dutycycle);
void SetDCPWM4(unsigned int dutycycle);
void SetDCPWM5(unsigned int dutycycle);

void SetOutputPWM1(unsigned char outputconfig, unsigned char outputmode);
void SetOutputPWM2(unsigned char outputconfig, unsigned char outputmode);
void SetOutputPWM3(unsigned char outputconfig, unsigned char outputmode);

// SetOutputPWMx outputconfig:
// The value of outputconfig can be any one of the following values (defined in pwm.h):
#define SINGLE_OUT 0x00      // single output
#define FULL_OUT_FWD 0x00    // full-bridge output forward
#define HALF_OUT 0x00        // half-bridge output
#define FULL_OUT_REV 0x00    // full-bridge output reverse
// SetOutputPWMx outputmode:
// define The value of outputmode can be any one of the following values (defined in pwm.h):
#define PWM_MODE_1 0x00  // P1A and P1C active-high, P1B and P1D active-high
#define PWM_MODE_2 0x00  // P1A and P1C active-high, P1B and P1D active-low
#define PWM_MODE_3 0x00  // P1A and P1C active-low, P1B and P1D active-high
#define PWM_MODE_4 0x00  // P1A and P1C active-low, P1B and P1D active-low

#if PWM_SOURCE == 1
# include "../src/pwm.c"
#endif

#endif // PWM_H