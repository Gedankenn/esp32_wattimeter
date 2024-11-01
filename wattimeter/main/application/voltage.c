#include "voltage.h"
#include <stdio.h>

//Define ADC 1 channel 6 as the voltage sensor
//This is the GPIO 34

#define ADC_CHANNEL ADC_CHANNEL_6
#define ADC_UNIT ADC_UNIT_1
#define ADC_ATTEN ADC_ATTEN_DB_12

#define ADC_TO_VOLTAGE(adc) ((adc * 3.3) / 4095)
#define VOLTAGE_TO_VALUE(voltage) (voltage / VoltageGain)

//Create adc handle
adc_oneshot_unit_handle_t voltage_handle;

//Define the Voltage sensor gain
//(1k/(1k+68k)) = 0.0147

float VoltageGain = 0.0147;

void Voltage_init()
{
    adc1_channel_init(ADC_CHANNEL);
}

float Voltage_read()
{
    int raw = adc1_read(ADC_CHANNEL);
    printf("----- Voltage ---------\n");
    printf("ADC raw: %d\n", raw);
    float voltage = ADC_TO_VOLTAGE(raw);
    printf("Voltage: %f\n", voltage);
    float value = VOLTAGE_TO_VALUE(voltage);
    printf("Value: %f\n", value);
    printf("----------------------\n");
    return voltage;
}
