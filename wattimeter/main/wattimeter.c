#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include <math.h>
#include <time.h>
#include "esp_timer.h"
#include "esp_attr.h"

#include "app.h"

TaskHandle_t task_handle = NULL;

#define delay_ms(ms) vTaskDelay(ms / portTICK_PERIOD_MS)

int main(void)
{
    printf("minimum stack size: %d\n", configMINIMAL_STACK_SIZE);

    // Create a task
    xTaskCreate(app_main, "wattimeter", 2048, NULL, 1, &task_handle);
  
    while(1)
    {
        delay_ms(1000);
    }
    return 0;
}
