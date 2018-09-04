//Daniela Palumbo 166301
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct no{
    char nome[10],operacao;
    struct ligacao *ligacoes;
    double valor;
    int marcado;
} No;

typedef struct ligacao{
    struct ligacao *prox;
    No *no;
} Ligacao;

typedef struct grafo{
    int total;
    No **matriz;
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

void visita(No* no,NoLista **l){
    if (no->marcado){
        return;
    }
    no->marcado=1;
    //chama pras ligacoes dele se houver
    Ligacao *ligacoes = no->ligacoes;
    while(ligacoes!=NULL){
        visita(ligacoes->no,l);
        ligacoes = ligacoes->prox;
    }
    //adiciona no no comeco da lista
    NoLista *noLista = novoNoLista(no);
    noLista->prox = *l;
    *l=noLista;
}

NoLista* topologica(Grafo *g){
    int i;
    No *no;
    NoLista *lista = novoNoLista(novoNo("no fake"));
    //confere todos os nos
    for (i = 0; i < g->total; ++i){
        no = g->matriz[i];
        visita(no,&lista);
    }
    return lista;
}

int main()
{
    int totalNos, i, k, j, totalLigacoes;
    double valorNo;
    char nomeNo[10], operacaoNo;
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
        scanf(" %c ",&operacaoNo);
        grafo->matriz[i]->operacao = operacaoNo;
        if(operacaoNo=='E'){
            totalLigacoes = 1;
        } else if (operacaoNo=='S' || operacaoNo=='M'){
            scanf("%d",&totalLigacoes);
        } else if(operacaoNo=='C'){
            totalLigacoes = 0;
            scanf("%lf",&valorNo);
            //cria no valor
            grafo->matriz[i]->valor = valorNo;
        }
        //ler e criar as ligacoes se existirem
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
    //ordenar topologicamente
    NoLista *lista = topologica(grafo);
    //realizar operacoes
    Ligacao *ligacoes;
    while(lista!=NULL){
        ligacoes = lista->no->ligacoes;
        //armazena valor da conta no no ligado
        while(ligacoes!=NULL){
            switch(ligacoes->no->operacao){
                case 'S':
                    ligacoes->no->valor += lista->no->valor;
                    break;
                case 'M':
                    if (ligacoes->no->valor==0){
                        ligacoes->no->valor = lista->no->valor;
                    } else{
                        ligacoes->no->valor = ligacoes->no->valor * lista->no->valor;
                    }
                    break;
                case 'E':
                    ligacoes->no->valor = exp(lista->no->valor);
                    break;
            }
            //anda nas ligacoes
            ligacoes = ligacoes->prox;
        }
        lista = lista->prox;
    }
    //escrever na ordem lida
    for (i = 0; i < totalNos; ++i)
    {
        printf("%s: %.2f\n", grafo->matriz[i]->nome,grafo->matriz[i]->valor);
    }
    limpaGrafo(grafo);
    limpaLista(lista);
    return 0;
}