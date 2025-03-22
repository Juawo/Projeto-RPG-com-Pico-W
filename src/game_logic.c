#include <stdlib.h>
#include <stdio.h>
#include <game_logic.h>
#include <display.h>


char historico[4][32];
int escolha_atual = 0;

Escolha escolha1 = {"textoA", "textoB", NULL };
Escolha escolha2 = {"textoA", "textoB", NULL} ;
Escolha escolha3 = {"textoA", "textoB", NULL };
Escolha escolha4 = {"textoA", "textoB", NULL };

void iniciar_jogo()
{
    escolha1.proxEsc = &escolha2;
    escolha2.proxEsc = &escolha3;
    escolha3.proxEsc = &escolha4;
    escolha4.proxEsc = NULL;

    escolha_atual = 0;
    exibir_escolha(&escolha1);
}

void controle_escolha(Escolha escolha)
{

}

void exibir_resultado()
{

}