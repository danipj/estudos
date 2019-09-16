#ifndef JOGADOR_H
#define JOGADOR_H
#include "fila.h"
#include "pilha.h"

void pontuar(char *carta, pf_no jogador);

void distribuir(p_pilha baralho, p_fila jogadores);

void hit(p_pilha baralho, pf_no jogador);

void stand(pf_no jogador);

void imprimir(p_fila jogadores);

#endif
