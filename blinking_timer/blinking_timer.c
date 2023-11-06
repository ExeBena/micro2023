#include <stdlib.h>
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

#define ROJO 16
#define AMARILLO 17
#define VERDE 18

uint8_t alarm_callback(struct repeating_timer *t)
{
    gpio_xor_mask(1ul<<VERDE);
}

void main(void)
{
    struct repeating_timer timer;

    gpio_init(VERDE);
    gpio_set_function(VERDE,GPIO_FUNC_SIO);
    gpio_set_dir(VERDE,true);

    add_repeating_timer_ms(200,alarm_callback,NULL,&timer);

    while(true);


    // return;
}