#include <stdio.h>
#include "pico/stdlib.h"
#include "src/display.h"
#include "src/game_logic.h"
#include "src/input.h"
#include "src/globals.h"

volatile int escolha_pendente = -1;

int main()
{
    stdio_init_all();

    display_init();
    input_init();
    iniciar_jogo();

    while (true)
    {
        if (escolha_pendente != -1)
        {
            processar_escolha(escolha_pendente);
            escolha_pendente = -1;
        }
        sleep_ms(100);
    }

    return 0;
}
