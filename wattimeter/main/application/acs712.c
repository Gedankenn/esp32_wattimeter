#include "acs712.h"
#include "adc.h"

#define ADC_CHANNEL ADC_CHANNEL_0
#define ADC_UNIT ADC_UNIT_1
#define ADC_ATTEN ADC_ATTEN_DB_12


//Create adc handle
adc_oneshot_unit_handle_t adc_handle;

float ACS712Gain = 0.1;
float ADCGain = 0.66;
float ADCOffset = 2.5;

#define ADC_TO_VOLTAGE(adc) ((adc * 3.3) / 4095)
#define ADC_TO_CURRENT(adc) ((adc - ADCOffset) / ADCGain)

float ACS712_read()
{
    float raw = adc_read(ADC_CHANNEL, adc_handle);
    printf("ADC raw: %f\n", raw);
    float voltage = ADC_TO_VOLTAGE(raw);
    printf("Voltage: %f\n", voltage);
    float current = ADC_TO_CURRENT(raw);
    printf("Current: %f\n", current);
    return current;
}

void ACS712_init()
{
    adc_init(ADC_CHANNEL, ADC_ATTEN, ADC_UNIT, &adc_handle);
}
