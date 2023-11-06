#include "pico/stdlib.h"
#include "pico/time.h"

#define rojo 16
#define amarillo 17
#define verde 18


void main(){

gpio_init_mask((1ul<<rojo)|(1ul<<amarillo)|(1ul<<verde));
// gpio_init(rojo);
// gpio_init(amarillo);
// gpio_init(verde);


gpio_set_dir_out_masked((1ul<<rojo)|(1ul<<amarillo)|(1ul<<verde));
// gpio_set_dir(rojo,GPIO_OUT);
// gpio_set_dir(amarillo,GPIO_OUT);
// gpio_set_dir(verde,GPIO_OUT);

gpio_put(rojo,false);
gpio_put(amarillo,false);
gpio_put(verde,false);


while(true)
{
    gpio_put(rojo,true);
    gpio_put(amarillo,false);
    gpio_put(verde,false);
    sleep_ms(2000);

    gpio_put(rojo,false);
    gpio_put(amarillo,false);
    gpio_put(verde,true);
    sleep_ms(2000);

    gpio_put(rojo,false);
    gpio_put(amarillo,true);
    gpio_put(verde,false);
    sleep_ms(500);


}


}