#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"

// ADC1_0 = 36
#define ADC1_CHANNEL ADC_CHANNEL_0  // GPIO36
#define ADC_ATTEN ADC_ATTEN_DB_12     // 12 dB attenuation


void adc_init();
float adc_read();
