// #include <stdio.h>
#include <stdlib.h>
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/time.h"

#define DIV 250
#define WRAP 10000

#define PIN 2

void main()
{
    uint slice_num;
    gpio_set_function(PIN,GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(PIN);

    pwm_set_wrap(slice_num, WRAP) ;
    pwm_set_clkdiv(slice_num, DIV) ;

    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);

    pwm_set_enabled(slice_num,true);


    while(true)
    {
        pwm_set_chan_level(slice_num, PWM_CHAN_A, 500);
        sleep_ms(1000);

        pwm_set_chan_level(slice_num, PWM_CHAN_A, 750);
        sleep_ms(1000);

        pwm_set_chan_level(slice_num, PWM_CHAN_A, 1000);
        sleep_ms(1000);
    }


    return;
}