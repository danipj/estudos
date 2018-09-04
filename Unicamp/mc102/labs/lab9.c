#include <stdio.h>
#include <stdlib.h>

int hash(char * str, int hash_seed, int M)
{
    unsigned long hash = hash_seed;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return (int)(hash % M);
}

int fast_rand(unsigned int * seed)
{
    *seed = (214013*(*seed)+2531011);
    return ((*seed)>>16)&0x7FFF;
}


int main()
{
    int bitsConjunto,funcoesHash;
    char operacao, *termo;

    scanf("%d %d",&bitsConjunto,&funcoesHash);

    int vetor[bitsConjunto];
    termo = (char*) malloc(10*sizeof(char));

    while(scanf("%c ",&operacao)!=EOF){
        scanf("%s",&termo);
        switch(operacao){
            case 'I':
                //inserir termo no hash
                break;
            case 'V':
                //verificar se esta no hash
                break;
        }
    }
    unsigned int seed = 0
hash_seed_1 = fast_rand(&seed);
hash_seed_2 = fast_rand(&seed);
.
.
.
hash_seed_K = fast_rand(&seed);


    return 0;
}