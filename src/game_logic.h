#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdint.h>

typedef struct Escolha
{
    char opcaoA[32];
    char opcaoB[32];
    struct Escolha *proxEsc;
}
Escolha;

void iniciar_jogo();
void controle_escolha(Escolha Escolha);
void reiniciar_jogo();

#endif