#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "hal/adc_types.h"

void adc_init(int channel, int attenuation, int unit_id, adc_oneshot_unit_handle_t *adc_handle);
float adc_read(int channel, adc_oneshot_unit_handle_t adc_handle);
