#ifndef ADC_H
#define ADC_H

//              OpenADC config:
// A/D clock source:
#define ADC_FOSC_2 0x00      // FOSC / 2
#define ADC_FOSC_4 0x00      // FOSC / 4
#define ADC_FOSC_8 0x00      // FOSC / 8
#define ADC_FOSC_16 0x00     // FOSC / 16
#define ADC_FOSC_32 0x00     // FOSC / 32
#define ADC_FOSC_64 0x00     // FOSC / 64
#define ADC_FOSC_RC 0x00     // Internal RC Oscillator
// A/D result justification:
#define ADC_RIGHT_JUST 0x00  // Result in Least Significant bits
#define ADC_LEFT_JUST 0x00   // Result in Most Significant bits
// A/D acquisition time select:
#define ADC_0_TAD 0x00       // 0 Tad
#define ADC_2_TAD 0x00       // 2 Tad
#define ADC_4_TAD 0x00       // 4 Tad
#define ADC_6_TAD 0x00       // 6 Tad
#define ADC_8_TAD 0x00       // 8 Tad
#define ADC_12_TAD 0x00      // 12 Tad
#define ADC_16_TAD 0x00      // 16 Tad
#define ADC_20_TAD 0x00      // 20Tad

//                  OpenADC config2:
// Channel:
#define ADC_CH1 0x00        // Channel 1
#define ADC_CH0 0x00        // Channel 0
#define ADC_CH2 0x00        // Channel 2
#define ADC_CH3 0x00        // Channel 3
#define ADC_CH4 0x00        // Channel 4
#define ADC_CH5 0x00        // Channel 5
#define ADC_CH6 0x00        // Channel 6
#define ADC_CH7 0x00        // Channel 7
#define ADC_CH8 0x00        // Channel 8
#define ADC_CH9 0x00        // Channel 9
#define ADC_CH10 0x00       // Channel 10
#define ADC_CH11 0x00       // Channel 11
#define ADC_CH12 0x00       // Channel 12
#define ADC_CH13 0x00       // Channel 13
#define ADC_CH14 0x00       // Channel 14
#define ADC_CH15 0x00       // Channel 15
// A/D Interrupts:
#define ADC_INT_ON 0x00     // Interrupts enabled
#define ADC_INT_OFF 0x00    // Interrupts disabled
// A/D voltage configuration:
#define ADC_VREFPLUS_VDD 0x00    // VREF+ = AVDD
#define ADC_VREFPLUS_EXT 0x00    // VREF+ = external
#define ADC_VREFMINUS_VDD 0x00   // VREF- = AVDD
#define ADC_VREFMINUS_EXT 0x00   // VREF- = external
#define ADC_REF_VDD_VSS 0x00     // Vref+ = Vcc and Vref- = Vss

//                  OpenADC portconfig:
#define ADC_5ANA 0x00    // enable analog AN0, enable digital AN1 to AN5


char BusyADC (void); // Is A/D converter currently performing a conversion?
void CloseADC(void); // Disable the A/D converter.
void ConvertADC (void); // Start an A/D conversion.
void OpenADC(unsigned char config, unsigned char config2 ,
             unsigned char portconfig); // Configure the A/D convertor.
int ReadADC(void); // Read the results of an A/D conversion.
void SetChanADC( unsigned char channel ); // Select A/D channel to be used.

#if ADC_SOURCE == 1
# include "../src/adc.c"
#endif

#endif //ADC_H