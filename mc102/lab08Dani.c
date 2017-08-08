/*
Daniela Palumbo Jorge
166301
Lab BigCalc
*/
#include <stdio.h>


/* realiza a adicao n1+n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
    /*pega o ultimo de cada vetor e soma. caso passe de 10, faz mod 10 e armazena no primeiro do result, 
    fazendo a proxima soma ja comecar com div 10*/ 
    int tamResult = 0, i;
    /*percorre os vetores até um deles acabar*/
    while(tamResult!=tam_n1 || tamResult != tam_n2){
        /*aloca result*/
        tamResult++;
        if(result!=NULL)
            free(result);
        nroX = (int*) malloc(tamResult);
        /*desloca os elementos de result pra direita*/
        for (i = tamResult-1; i > 0; --i)
        {
            result[i]=result[i-1];
        }
        if(dezena>0)
            soma = dezena;
        /*limpa dezena*/
        dezena = 0;
    
    }
}

/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em result */
void subtract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    
}

/* realiza a multiplicacao n1*n2, armazendo o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i;
    for (i = 0; i < n1; ++i)
    {
        add(result, tamResult, n2, tam_n2, result);
    }   
}

int main()
{   
    int *nroX, *nroY, *result, tamX, tamY;
    char operacao;

    /*ler os valores*/
    scanf("%d %d %c", &tamX, &tamY, &operacao);
    
    /*alocar o vetor*/ 
    nroX = (int*) malloc(tamX);
    for (i = 0; i < tamX; ++i)
    {
        scanf("%c",&nroX[i]);
    }
    nroY = (int*) malloc(tamY);
    for (i = 0; i < tamY; ++i)
    {
        scanf("%c",&nroY[i]);
    }

    switch(operacao){
        case 'A':
            add(nroX, tamX, nroY, tamY,result);
            break;
        case 'S':
            subtract(nroX, tamX, nroY, tamY,result);
            break;
        case 'M':
            add(nroX, tamX, nroY, tamY,result);
            break;
    }
    return 0;
}