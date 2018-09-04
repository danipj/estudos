//Daniela Palumbo 166301
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no{
    char nome[10];
    struct ligacao *ligacoes;
    int visitado;
} No;

typedef struct ligacao{
    struct ligacao *prox;
    No *no;
} Ligacao;

typedef struct grafo{
    int total;
    No **matriz;
} Grafo;

No* novoNo(char nome[]){
    No *n = (No*) malloc(sizeof(No));
    strcpy(n->nome,nome);
    n->ligacoes = NULL;
    n->visitado = 0;
    return n;
}

Ligacao* novaLigacao(No *no, Ligacao *prox){
    Ligacao *l = (Ligacao*) malloc(sizeof(Ligacao));
    l->prox = prox;
    l->no = no;
    return l;
}

Grafo* novoGrafo(int N){
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->total = N;
    g-> matriz = malloc(N*sizeof(No));
    int i;
    //aloca matriz de nos
    for (i = 0; i < N; ++i)
    {
        g->matriz[i]=NULL;
    }
    return g;
}

int detectaCiclo(No *no){
    int ciclo = 0;
    Ligacao *l;
    //se ja passou por esse no, existe ciclo
    if (no->visitado){
        return 1;
    }
    l=no->ligacoes;
    //marca como visitado
    no->visitado = 1;
    while(l!=NULL){
        if(detectaCiclo(l->no))
            ciclo = 1;
        l = l->prox;
    }
    //desmarca
    no->visitado = 0;

    return ciclo;
}

void limpa(Grafo *g){
    int i;
    for (i = 0; i < g->total; ++i)
    {
        free(g->matriz[i]);
    }
    free(g);
}

int main()
{
    int totalNos,totalLigacoes,i,j,k;
    char nomeNo[10];
    Grafo *grafo;

    scanf("%d",&totalNos);
    grafo = novoGrafo(totalNos);

    for (i = 0; i < totalNos; ++i)
    {
        scanf("%s",nomeNo);
        //coloca na matriz de grafo
        grafo->matriz[i] = novoNo(nomeNo);
    }
    for (i = 0; i < totalNos; ++i)
    {
        scanf("%d",&totalLigacoes);
        for (j = 0; j < totalLigacoes; ++j)
        {
            scanf("%s",nomeNo);
            //cria dependencia
            for (k = 0; k < totalNos; ++k)
            {
                //encontra o grafo
                if (strcmp(nomeNo,grafo->matriz[k]->nome)==0){
                    //coloca nas ligacoes se ja existirem
                    if (grafo->matriz[k]->ligacoes!=NULL){
                        grafo->matriz[k]->ligacoes->prox = novaLigacao(grafo->matriz[i],grafo->matriz[k]->ligacoes->prox);
                    } else {
                        //cria ligacoes
                        grafo->matriz[k]->ligacoes = novaLigacao(grafo->matriz[i],NULL);
                    }
                }
            }
        }
    }
    //verifica se existe ciclo
    int ciclo =0;
    for (i = 0; i < totalNos; ++i)
    {
        if (detectaCiclo(grafo->matriz[i])){
            ciclo++;
        }
    }

    if (ciclo){
        printf("Cycle detected\n");
    } else {
        printf("No cycles\n");
    }

    return 0;
}