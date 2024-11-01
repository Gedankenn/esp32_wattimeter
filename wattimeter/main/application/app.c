#include "app.h"
#include "acs712.h"
#include "voltage.h"
#include "adc.h"

#define delay_ms(ms) vTaskDelay(ms / portTICK_PERIOD_MS)


void app_main(void *args)
{
    adc1_init();
    Voltage_init();
    ACS712_init();
    float current = 0;
    float voltage = 0;
    while (1)
    {
        current = ACS712_read();
        voltage = Voltage_read();
            
        printf("----- Main ---------\n");
        printf("Current: %f\n", current);
        printf("Voltage: %f\n", voltage);
        printf("----------------------\n");

        delay_ms(2500);
    }
}
