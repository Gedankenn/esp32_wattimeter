#include "pwm.h"



void PWM_init(void)
{
    // Prepare and initialize configuration for the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_TIMER,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = LEDC_FREQUENCY,   // Set output frequency at 5 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    
    // Set configuration of the LEDC timer
    ledc_timer_config(&ledc_timer);

    // Prepare and initialize configuration for the LEDC channel (GPIO 25)
    ledc_channel_config_t ledc_channel_1 = {
        .speed_mode     = LEDC_MODE,
        .channel        = FOWARD,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_OUTPUT_IO_1,
        .duty           = 0,                // Set duty cycle to 0 initially
        .hpoint         = 0
    };

    // Set configuration of the LEDC channel (GPIO 26)
    ledc_channel_config_t ledc_channel_2 = {
        .speed_mode     = LEDC_MODE,
        .channel        = BACKWARD,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_OUTPUT_IO_2,
        .duty           = 0,                // Set duty cycle to 0 initially
        .hpoint         = 0
    };

    // Set configuration for the channels
    ledc_channel_config(&ledc_channel_1);
    ledc_channel_config(&ledc_channel_2);

    // Set duty cycle for GPIO 25
    ledc_set_duty(LEDC_MODE, FOWARD, LEDC_DUTY);
    ledc_update_duty(LEDC_MODE, FOWARD);

    // Set duty cycle for GPIO 26
    ledc_set_duty(LEDC_MODE, BACKWARD, LEDC_DUTY);
    ledc_update_duty(LEDC_MODE, BACKWARD);

}

void update_duty_cicle(int duty, int channel)
{
    // Set duty cycle for GPIO 25
    // duty = 0-8191 for 13-bit
    
    ledc_set_duty(LEDC_MODE, channel, duty);
    ledc_update_duty(LEDC_MODE, channel);
}
