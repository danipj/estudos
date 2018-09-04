/*Daniela Palumbo 166301*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nofila
{
    float valor;
    struct nofila* prox;
} NoFila;

NoFila* novoNo(float value){
    NoFila* no = (NoFila*) malloc(sizeof (NoFila));
    no->valor = value;
    no->prox = NULL;
    return no;
}

float front(NoFila* no){
    return no->valor;
}

void push(NoFila* no, NoFila* fila){
    NoFila* noAtual = fila;
    while (noAtual->prox!=NULL)
        noAtual=noAtual->prox;
    //saiu entao ta no fim da fila
    noAtual->prox = no;
}

void pop(NoFila* fila){
    //mantendo o no inicio simbolico:
    fila->prox = fila->prox->prox;
}

int main()
{
    int K, N,i,j;
    float valor,soma;

    while (scanf("%d",&K)!=EOF){

        scanf("%d",&N);

        if (K >= 0 && N == 0) {
            //sem elementos
            printf("\n");
        }
        else if (K == 0 && N >= 0){
            //se janela for zero, printar zeros
            for (i = 0; i < N-1; ++i)
            {
                printf("0.0 ");
            }
            printf("0.0\n");
        }
        else{

            //no simbolico
            NoFila* fila = novoNo(-1);

            for (i = 0; i < N; ++i)
            {
                scanf("%f",&valor);
                push(novoNo(valor),fila);
            }

            // fim da leitura dos dados, escrever media
            //comeco em 1 pois eh o divisor de cada media
            for (i = 1; i < N; ++i)
            {
                soma=0;
                NoFila* atual=fila->prox;
                for (j = 0; j < i; ++j)
                {
                    soma+=front(atual);
                    atual = atual->prox;
                }
                //apos K valores, toda divisao eh feita por K
                if(i>K)
                    printf("%.1f ", soma/(double)K);
                else
                    printf("%.1f ", soma/(double)i);
            }

            //escreve o ultimo elemento com quebra de linha
            soma=0;
            NoFila* atual=fila->prox;
            for (j = 0; j < i; ++j)
            {
                soma+=front(atual);
                atual = atual->prox;
            }
            printf("%.1f\n", soma/(double)K);
        }
    }
    return 0;
}