/*Daniela Palumbo 166301*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct op
{
    int valor;
    int inserir;
    char operacao;
}Op;

typedef struct nopilha
{
    int valor;
    struct nopilha* prox;
} NoPilha;

NoPilha* novoNo(int value){
    NoPilha* no = (NoPilha*) malloc(sizeof (NoPilha));
    no->valor = value;
    no->prox = NULL;
    return no;
}

NoPilha* push(NoPilha* no, NoPilha* pilha){
    //empurra o topo da pilha pra baixo
    no->prox = pilha;
    //pilha = no;
    return no;
}

NoPilha* soma(NoPilha* pilha){
    int A, B;
    NoPilha* topo;
    //armazena valores
    A = pilha->valor;
    B = pilha->prox->valor;
    //libera o topo da pilha
    topo = pilha->prox;
    free(pilha);
    //armazena a soma no topo
    pilha = topo;
    pilha->valor = A+B;
    return pilha;
}

NoPilha* subt(NoPilha* pilha){
    int A, B;
    NoPilha* topo;
    //armazena valores
    A = pilha->prox->valor;
    B = pilha->valor;
    //libera o topo da pilha
    topo = pilha->prox;
    free(pilha);
    //armazena a subtracao no topo
    pilha = topo;
    pilha->valor = abs(B-A);
    return pilha;
}

NoPilha* mult(NoPilha* pilha){
    int A, B;
    NoPilha* topo;
    //armazena valores
    A = pilha->prox->valor;
    B = pilha->valor;
    //libera o topo da pilha
    topo = pilha->prox;
    free(pilha);
    //armazena a multiplicacao no topo
    pilha = topo;
    pilha->valor = A*B;
    return pilha;
}

NoPilha* divi(NoPilha* pilha){
    int A, B;
    NoPilha* topo;
    //armazena valores
    A = pilha->prox->valor;
    B = pilha->valor;
    //libera o topo da pilha
    topo = pilha->prox;
    free(pilha);
    //armazena a divisao no topo
    pilha = topo;
    pilha->valor = abs(A/B);
    return pilha;
}

NoPilha* equal(NoPilha* pilha){
    int A, B,valor;
    NoPilha* topo;
    //armazena valores
    A = pilha->prox->valor;
    B = pilha->valor;
    //libera o topo da pilha
    topo = pilha->prox;
    free(pilha);
    //se forem valores iguais armazena 1, se nao, 0
    pilha = topo;
    if (A==B)
        valor = 1;
    else
        valor = 0;
    pilha->valor = valor;
    return pilha;
}

NoPilha* swap(NoPilha* pilha){
    int A, B;
    //armazena valores
    A = pilha->prox->valor;
    B = pilha->valor;
    //inverte
    pilha->valor = A;
    pilha->prox->valor = B;
    return pilha;
}

NoPilha* dup(NoPilha* pilha){
    //cria no igual ao topo
    //coloca na pilha
    return push(novoNo(pilha->valor),pilha);
}

NoPilha* cond(NoPilha* pilha){
    int A,B,C;
    NoPilha* topo;
    A = pilha->prox->prox->valor;
    B = pilha->prox->valor;
    C = pilha->valor;
    topo = pilha->prox->prox;
    free(pilha->prox);
    free(pilha);
    if (A!=0)
    {
        //A verdadeiro, mantem B e tira C
        topo->valor = B;
    } else {
        //A falso, tira B e mantem C
        topo->valor = C;
    }
    return topo;
}

NoPilha* print(NoPilha* pilha){
    //imprime e libera o valor do topo
    printf("%d\n", pilha->valor);
    return pilha->prox;
}

int main()
{
    int total,i;
    char* string;
    Op* operacoes;
    while (scanf("%d", &total) != EOF) {

        string = (char*) malloc(255 * sizeof(char));
        operacoes = (Op*) malloc(total * sizeof(Op));
        for (i = 0; i < total; i++) {
            scanf("%s", string);
            //verifica se eh numero ou caractere
            if (isdigit(string[0])) {
                //armazena numero a ser inserido
                operacoes[i].valor = atoi(string);
                operacoes[i].inserir = TRUE;
            } else {
                //armazena como operacao
                operacoes[i].operacao = string[0];
                operacoes[i].inserir = FALSE;
            }
        }

        NoPilha* pilha = NULL;
        for (i = 0; i < total; ++i)
        {
            if (operacoes[i].inserir==TRUE){
                //insere na pilha
                pilha= push(novoNo(operacoes[i].valor),pilha);
            }else{
                switch(operacoes[i].operacao){
                    case '+':
                        pilha=soma(pilha);
                        break;
                    case '-':
                        pilha=subt(pilha);
                        break;
                    case '*':
                        pilha=mult(pilha);
                        break;
                    case '/':
                        pilha=divi(pilha);
                        break;
                    case 'P':
                        pilha=print(pilha);
                        break;
                    case 'I':
                        pilha=cond(pilha);
                        break;
                    case '=':
                        pilha=equal(pilha);
                        break;
                    case 'S':
                        pilha=swap(pilha);
                        break;
                    case 'D':
                        pilha=dup(pilha);
                        break;
                    case 'J':
                    //troca o indice para o valor desempilhado
                        i = pilha->valor-1;
                        pilha = pilha->prox;
                        //free(pilha);
                        //pilha = topo;
                        break;
                }
            }
        }

        free(operacoes);
        free(string);
    }
    return 0;
}
