#include "app.h"
#include "hal/adc_types.h"
#include "acs712.h"

#define delay_ms(ms) vTaskDelay(ms / portTICK_PERIOD_MS)

// Since the ADC has a delay of 1ms and we want to read a full cycle of the AC signal
// and the frequency is 60Hz, so we will read 16 samples per cycle

void app_main(void *args)
{
    while (1)
    {
        float current = ACS712_read();
        delay_ms(1);
    }
}
