#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/timer.h"
#include "hardware/uart.h"

#define ROJO 16
#define AMARILLO 17
#define VERDE 18

// #define UMBRAL (uint32_t)262144*4
#define BASE 0.0048
#define UMBRAL (int32_t) 0.9952

#define ADC_NUM 0
#define ADC_PIN (26 + ADC_NUM)
#define ADC_VREF 3.3
#define ADC_RANGE (1 << 12)
#define ADC_CONVERT (ADC_VREF / (ADC_RANGE - 1))


// bool alarm_callback(struct repeating_timer *t)
// {
//     // ADC_CS_START_ONCE_BITS = 1;
//     // ADC_BASE + ADC_CS_OFFSET + ADC_CS_START_ONCE_BITS;
//     adc_hw->cs |= ADC_CS_START_ONCE_BITS;

    
//     add_alarm_in_us(125, &alarm_callback, NULL , false);
// }


int main() {

    uint16_t samples[5] = {0,0,0,0,0};
    uint32_t res = 0, prom = 0;
    int32_t audio = 0;
    uint8_t i = 0;


    stdio_init_all();
    printf("Beep boop, listening...\n");

    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);


    gpio_init_mask((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));
    gpio_set_dir_out_masked((1ul<<ROJO)|(1ul<<AMARILLO)|(1ul<<VERDE));

    gpio_put(ROJO,false);
    gpio_put(AMARILLO,false);
    gpio_put(VERDE,false);



    // add_alarm_in_us(125, &alarm_callback, NULL , false);

    while (1) {

        res = adc_read();

        // if((adc_hw->cs && ADC_CS_READY_BITS)==1)
        // {
            if(i<5)
            {
                // res = adc_hw->result;
                samples[i] = res; // entre 0 y 4096
                i++;
            }
            else
            {
                // res = adc_hw->result;
                samples[0]=samples[1];
                samples[1]=samples[2];
                samples[2]=samples[3];
                samples[3]=samples[4];
                samples[4] = res;
            }

            
        // }
        // prom = (uint32_t)(samples[0]*samples[0]+samples[1]*samples[1]+samples[2]*samples[2]
        // +samples[3]*samples[3]+samples[4]*samples[4])/5;
        prom = (uint32_t)(samples[0]+samples[1]+samples[2]+samples[3]+samples[4])/5;

        audio = (int32_t) (res-prom);

        // printf("%3.4f\n", audio * ADC_CONVERT);

        sleep_us(125);
        // sleep_ms(50);


        





        // if(i<5)
        // {
        //     samples[i] = adc_read(); // entre 0 y 4096
        //     i++;
        // }
        // else
        // {
        //     samples[0]=samples[1];
        //     samples[1]=samples[2];
        //     samples[2]=samples[3];
        //     samples[3]=samples[4];
        //     samples[4] = adc_read();
        // }

        // resul = (uint32_t)(samples[0]*samples[0]+samples[1]*samples[1]+samples[2]*samples[2]
        // +samples[3]*samples[3]+samples[4]*samples[4])/5;
        // // resul = adc_read();

        if(audio < 0)
                audio*=-1;

        printf("%3.4f\n", audio * ADC_CONVERT);

        if(audio * ADC_CONVERT < 0.15)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,false);
        }
        else if(0.15 <= audio * ADC_CONVERT && audio * ADC_CONVERT < 0.5)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,false);
            gpio_put(VERDE,true);
        }
        else if(0.5 <= audio * ADC_CONVERT && audio * ADC_CONVERT < 0.75)
        {
            gpio_put(ROJO,false);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,true);
        }
        else if(0.75 <= audio * ADC_CONVERT )
        {
            gpio_put(ROJO,true);
            gpio_put(AMARILLO,true);
            gpio_put(VERDE,true);
        }




        // sleep_ms(50);
    }
}
