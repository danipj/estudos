#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct entradadicionario
{
    char* palavraIng;
    char* palavraPt;
    struct entradadicionario* prox;
}EntradaDicionario;

EntradaDicionario* novaEntrada(char* ing, char* pt){
    EntradaDicionario* noDic = (EntradaDicionario*) malloc(sizeof(EntradaDicionario));
    noDic->palavraIng = ing;
    noDic->palavraPt = pt;
    noDic->prox = NULL;
    return noDic;
}

int numero(char letra){
    //retorna o numero de cada letra do alfabeto
    //a|A = 0, b|B = 1...
    if(letra < 'a')
        //maiuscula
        return letra - 'A';
    else
        return letra - 'a';
}

//funcao de hash, retorna qual pg do dicionario tem a palavra
int pagDic(char* palavra){
    int total = 0;
    int i;
    for (i = 0; palavra[i]!='\0'; ++i)
    {
        total += numero(palavra[i]) * pow(26,i);
    }
    return total % 1000;
}

int main(int argc, char const *argv[])
{
    int i,total,j;
    char pPt[100], pIng[100], string[800],entrada[300];
    EntradaDicionario* dicionario[1000];
    FILE *teclado;

    teclado = fopen(argv[1],"r");
    fscanf(teclado,"%d",&total);

    for (i = 0; i < total; ++i)
    {
        //ler linha inteira
        fgets(entrada,100,stdin);

        for (j = 0; entrada[j]!='='; ++j)
        {
            //palavra ingles termina na seta
            pIng[j] = entrada[j];

        }
        //fim da string
        pIng[j-1] = '\0';
	printf("palavra ing %s", pIng);
        for (j=j+3; entrada[j]!='\n'; ++i)
        {
            //pula caracteres ' => ' e comeca na outra palavra
            pPt[j]=entrada[j];
        }
        pPt[j] = '\0';
	printf("palavra pt %s", pPt);
        //armazenar na tabela dicionario a nova entrada
        int pg = pagDic(pIng);
        if (dicionario[pg] == NULL)
            //se pagina for vazia, preenche
            dicionario[pg] = novaEntrada(pIng,pPt);
        else
            //se ja tiver palavra, encadeia
            dicionario[pg]->prox = novaEntrada(pIng,pPt);
    }

    //le frases pra traducao
    while(fgets(string, 800, stdin)){
        printf("%s\n", string);
    }

    return 0;
}
