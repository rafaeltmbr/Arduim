#ifndef ADC_H
#define ADC_H

//              OpenADC config:
// A/D clock source:
#define ADC_FOSC_2      // FOSC / 2
#define ADC_FOSC_4      // FOSC / 4
#define ADC_FOSC_8      // FOSC / 8
#define ADC_FOSC_16     // FOSC / 16
#define ADC_FOSC_32     // FOSC / 32
#define ADC_FOSC_64     // FOSC / 64
#define ADC_FOSC_RC     // Internal RC Oscillator
// A/D result justification:
#define ADC_RIGHT_JUST  // Result in Least Significant bits
#define ADC_LEFT_JUST   // Result in Most Significant bits
// A/D acquisition time select:
#define ADC_0_TAD       // 0 Tad
#define ADC_2_TAD       // 2 Tad
#define ADC_4_TAD       // 4 Tad
#define ADC_6_TAD       // 6 Tad
#define ADC_8_TAD       // 8 Tad
#define ADC_12_TAD      // 12 Tad
#define ADC_16_TAD      // 16 Tad
#define ADC_20_TAD      // 20Tad

//                  OpenADC config2:
// Channel:
#define ADC_CH1             // Channel 1
#define ADC_CH0             // Channel 0
#define ADC_CH2             // Channel 2
#define ADC_CH3             // Channel 3
#define ADC_CH4             // Channel 4
#define ADC_CH5             // Channel 5
#define ADC_CH6             // Channel 6
#define ADC_CH7             // Channel 7
#define ADC_CH8             // Channel 8
#define ADC_CH9             // Channel 9
#define ADC_CH10            // Channel 10
#define ADC_CH11            // Channel 11
#define ADC_CH12            // Channel 12
#define ADC_CH13            // Channel 13
#define ADC_CH14            // Channel 14
#define ADC_CH15            // Channel 15
// A/D Interrupts:
#define ADC_INT_ON          // Interrupts enabled
#define ADC_INT_OFF         // Interrupts disabled
// A/D voltage configuration:
#define ADC_VREFPLUS_VDD    // VREF+ = AVDD
#define ADC_VREFPLUS_EXT    // VREF+ = external
#define ADC_VREFMINUS_VDD   // VREF- = AVDD
#define ADC_VREFMINUS_EXT   // VREF- = external
#define ADC_REF_VDD_VSS     // Vref+ = Vcc and Vref- = Vss

//                  OpenADC portconfig:
#define ADC_5ANA    // enable analog AN0, enable digital AN1 to AN5


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