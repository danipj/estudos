#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "jogador.h"

int main(){
    int n_carta, n_jogador, i;
    char carta[3], comando[3] = "\0";
    p_pilha baralho;
    p_fila jogadores;
    pf_no jogador;
    scanf("%d %d", &n_carta, &n_jogador);

    baralho = criar_pilha();
    jogadores = criar_fila();

    for (i = 0; i < n_carta; i++){
        scanf("%s", carta);
        empilhar(baralho, carta);
    }

    for (i = 0; i < n_jogador; i++)
        enfileira(jogadores, 0);

    for(i = 0; i < 2; i++)
        distribuir(baralho, jogadores);

    jogador = jogadores->ini;
    while(!strcmp(comando, "#")){
        if (jogador == NULL)
            jogador = jogadores->ini;
        if (strcmp(comando, "H")){
            hit(baralho, jogador);
            jogador = jogador->prox;
        }
        else if(strcmp(comando, "S")){
            stand(jogador);
            jogador = jogador->prox;
        }
        else{
            empilhar(baralho, comando);
        }
    }

    imprimir(jogadores);
    destruir_pilha(baralho);
    destruir_fila(jogadores);

    return 0;
}
