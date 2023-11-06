#include <stdlib.h>
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

#define ROJO 16
#define AMARILLO 17
#define VERDE 18

static uint8_t color;

bool alarm_callback(struct repeating_timer *t)
{

    if(color%3 == 0)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,true);
            t->delay_us = 2000000;
        }
    else if(color%3 == 1)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,false);
            t->delay_us = 600000;
        }
    else if(color%3 == 2)
        {
            gpio_put(ROJO,true);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,false);
            t->delay_us = 2000000;
        }
    
    color++;


    // gpio_xor_mask(1ul<<ROJO);

    return true;
}

void main(void)
{
    struct repeating_timer timer;
    color = 0;

    gpio_init(ROJO);
    gpio_set_function(ROJO,GPIO_FUNC_SIO);
    gpio_set_dir(ROJO,true);

    gpio_init(VERDE);
    gpio_set_function(VERDE,GPIO_FUNC_SIO);
    gpio_set_dir(VERDE,true);

    gpio_init(AMARILLO);
    gpio_set_function(AMARILLO,GPIO_FUNC_SIO);
    gpio_set_dir(AMARILLO,true);

    add_repeating_timer_ms(800,&alarm_callback,NULL,&timer);

    while(true);


    // return;
}