#include "acs712.h"
#include "adc.h"

#define ADC_CHANNEL ADC_CHANNEL_0
float ACS712Gain = 0.1;
float ADCGain = 0.66;
float ADCOffset = 2.5;

#define ADC_TO_VOLTAGE(adc) ((adc * 3.3) / 4095)
#define ADC_TO_CURRENT(adc) ((adc - ADCOffset) / ADCGain)

float ACS712_read()
{
    float raw = adc_read(ADC_CHANNEL);
    printf("ADC raw: %f\n", raw);
    float voltage = ADC_TO_VOLTAGE(raw);
    printf("Voltage: %f\n", voltage);
    float current = ADC_TO_CURRENT(raw);
    printf("Current: %f\n", current);
    return current;
}
