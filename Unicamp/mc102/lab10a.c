/*
Daniela Palumbo Jorge
166301

Lab Tag Cloud
*/

#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main()
{
	int i, j,k, iMaior, maior, fim, maxDistintas, minOcorrencias, tamMinimo, tamMaximo,qts,ocorrencias[1000],nova,tamPalavra,prox;
	char palavra[100000], palavras[1000000][100];
	
	scanf("%d %d %d %d", &maxDistintas, &minOcorrencias, &tamMinimo, &tamMaximo);
	getchar();

	fim = FALSE;
	qts = 0;
	while(fim == FALSE)
	{
		scanf("%[^ \n]s",palavra);
		getchar();
		if(palavra[0]!='*'){
			/*conta tamanho da palavra*/
			for (tamPalavra = 0; palavra[tamPalavra] != '\0'; ++tamPalavra);

			if (tamPalavra>=tamMinimo){
				nova = TRUE;
				/*ver se palavra ja apareceu antes*/
				for (i = 0; i < qts && nova == TRUE; ++i)
				{
					j = 0;
					prox = FALSE;
					while (j<tamPalavra && palavras[i][j]!='\0' && prox == FALSE)
					{
						if (palavras[i][j]==palavra[j]){
							j++;
						} else {
							prox = TRUE;
						}
					}
					/*se sair do while e prox for false, chegou ao final da palavra e ela era igual. somar ocorrencia e sair do for*/
					if (prox == FALSE){
						printf("ocorrencia %s\n", palavra);
						ocorrencias[i]++;
						nova = FALSE;
					}
				}
				/*se nao apareceu, adiciona*/
				if(nova == TRUE){
					printf("nova %s\n",palavra);
					for (i = 0; i<=tamPalavra; ++i)
					{
						palavras[qts][i] = palavra[i];
					}
					qts++;
					ocorrencias[qts]=1;
				}
			}
		} else {
			fim = TRUE;
		}
	}	
	/*escrever resultado em ordem de ocorrencia (ou lexicografica) ate as que tenham pelo menos minOcorrencias*/
	for (i = 0; i < qts; ++i)
	{
		maior = 0;
		iMaior = 0;
		for (j = 0; j < qts; ++j)
		{
			if (ocorrencias[j] > maior){
				maior = ocorrencias[j];
				iMaior = j;
			} /*else if (ocorrencias[j] == maior){
				/*percorre palavra
				k = 0;
				while(palavras[j][k]!='\0' && palavras[iMaior][k]!='\0' && k >= 0)
				{
					if (palavras[j][k]>palavras[iMaior][k]){
						maior = ocorrencias[j];
						iMaior = j;
						k = -1;
					} else if (palavras[j][k]==palavras[iMaior][k]){
						k++;
					}
					 else
					 	k = -1;
				}
			}*/
		}
		printf("%s %d\n",palavras[iMaior], ocorrencias[iMaior]);
		ocorrencias[iMaior] = -1;
	}
	
	return 0;
}