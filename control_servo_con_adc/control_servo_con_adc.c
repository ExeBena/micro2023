#include <stdio.h>
#include <stdlib.h>
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "pico/time.h"
#include "pico/stdlib.h"


#define DIV 250
#define WRAP 10000

#define PIN 2

void main()
{

    stdio_init_all();
    uint slice_num;
    uint16_t res;
    float grados;

    gpio_set_function(PIN,GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(PIN);

    pwm_set_wrap(slice_num, WRAP) ;
    pwm_set_clkdiv(slice_num, DIV) ;

    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
    pwm_set_enabled(slice_num, true);

    adc_init();
    adc_gpio_init(28);
    adc_select_input(2);

    pwm_set_chan_level(slice_num, PWM_CHAN_A, 500);
    sleep_ms(1000);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 1000);
    sleep_ms(1000);

    while(true)
    {

        res = adc_read(); // entre 0 y 4096
        grados =   500 *((float)res/(4096-1));

        // printf("%2.2f\n", );

        pwm_set_chan_level(slice_num, PWM_CHAN_A, 500 + grados);
        sleep_ms(100);
    }


    return;
}