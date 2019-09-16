#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"
#include "pilha.h"
#include "fila.h"

void pontuar(char *carta, pf_no jogador){
    int valor;
    if (strcmp(carta, "V")==0 || strcmp(carta, "D")==0 || strcmp(carta, "R")==0){
        valor = 10;
    }
    else if (strcmp(carta, "A")==0){
        valor=11;
        jogador->as++;
    }
    else{
        valor = atoi(carta);
    }

    jogador->pontuacao += valor;
    
    if(jogador->pontuacao==21){
        if(jogador->stand==0){
            stand(jogador);
        } 
    } else{
    if (jogador->pontuacao > 20){

            if(jogador->as>0){
                jogador->as--;
                jogador->pontuacao-=10;
            } else {
                stand(jogador);
            }
        }
    }
}

void distribuir(p_pilha baralho, p_fila jogadores){
    pf_no jogador;
    for (jogador = jogadores->ini; jogador != NULL; jogador = jogador->prox){
        hit(baralho, jogador);
    }
}

void hit(p_pilha baralho, pf_no jogador){
    char *carta = malloc(3 * sizeof(char));
    carta = desempilhar(baralho);
    pontuar(carta, jogador);
}

void stand(pf_no jogador){
    jogador->stand = 1;
}

void imprimir(p_fila jogadores){
    pf_no jogador;
    for (jogador = jogadores->ini; jogador != NULL; jogador = jogador->prox)
        printf("%d\n", jogador->pontuacao);
}
