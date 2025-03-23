#include <stdio.h>
#include "pico/stdlib.h"
#include "src/game_logic.h"
#include "globals.h"

#define BTN_A 05
#define BTN_B 06

void btn_callback(uint gpio, uint32_t events)
{
    if (gpio == BTN_A)
    {
        printf("Escolha A\n");
        escolha_pendente = 0;
    }
    
    if (gpio == BTN_B)
    {
        printf("Escolha B\n");
        escolha_pendente = 1;
    }
}

void input_init()
{
    gpio_set_function(BTN_A, GPIO_FUNC_SIO);
    gpio_set_function(BTN_B, GPIO_FUNC_SIO);
    
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_set_dir(BTN_B, GPIO_IN);
    
    gpio_pull_up(BTN_A);
    gpio_pull_up(BTN_B);

    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_RISE, true, &btn_callback);
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_RISE, true, &btn_callback);
    
}