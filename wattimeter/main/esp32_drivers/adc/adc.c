#include "adc.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_oneshot.h"
#include "hal/adc_types.h"


adc_oneshot_unit_handle_t adc_handle;

void adc_init(int channel, int attenuation)
{
    // Configure ADC
    adc_oneshot_unit_init_cfg_t cfg = {
        .unit_id = ADC_UNIT_1,
    };

    adc_oneshot_new_unit(&cfg, &adc_handle);

    adc_oneshot_chan_cfg_t chan_cfg = {
        .atten = attenuation,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };

    adc_oneshot_config_channel(adc_handle, channel, &chan_cfg);

    // Calibrate ADC
    adc_cali_handle_t handle = NULL;
    adc_cali_line_fitting_config_t cali_config = {
        .unit_id = ADC_UNIT_1,
        .atten = attenuation,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    bool ret = adc_cali_create_scheme_line_fitting(&cali_config, &handle);
    int raw = 0;
    adc_oneshot_read(adc_handle, channel, &raw);
    //int voltage = 0;
    //adc_cali_raw_to_voltage(handle, raw, &voltage);
    if (ret == ESP_OK) 
    {
        printf("ADC calibration scheme created\n");
    }
    else 
{
        printf("ADC calibration scheme creation failed\n");
    }
}

float adc_read(int channel)
{
    // Read ADC
    int raw = 0;
    adc_oneshot_read(adc_handle, channel, &raw);
    return raw;
}

