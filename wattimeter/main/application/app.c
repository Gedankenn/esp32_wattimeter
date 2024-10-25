#include "app.h"
#include "hal/adc_types.h"
#include "acs712.h"

#define ADC_CHANNEL ADC_CHANNEL_0
#define ADC_ATTEN ADC_ATTEN_DB_12

#define delay_ms(ms) vTaskDelay(ms / portTICK_PERIOD_MS)

// Since the ADC has a delay of 1ms and we want to read a full cycle of the AC signal
// and the frequency is 60Hz, so we will read 16 samples per cycle

void app_main(void *args)
{
    adc_init(ADC_CHANNEL, ADC_ATTEN);
    while (1)
    {
        float current = ACS712_read();
        delay_ms(1);
    }
}
