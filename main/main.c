/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


// 1 Vamos inicializar os pinos, no caso vamos fazer para o pino de LED inicialmente
const int PIN_LED= 16;

// 2 Agora vamos inicializar o pino para o botão: que vai ser o roxo, que é o pino do positivo e o outro vai ser no GND
const int PIN_BOTAO = 14;

// 3 Agora vamos inicializar os pinos referentes aos motores, vamos designar por motor i o motor
// o qual possui o pino que se encontra mais acima na vertical, ou seja, possui a menor numeração
const int PIN_M1= 2;
const int PIN_M2= 3;
const int PIN_M3= 4;
const int PIN_M4= 5;

int main() {
    stdio_init_all();

    // 4 Inicializando o pino LED
    gpio_init(PIN_LED);
    // 5 Configurando o pino do LED como saida 
    gpio_set_dir(PIN_LED,GPIO_OUT);
    //6 agora abaixo vamos aplicar a primeira funcionalidade de fazer piscar o LED

    // 7 configurando o pino do botao como entrada e inicializando ele:
    gpio_init(PIN_BOTAO);
    gpio_set_dir(PIN_BOTAO,GPIO_IN);
    gpio_pull_up(PIN_BOTAO);

    //8 Agora vamos fazer o motor girar:
    // 9 Vamos inicializar os pinos do motor e definir as portas
    gpio_init(PIN_M1);
    gpio_init(PIN_M2);
    gpio_init(PIN_M3);
    gpio_init(PIN_M4);

    gpio_set_dir(PIN_M1,GPIO_OUT);
    gpio_set_dir(PIN_M2,GPIO_OUT);
    gpio_set_dir(PIN_M3,GPIO_OUT);
    gpio_set_dir(PIN_M4,GPIO_OUT);





    while (true) {
        int i=0;

        if(!gpio_get(PIN_BOTAO)){
            gpio_put(PIN_LED,1);
            sleep_ms(100);
            
            for (i = 0; i < 512; i++)
            {
            int sono = 10;
           
            
           

            gpio_put(PIN_M1,1);
            sleep_ms(sono);
            gpio_put(PIN_M1,0);
            gpio_put(PIN_M2,1);
            sleep_ms(sono);
            gpio_put(PIN_M2,0);

            gpio_put(PIN_M3,1);
            sleep_ms(sono);
            gpio_put(PIN_M3,0);
            gpio_put(PIN_M4,1);
            sleep_ms(sono);
            gpio_put(PIN_M4,0);
            


            


                
            }
            gpio_put(PIN_LED,0);
            





            
        }
    }
}

