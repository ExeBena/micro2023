// #include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define ROJO 16
#define AMARILLO 17
#define VERDE 18


int main() {

    adc_init();


    adc_gpio_init(28);
    adc_select_input(2);


    gpio_init_mask((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));
    gpio_set_dir_out_masked((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));

    gpio_put(ROJO,false);
    gpio_put(AMARILLO,false);
    gpio_put(VERDE,false);


    while (1) {

        uint16_t resul = adc_read(); // entre 0 y 4096

        if(resul < 1274)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,false);
        }
        else if(1274 <= resul && resul < 2*1274)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,true);
        }
        else if(2*1274 <= resul && resul < 3*1274)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,true);
        }
        else if(3*1274 <= resul )
        {
            gpio_put(ROJO,true);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,true);
        }




        sleep_ms(50);
    }
}
