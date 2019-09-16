#ifndef FILA_H
#define FILA_H

typedef struct No_fila{
    int pontuacao;
    struct No_fila *prox;
} No_fila;
typedef struct No_fila * pf_no;

typedef struct Fila{
    pf_no ini, fim;
} Fila;
typedef Fila * p_fila;

p_fila criar_fila();

void destruir_lista_fila(pf_no lista);

void destruir_fila(p_fila f);

void enfileira(p_fila f, int pont);

int desenfileira(p_fila f);

#endif
