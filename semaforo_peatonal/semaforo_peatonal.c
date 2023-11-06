#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define BOTON 15
#define ROJO 16
#define AMARILLO 17
#define VERDE 18


enum estado {
    verde = 0,
    amarillo = 1,
    rojo = 2
};

uint8_t luz;

void irq_callback(uint gpio, uint32_t evento)
{
    luz = 1;

    gpio_put(ROJO,false);
    gpio_put(AMARILLO,true);
    gpio_put(VERDE,false);

    // sleep_ms(1000);

    // // irq_clear(IO_IRQ_BANK0);


    // gpio_put(ROJO,true);
    // gpio_put(AMARILLO,false);
    // gpio_put(VERDE,true);

    // sleep_ms(1000);


    return;

    // gpio_irq_
}



void main()
{
gpio_init_mask((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));
gpio_set_dir_out_masked((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));
gpio_put(ROJO,true);
gpio_put(AMARILLO,true);
gpio_put(VERDE,true);

sleep_ms(150);

gpio_put(ROJO,false);
gpio_put(AMARILLO,false);
gpio_put(VERDE,true);

gpio_init(BOTON);
gpio_set_function(BOTON,GPIO_FUNC_SIO);
gpio_set_pulls(BOTON,true,false);
// gpio_set_irq_enabled_with_callback(BOTON,GPIO_IRQ_LEVEL_LOW,true,&irq_callback);
gpio_set_irq_enabled_with_callback(BOTON,GPIO_IRQ_EDGE_RISE,true,&irq_callback);

// irq_set_enabled(IO_IRQ_BANK0, true);

luz = 0;

while(true)
{

    // switch (luz)
    // {
    // case 0:
    //     gpio_put(ROJO,false);
    //     gpio_put(AMARILLO,false);
    //     gpio_put(VERDE,true);


    //     break;

    // case 1:
    //     gpio_put(ROJO,false);
    //     gpio_put(AMARILLO,true);
    //     gpio_put(VERDE,false);

    //     sleep_ms(500);

    //     luz = rojo;
    //     break;

    // case 2:
    //     gpio_put(ROJO,true);
    //     gpio_put(AMARILLO,false);
    //     gpio_put(VERDE,false);

    //     sleep_ms(3000);

    //     luz = verde;
    //     break;
    
    // default:
    //     break;
    // }

    if(gpio_get(VERDE) == true)
    // if(luz == 0)
    {
        gpio_put(ROJO,false);
        gpio_put(AMARILLO,false);
        gpio_put(VERDE,true);
    }  
    else if(gpio_get(AMARILLO)==true)
    // else if(luz == 1)
    {
        gpio_put(ROJO,false);
        gpio_put(AMARILLO,true);
        gpio_put(VERDE,false);

        sleep_ms(500);

        gpio_put(ROJO,true);
        gpio_put(AMARILLO,false);
        gpio_put(VERDE,false);

        luz = 2;
    }
    else if(gpio_get(ROJO)==true)
    // else if(luz == 2)
    {

        gpio_put(ROJO,true);
        gpio_put(AMARILLO,false);
        gpio_put(VERDE,false);

        sleep_ms(3000);

        gpio_put(ROJO,false);
        gpio_put(AMARILLO,false);
        gpio_put(VERDE,true);

        luz = 0;
    }

}





}