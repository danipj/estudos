#ifndef PILHA_H
#define PILHA_H

typedef struct No_pilha{
    char carta[3];
    struct No_pilha *prox;
} No_pilha;
typedef struct No_pilha * pp_no;

typedef struct Pilha{
    pp_no topo;
} Pilha;
typedef struct Pilha * p_pilha;

p_pilha criar_pilha();

void empilhar(p_pilha pilha, char *nova_carta);

char * desempilhar(p_pilha pilha);

void destruir_lista(pp_no lista);

void destruir_pilha(p_pilha pilha);

#endif
