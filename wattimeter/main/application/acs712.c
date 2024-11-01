#include "acs712.h"
#include "adc.h"


#define ADC_CHANNEL ADC_CHANNEL_0
#define ADC_UNIT ADC_UNIT_1
#define ADC_ATTEN ADC_ATTEN_DB_12


//Create adc handle
adc_oneshot_unit_handle_t acs712_handle;

float ACS712Gain = 0.1;
float ADCGain = 0.66;
float ADCOffset = 2.5;

#define ADC_TO_VOLTAGE(adc) ((adc * 3.3) / 4095)
#define ADC_TO_CURRENT(adc) ((adc + ADCOffset) / ADCGain)
#define VOLTAGE_TO_CURRENT(voltage) (((voltage / ADCGain) - ADCOffset) / ACS712Gain )

float ACS712_read()
{
    int raw = adc1_read(ADC_CHANNEL);
    printf("--- ADC712 -----\n");
    printf("ADC raw: %d\n", raw);
    float voltage = ADC_TO_VOLTAGE(raw);
    printf("Voltage: %f\n", voltage);
    float current = VOLTAGE_TO_CURRENT(voltage);
    printf("Value: %f\n", current);
    printf("---------------\n");
    return current;
}

void ACS712_init()
{
    adc1_channel_init(ADC_CHANNEL);
}
