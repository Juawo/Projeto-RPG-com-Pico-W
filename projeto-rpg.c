#include <stdio.h>
#include "pico/stdlib.h"
#include "src/display.h"
#include "src/game_logic.h"
#include "src/input.h"

int main()
{
    stdio_init_all();

    display_init();
    input_init();
    iniciar_jogo();

    while (true)
    {
        sleep_ms(1000);
    }

    return 0;
}
