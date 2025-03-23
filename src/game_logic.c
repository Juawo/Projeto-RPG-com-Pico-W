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

Escolha escolha1 = {"  textoA1   ", "  textoB1   ", NULL};
Escolha escolha2 = {"  textoA2   ", "  textoB2   ", NULL};
Escolha escolha3 = {"  textoA3   ", "  textoB3   ", NULL};
Escolha escolha4 = {"  textoA4   ", "  textoB4   ", NULL};
Escolha *escolha_atual_ptr = &escolha1;

void iniciar_jogo()
{
    escolha_atual_ptr = &escolha1;

    escolha1.proxEsc = &escolha2;
    escolha2.proxEsc = &escolha3;
    escolha3.proxEsc = &escolha4;
    escolha4.proxEsc = NULL;

    escolha_atual = 0;
    exibir_escolha(&escolha1);
}

void processar_escolha(int opcao)
{
    if (escolha_atual >= MAX_ESCOLHAS)
    {
        return;
    }

    // Salvar na lista de historico, com limite de 32 caracteres do tipo string, se a opcao == 0, salva opcaoA e se não, salva opcaoB
    snprintf(historico[escolha_atual], MAX_TEXTO, "%s", opcao == 0 ? escolha_atual_ptr->opcaoA : escolha_atual_ptr->opcaoB);

    escolha_atual++;

    if (escolha_atual_ptr->proxEsc != NULL)
    {
        escolha_atual_ptr = escolha_atual_ptr->proxEsc;
        exibir_escolha(escolha_atual_ptr);
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