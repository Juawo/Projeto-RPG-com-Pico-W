#include <stdlib.h>
#include <stdio.h>
#include <game_logic.h>
#include <display.h>

char historico[4][32];
int escolha_atual = 0;

Escolha escolha1 = {"  textoA   ", "  textoB   ", NULL};
Escolha escolha2 = {"  textoA   ", "  textoB   ", NULL};
Escolha escolha3 = {"  textoA   ", "  textoB   ", NULL};
Escolha escolha4 = {"  textoA   ", "  textoB   ", NULL};
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
}

void processar_escolha(int opcao)
{
    if (escolha_atual >= 4)
    {
        return;
    }

    // Salvar na lista de historico, com limite de 32 caracter do tipo string, se a opcao == 0, salva opcaoA e se não, salva opcaoB
    snprintf(historico[escolha_atual], 32, "%s", opcao == 0 ? escolha1.opcaoA : escolha1.opcaoB);
    
    escolha_atual++;

    if (escolha_temp.proxEsc != NULL)
    {
        escolha_temp = *escolha_temp.proxEsc;
    }
    else
    {
        exibir_resultado();
    }

}

void exibir_resultado()
{
    printf("--- Resultado de todas as suas escolhas ---\n");

    for (uint i = 0; i < 4; i++)
    {
        printf("%dª Escolha : %s", i + 1, historico[i]);
    }

    sleep_ms(5000);
    iniciar_jogo();
}