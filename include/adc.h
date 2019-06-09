#ifndef ADC_H
#define ADC_H

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