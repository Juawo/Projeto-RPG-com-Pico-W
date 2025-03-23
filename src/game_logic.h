#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdint.h>

typedef struct Escolha
{
    char opcaoA[32];
    char opcaoB[32];;
}
Escolha;

void iniciar_jogo();
void processar_escolha(int opcao);
void exibir_resultado();

#endif