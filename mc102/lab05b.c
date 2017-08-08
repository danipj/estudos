/*
Daniela Palumbo Jorge
166301

Lab Distancia de Tchonsky
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main()
{   
    int i,j, comum=0, achou, tamanhoA, tamanhoB;
    char palavraA[102], palavraB[102];

    fgets(palavraA,102,stdin);
    fgets(palavraB,102,stdin);

    /* converter as palavras pra minuscula */
    tamanhoA=0;
    while (palavraA[tamanhoA]!='\0')
    {   
        /*'a' minusculo = 97, maiusculas vem antes*/
        if(palavraA[tamanhoA]<97)
            palavraA[tamanhoA] = palavraA[tamanhoA]+32;   
        tamanhoA++;
    }
    
    tamanhoB=0;
    while (palavraB[tamanhoB]!='\0')
    {
        if(palavraB[tamanhoB]<97)
            palavraB[tamanhoB] = palavraB[tamanhoB]+32;
        tamanhoB++;
    }
    
    /*tira o \0 do tamanho da string lida*/
    tamanhoA--;
    tamanhoB--;

    /*conta quando existe o char da A na B*/
    for (i = 0; i < tamanhoA; ++i)
    {   
        achou = FALSE;
        for (j = 0; j < tamanhoB; ++j)
            if(achou != TRUE && palavraA[i]==palavraB[j])
            {
                comum++;
                achou = TRUE;
                /*'remove' da string*/
                palavraB[j]=' ';
            }        
    }
    printf("Distancia de Tchonsky = %d\n", tamanhoA + tamanhoB - 2*comum);
    
    return 0;
}