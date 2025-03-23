#ifndef DISPLAY_H
#define DISPLAY_H

#include <src/game_logic.h>

void display_init();
void exibir_escolha(Escolha *escolha);
void exibir_mensagem(char texto[32]);
void limpar_display();

#endif