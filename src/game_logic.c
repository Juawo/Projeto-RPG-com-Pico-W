#include <stdlib.h>
#include <stdio.h>
#include <src/game_logic.h>
#include <src/display.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define MAX_ESCOLHAS 4
#define MAX_TEXTO 32

char historico[MAX_ESCOLHAS][MAX_TEXTO];
int escolha_atual = 0;

Escolha escolha1 = {"  textoA1   ", "  textoB1   ", NULL};
Escolha escolha2 = {"  textoA2   ", "  textoB2   ", NULL};
Escolha escolha3 = {"  textoA3   ", "  textoB3   ", NULL};
Escolha escolha4 = {"  textoA4   ", "  textoB4   ", NULL};
Escolha escolha_temp;

void iniciar_jogo()
{
    escolha1.proxEsc = &escolha2;
    escolha2.proxEsc = &escolha3;
    escolha3.proxEsc = &escolha4;
    escolha4.proxEsc = NULL;

    escolha_temp = escolha1;

    escolha_atual = 0;
    exibir_escolha(&escolha1);
    sleep_ms(500);
}

void processar_escolha(int opcao)
{

    if (escolha_atual >= MAX_ESCOLHAS)
    {
        printf("Escolha atual excedeu o máximo de escolhas.\n");
        return;
    }
    
    // Salvar na lista de historico, com limite de 32 caracteres do tipo string, se a opcao == 0, salva opcaoA e se não, salva opcaoB
    snprintf(historico[escolha_atual], MAX_TEXTO, "%s", opcao == 0 ? escolha_temp.opcaoA : escolha_temp.opcaoB);

    escolha_atual++;

    if (escolha_temp.proxEsc != NULL)
    {
        escolha_temp = *escolha_temp.proxEsc;
        exibir_escolha(&escolha_temp);
    }
    else
    {
        exibir_resultado();
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