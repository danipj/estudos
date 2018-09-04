/*Daniela Palumbo 166301*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noarvore
{
    char* value;
    struct noarvore* esq;
    struct noarvore* dir;
} NoArvore;

typedef struct nopilha
{
    NoArvore* noArv;
    struct nopilha* prox;
} NoPilha;

NoArvore* novoNo(char* value, NoArvore* noEsq, NoArvore* noDir){
    NoArvore* no = (NoArvore*) malloc(sizeof (NoArvore));
    char* string = (char*) malloc(100*sizeof(char));
    strcpy(string,value);
    no->value = string;
    no->esq = noEsq;
    no->dir = noDir;
    return no;
}

NoPilha* novoNoPilha(NoArvore* noArv, NoPilha* prox){
    NoPilha* no = (NoPilha*) malloc(sizeof (NoPilha));
    no->noArv = noArv;
    no->prox = prox;
    return no;
}

void empilha(NoPilha** pilha, NoArvore* no){
    /*cria um novo no de pilha usando o no de arvore passado e seta seu proximo
    como o topo da pilha atual. seta o novo no agora criado para ser o novo topo*/
    *pilha = novoNoPilha(no,*pilha);
}

NoArvore* desempilha(NoPilha** pilha){
    /*retorna o valor armazenado no topo da pilha e seta o
    novo topo como o armazenado apos ele*/
    NoArvore* no = (*pilha)->noArv;
    *pilha = (*pilha)->prox;
    return no;
}

void escreveExpressao(NoArvore* raiz){
    if (raiz->esq != NULL && raiz->dir !=NULL)
    {
        printf("(");
    }
    if (raiz->esq != NULL)
    {
        escreveExpressao(raiz->esq);
    }
    printf("%s",raiz->value);
    if (raiz->dir!= NULL)
    {
        escreveExpressao(raiz->dir);
    }

    if (raiz->esq != NULL && raiz->dir !=NULL)
    { //entao eh no de operacao, fechar parenteses
        printf(")");
    }
}

void limpaArvore(NoArvore* raiz){
    if (raiz->esq != NULL)
    {
        limpaArvore(raiz->esq);
    }
    if (raiz->dir!= NULL)
    {
        limpaArvore(raiz->dir);
    }
    free(raiz);
}

void limpaPilha(NoPilha* pilha){
    if(pilha->prox!=NULL)
        limpaPilha(pilha->prox);
    free(pilha);
}

int ehOperador(char* c){
    if (strlen(c)==1){
        if(c[0]=='+')
            return 1;
        if(c[0]=='-')
            return 1;
        if(c[0]=='*')
            return 1;
        if(c[0]=='/')
            return 1;
    }
    return 0;
}

int main()
{
    int total,i;
    char *input= (char*) malloc(11*sizeof(char));
    NoPilha* pilha = NULL;
    NoArvore* raiz;


    while (scanf("%d", &total) != EOF) {
        //montar a arvore
        pilha = novoNoPilha(NULL,NULL);
        for (i = 0; i < total; ++i)
        {
            scanf("%s",input);

            //checa se eh operador
            if (ehOperador(input)){

                //armazena ja com espacos pra imprimir bonito depois
                input[1] = input[0];
                input[0] = input[2] = ' ';
                input[3] = '\0';
                //tem que existir algum numero/expressao empilhado, pega os 2 ultimos, coloca de filho e reempilha
                empilha(&pilha, novoNo(input, desempilha(&pilha), desempilha(&pilha)));
            } else {
                //eh numero, cria folha e coloca na pilha
                empilha(&pilha, novoNo(input,NULL,NULL));
            }
        }
        //no fim, a raiz da arvore eh o unico no na pilha
        raiz = pilha->noArv;
        escreveExpressao(raiz);
        printf("\n");
        limpaPilha(pilha);
        limpaArvore(raiz);
    }
    return 0;
}

