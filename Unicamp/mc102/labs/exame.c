//Daniela Palumbo 166301
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct no{
    char nome[10],operacao;
    struct ligacao *ligacoes;
    //double valor;
    //int marcado;
    struct no *prox;
} No;

typedef struct ligacao{
    struct ligacao *prox;
    double dist;
    No *no;
} Ligacao;

//grafo nao sera usado?
typedef struct grafo{
    int total;
    //No **matriz;
} Grafo;

typedef struct nolista{
    No *no;
    struct nolista *prox;
} NoLista;

No* novoNo(char nome[]){
    No *n = (No*) malloc(sizeof(No));
    strcpy(n->nome,nome);
    n->ligacoes = NULL;
    n->valor = 0;
    n->operacao = '-';
    n->marcado = 0;
    return n;
}

Ligacao* novaLigacao(No *no, Ligacao *prox, double dist){
    Ligacao *l = (Ligacao*) malloc(sizeof(Ligacao));
    l->prox = prox;
    l->no = no;
    l->dist=dist;
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

NoLista* novoNoLista(No* n){
    NoLista *no = (NoLista*) malloc(sizeof(NoLista));
    no->no = (No*) malloc(sizeof(No));
    no->no = n;
    no->prox = NULL;
    return no;
}

void limpaGrafo(Grafo *g){
    int i;
    for (i = 0; i < g->total; ++i)
    {
        free(g->matriz[i]);
    }
    free(g);
}

void limpaLista(NoLista *l){
    if(l!=NULL){
        limpaLista(l->prox);
    }
    free(l);
}

double djikstra(No *n, No *origem){
    int i, dist[],prev[];
    No **Q;
    while(n->prox != NULL){
        dist[n->id]= MAX_INT;
        prev[n->id]= -1;
        Q[i] = n;
        i++;
    }   
    dist[origem->id] = 0;
    while(Q[i]!=NULL){

    }
}

double coeficiente(){

}

int main()
{
    char comando,nome[20];
    double distancia;
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
                scanf("%lf %d %d",&distancia,&id,&idAresta);
                criaAresta(grafo,id,idAresta,distancia);
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
            case 'M':
            //djikstra
            scanf("%d %d",&id,&idAresta);
            printf("%.1f\n", djikstra());
                break;
            case 'C':
            //coef
            scanf("%d",&id);
            printf("%.2f\n", coeficiente());
                break;
        }
    }
    //free
    return 0;
}