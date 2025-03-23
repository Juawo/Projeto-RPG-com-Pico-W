#include <stdlib.h>
#include <stdio.h>
#include <src/game_logic.h>
#include <src/display.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define MAX_ESCOLHAS 4
#define MAX_TEXTO 128

char historico[MAX_ESCOLHAS][MAX_TEXTO];
int escolha_atual = 0;

Escolha escolha1 = {"Reparar modulos da nave danificados", "Redirecionar energia ao propulsor"};
Escolha escolha2 = {"Algo se move no casco. Investigar?", "Algo se move no casco. Ignorar"};
Escolha escolha3 = {"tentar falar com a criatura", "tranca-la fora da nave"};
Escolha escolha4 = {"Pegou o artefato brilhante dele", "Fugiu sem olhar para tras"};
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
        limpar_display();
        exibir_escolha(&escolhas[escolha_atual]);
    }
}

void exibir_resultado()
{
    printf("--- Sua épica história ---\n");

    for (int i = 0; i < MAX_ESCOLHAS; i++)
    {
        if (i == 0)
        {
            printf("Ao %s, ", historico[i]);
        }
        else if (i == 2)
        {
            printf("Então ao %s,", historico[i]);
        }
        else
        {
            printf("%s.\n", historico[i]);
        }
    }

    sleep_ms(5000);
    iniciar_jogo();
}