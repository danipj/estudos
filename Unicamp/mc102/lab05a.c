/*
Daniela Palumbo Jorge
166301

Lab Necronomicon
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main()
{ 
    int qtsPalavras, fim, i, j, p, s, x;
    char primeira[20], segunda[20], c = ' ', lixo;
    
    scanf("%d",&qtsPalavras);

    /*cria matriz pra armazenar os Sim e Nao*/
    char resposta[qtsPalavras][3];
    
    /*ignora o enter*/
    scanf("%c",&lixo);
    
    for (i = 0; i < qtsPalavras; ++i)
    {   
        /*inicializa as palavras em branco*/
        for (x = 0; x < 20; ++x)
        {
            primeira[x] =' ';
            segunda[x] = ' ';
        }

        fim = FALSE;

        /*le primeira palavra*/
        for (p = 0; p < 20; ++p)
        {
            if (fim == FALSE)
                scanf("%c",&c);
            /*espaco = final da palavra*/
            if (c==' ')
                fim = TRUE;
            if (fim == FALSE)
                primeira[p] = c;    
        }

        fim = FALSE;
        
        /*le segunda palavra*/
        for (s = 0; s < 20; ++s)
        {
            if (fim == FALSE)
                scanf("%c",&c);
            /*quebra linha = final da palavra*/
            if (c=='\n')
                fim = TRUE;
            if (fim == FALSE)
                segunda[s] = c;         
        }

        /*comeco da verificacao da subsequencia*/
        p = 0;
        s = 0;
        /*enquanto nao chegar ao fim das palavras*/
         while(p<20 && s<20 && primeira[p]!=' ' && segunda[s]!=' ')
         { 
            /*verifica se essa letra existe na segunda palavra*/
            if(primeira[p]==segunda[s])
                /*se existir, anda com a letra sendo procurada*/
                p++;
            else
                /*se nao existir, continua procurando nessa palavra*/
                s++;
         }

         /*subsequencia se a primeira palavra tiver chegado ao fim*/
         if (p==20 || primeira[p]==' '){
            resposta[i][0] = 'S';
            resposta[i][1] = 'i';
            resposta[i][2] = 'm';
         } else {
            resposta[i][0] = 'N';
            resposta[i][1] = 'a';
            resposta[i][2] = 'o';
         }
    }

    /*escreve os resultados*/
    for (i = 0; i < qtsPalavras; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            printf("%c", resposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}