#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"
#include "pilha.h"
#include "fila.h"

void pontuar(char *carta, pf_no jogador){
    int valor;
    if (strcmp(carta, "V") || strcmp(carta, "D") || strcmp(carta, "R"))
        valor = 10;
    else if (strcmp(carta, "A")){
        if(jogador->pontuacao > 11)
            jogador->pontuacao++;
        else
            jogador->pontuacao += 11;
    }
    else
        valor = atoi(carta);
    jogador->pontuacao += valor;
    if (jogador->pontuacao > 20)
        stand(jogador);
}

void distribuir(p_pilha baralho, p_fila jogadores){
    pf_no jogador;
    char *carta = malloc(3 * (sizeof(char)));
    for (jogador = jogadores->ini; jogador != NULL; jogador = jogador->prox){
        carta = desempilhar(baralho);
        pontuar(carta, jogador);
    }
}

void hit(p_pilha baralho, pf_no jogador){
    char *carta = malloc(3 * sizeof(char));
    carta = desempilhar(baralho);
    pontuar(carta, jogador);
}

void stand(pf_no jogador){

}

void imprimir(p_fila jogadores){
    pf_no jogador;
    for (jogador = jogadores->ini; jogador != NULL; jogador = jogador->prox)
        printf("%d\n", jogador->pontuacao);
}
