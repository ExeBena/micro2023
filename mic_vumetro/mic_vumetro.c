// #include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define ROJO 16
#define AMARILLO 17
#define VERDE 18

#define UMBRAL (uint32_t)262144*4


int main() {

    uint16_t samples[5] = {0,0,0,0,0};
    uint32_t resul = 0;
    uint8_t i = 0;

    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);


    gpio_init_mask((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));
    gpio_set_dir_out_masked((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));

    gpio_put(ROJO,false);
    gpio_put(AMARILLO,false);
    gpio_put(VERDE,false);


    while (1) {

        if(i<5)
        {
            samples[i] = adc_read(); // entre 0 y 4096
            i++;
        }
        else
        {
            samples[0]=samples[1];
            samples[1]=samples[2];
            samples[2]=samples[3];
            samples[3]=samples[4];
            samples[4] = adc_read();
        }

        resul = (uint32_t)(samples[0]*samples[0]+samples[1]*samples[1]+samples[2]*samples[2]
        +samples[3]*samples[3]+samples[4]*samples[4])/5;
        // resul = adc_read();

        if(resul < 1.25*UMBRAL)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,false);
        }
        else if(1.25*UMBRAL <= resul && resul < 1.5*UMBRAL)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,true);
        }
        else if(1.5*UMBRAL <= resul && resul < 1.75*UMBRAL)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,true);
        }
        else if(1.75*UMBRAL <= resul )
        {
            gpio_put(ROJO,true);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,true);
        }




        sleep_ms(50);
    }
}
