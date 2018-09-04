//Daniela Palumbo 166301
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct no{
    char nome[20];
    int id,totalVizinhos,*vizinhos;
    struct no *prox;
} No;


No* novoNo(int id,char nome[]){
    No *n = (No*) malloc(sizeof(No));
    strcpy(n->nome,nome);
    n->vizinhos = NULL;
    n->prox = NULL;
    n->id = id;
    n->totalVizinhos=0;
    return n;
}


double pageRank(No *g,int total){
    //cria vetor de vizinhos
    int vizinhos[total],rank[total],i=0;
    while(g != NULL){
        rank[i]=1;
        vizinhos[i] = g->totalVizinhos;
        i++;
    }
    double mean = 1;
    return mean;
}

void criaAresta(No *grafo, int id, int idAresta){
    No *aux,*aresta;
    //achar os nos de mesmo id
    aux = grafo;
    while(aux->prox!=NULL && aux->id!=id){
        aux = aux->prox;
    }
    aresta = grafo;
     while(aresta->prox!=NULL && aresta->id!=idAresta){
        aresta = aresta->prox;
    }
    aux->totalVizinhos++;
    aresta->totalVizinhos++;
    aux->vizinhos = (int*)malloc(aux->totalVizinhos*sizeof(int));
    aresta->vizinhos = (int*)malloc(aresta->totalVizinhos*sizeof(int));
    //adicionar como vizinho
    aux->vizinhos[aux->totalVizinhos-1]=aresta->id;
    aresta->vizinhos[aresta->totalVizinhos-1]=aux->id;
}

int main()
{
    char comando,nome[20];
    int id,idAresta,totalNos=0,i,j,k;
    No *grafo=NULL,*aux,*no;

    while(scanf(" %c",&comando)!=EOF){
        switch(comando){
            case 'I':
                totalNos++;
                scanf("%d %s",&id,nome);
                if (grafo==NULL){
                    grafo = novoNo(id,nome);
                } else {
                    aux = grafo;
                    while(aux->prox!=NULL){
                        aux = aux->prox;
                    }
                    aux->prox = novoNo(id,nome);
                }
                break;
            case 'A':
                scanf("%d %d",&id,&idAresta);
                criaAresta(grafo,id,idAresta);
                break;
            case 'R':
                scanf("%d",&id);
                break;
            case 'D':
                scanf("%d %d",&id,&idAresta);
                break;
            case 'S':
                aux = grafo;
                for (i = 0; i < totalNos; ++i)
                {
                    printf("%s:", aux->nome);
                    //printar vizinhos
                    for (j = 0; j < aux->totalVizinhos; ++j)
                    {
                        no=grafo;
                        for (k = 0; k < totalNos; ++k)
                        {
                            if (no->id==aux->vizinhos[j]){
                                printf(" %s", no->nome);
                            }
                            no=no->prox;
                        }
                    }
                    printf("\n");
                    aux = aux->prox;
                }
                break;
            case 'P':
            //pagerank
                break;
        }
    }
    //free
    return 0;
}