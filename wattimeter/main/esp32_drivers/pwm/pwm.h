
#include "driver/ledc.h"

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_HIGH_SPEED_MODE
#define LEDC_OUTPUT_IO_1        25  // Define the output GPIO for PWM on pin 25
#define LEDC_OUTPUT_IO_2        26  // Define the output GPIO for PWM on pin 26
#define FOWARD                  LEDC_CHANNEL_0
#define BACKWARD                LEDC_CHANNEL_1
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT  // Resolution of PWM duty
#define LEDC_DUTY               4000               // Duty cycle (0-8191 for 13-bit)
#define LEDC_FREQUENCY          5000               // Frequency in Hertz. Set frequency at 5 kHz


void PWM_init(void);
void update_duty_cicle(int duty, int channel);
