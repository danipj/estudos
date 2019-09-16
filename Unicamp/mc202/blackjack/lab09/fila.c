#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

p_fila criar_fila(){
    p_fila f;
    f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void destruir_lista_fila(pf_no lista){
    if (lista != NULL){
        destruir_lista_fila(lista->prox);
        free(lista);
    }
}

void destruir_fila(p_fila f){
    destruir_lista_fila(f->ini);
    free(f);
}

void enfileira(p_fila f, int pont){
    pf_no novo;
    novo = malloc(sizeof(No_fila));
    novo->pontuacao = pont;
    novo->stand = 0;
    novo->as = 0;
    novo->prox = NULL;
    if (f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}

int desenfileira(p_fila f){
    pf_no primeiro = f->ini;
    int pont = primeiro->pontuacao;
    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(primeiro);
    return pont;
}
