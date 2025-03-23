#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include <src/game_logic.h>

#define I2C_SDA 14
#define I2C_SCL 15
#define MAX_LINHA 14

struct render_area frame_area = {
    start_column : 0,
    end_column : ssd1306_width - 1,
    start_page : 0,
    end_page : ssd1306_n_pages - 1
};

uint8_t ssd[ssd1306_buffer_length];


void display_init()
{
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);

    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    calculate_render_area_buffer_length(&frame_area);

    // zera o display inteiro
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);
}

void exibir_escolha(Escolha *escolha)
{

    char *text[] = {
        escolha->opcaoA,
        escolha->opcaoB};

    int y = 0;

    for (uint i = 0; i < count_of(text); i++)
    {
        char buffer[16];
        int len = strlen(text[i]);

        for (int j = 0; j < len; j += MAX_LINHA)
        {
            strncpy(buffer, &text[i][j], MAX_LINHA);
            buffer[MAX_LINHA] = '\0'; // Garantir fim da string
            ssd1306_draw_string(ssd, 5, y, buffer);
            y += 8;
        }

        y += 8;
    }

    render_on_display(ssd, &frame_area);
}

void limpar_display()
{
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);
}