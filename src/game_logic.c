#include <stdlib.h>
#include <stdio.h>
#include <src/game_logic.h>
#include <src/display.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define MAX_ESCOLHAS 4
#define MAX_TEXTO 32
#define BTN_A 05
#define BTN_B 06

char historico[MAX_ESCOLHAS][MAX_TEXTO];
int escolha_atual = 0;

Escolha escolha1 = {"  textoA1   ", "  textoB1   "};
Escolha escolha2 = {"  textoA2   ", "  textoB2   "};
Escolha escolha3 = {"  textoA3   ", "  textoB3   "};
Escolha escolha4 = {"  textoA4   ", "  textoB4   "};
Escolha escolhas[4];

void iniciar_jogo()
{
    escolha_atual = 0;
    escolhas[0] = escolha1;
    escolhas[1] = escolha2;
    escolhas[2] = escolha3;
    escolhas[3] = escolha4;

    exibir_escolha(&escolhas[escolha_atual]);
}

void processar_escolha(int opcao)
{
    if (escolha_atual >= MAX_ESCOLHAS)
    {
        exibir_resultado();
    }

    // Salvar na lista de historico, com limite de 32 caracteres do tipo string, se a opcao == 0, salva opcaoA e se não, salva opcaoB
    snprintf(historico[escolha_atual], MAX_TEXTO, "%s", opcao == 0 ? escolhas[escolha_atual].opcaoA : escolhas[escolha_atual].opcaoB);

    escolha_atual++;

    if (escolha_atual >= MAX_ESCOLHAS)
    {
        exibir_resultado();
    }
    else
    {
        exibir_escolha(&escolhas[escolha_atual]);
    }
}

void exibir_resultado()
{
     printf("--- Resultado de todas as suas escolhas ---\n");

    for (int i = 0; i < MAX_ESCOLHAS; i++)
    {
        printf("%dª Escolha : %s\n", i + 1, historico[i]);
    }

    sleep_ms(5000);
    iniciar_jogo();
}