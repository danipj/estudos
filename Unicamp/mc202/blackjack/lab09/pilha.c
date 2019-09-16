#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

p_pilha criar_pilha(){
    p_pilha p;
    p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(p_pilha pilha, char *nova_carta){
    pp_no novo = malloc(sizeof(No_pilha));
    strcpy(novo->carta, nova_carta);
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

char * desempilhar(p_pilha pilha){
    char *carta = malloc(3 * (sizeof(char)));
    pp_no topo = pilha->topo;
    strcpy(carta, topo->carta);
    pilha->topo = pilha->topo->prox;
    free(topo);
    return carta;
}

void destruir_lista(pp_no lista){
    if (lista != NULL){
        destruir_lista(lista->prox);
        free(lista);
    }
}

void destruir_pilha(p_pilha pilha){
    destruir_lista(pilha->topo);
    free(pilha);
}
