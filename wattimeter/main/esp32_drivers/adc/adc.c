#include "adc.h"
#include "driver/adc_types_legacy.h"
#include "esp_adc/adc_oneshot.h"

static adc_oneshot_unit_handle_t adc1_handle = NULL;
static adc_oneshot_unit_handle_t adc2_handle = NULL;

adc_oneshot_chan_cfg_t adc1_chan_cfg = {
    .bitwidth = ADC_WIDTH_BIT_12,
    .atten = ADC_ATTEN_DB_12,
};
adc_oneshot_chan_cfg_t adc2_chan_cfg = {
    .bitwidth = ADC_WIDTH_BIT_12,
    .atten = ADC_ATTEN_DB_12,
};

void adc1_init(void)
{
    adc_oneshot_unit_init_cfg_t unity_cfg = {
        .unit_id = ADC_UNIT_1,
    };
    adc_oneshot_new_unit(&unity_cfg, &adc1_handle);
}

void adc1_channel_init(int channel)
{
    adc_oneshot_config_channel(adc1_handle, channel, &adc1_chan_cfg);
}

int adc1_read(int channel)
{
    int raw;
    adc_oneshot_read(adc1_handle, channel, &raw);
    return raw;
}

void adc2_init(void)
{
    adc_oneshot_unit_init_cfg_t unity_cfg = {
        .unit_id = ADC_UNIT_2,
    };
    adc_oneshot_new_unit(&unity_cfg, &adc2_handle);
}

void adc2_channel_init(int channel)
{
    adc_oneshot_config_channel(adc2_handle, channel, &adc2_chan_cfg);
}

int adc2_read(int channel)
{
    int raw;
    adc_oneshot_read(adc2_handle, channel, &raw);
    return raw;
}
