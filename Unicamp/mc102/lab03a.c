/*
Daniela Palumbo Jorge
RA 166301

Lab Admiravel Mundo Novo
*/

#include <stdio.h>

int main()
{	int lotes, castas, totalIndiv = 0, nascAtual, i, charAtual, ler;
	char loteAtual[256], charLido, lixo;

	scanf("%d %d", &lotes, &castas);
	scanf("%c",&lixo);

	/*cria vetor do tamanho das castas que foram lidas para armazenar os nascimentos de cada casta*/
	int nascimentos[castas];
	for (i = 0; i < castas; ++i)
	{
		/* inicializa o vetor com zero */
		nascimentos[i] = 0;
	}

	/* le de acordo com o numero de lotes */
	for (i = 0; i < lotes; ++i)
	{  
	    /*ler o lote char por char*/
		charAtual = 0;
		/* ler = true*/
		ler = 1;
		while (ler == 1)
		{
			scanf("%c", &charLido);
			/*para de ler (= false) quando achar o final da linha
				em ascii \n = 10 */
			if (charLido == 10)
				ler = 0;
			else
				loteAtual[charAtual] = charLido;
			charAtual++;
		}
	
		/* cria um indice pro vetor */
		nascAtual = 0;

		/*quebra o lote por individuo como um vetor e o percorre*/
		while (nascAtual<charAtual-1)
		{
			/*incrementa a posição do vetor da casta lida 
					tabela ascii: 
					1 = 49, 49-49 = 0*/
			nascimentos[loteAtual[nascAtual]-49]++;
			/*incrementa o total de individuos lidos*/
			totalIndiv++;
			/*avanca o vetor*/
			nascAtual++;
		}
	}
                printf("Total: %d individuos\n", totalIndiv);
                for(i=0;i<castas;i++)
                        printf("Total da casta %d: %d\n", i+1, nascimentos[i]);
		for(i=0;i<castas;i++)
			printf("Percentual da casta %d: %.2f\n",i+1, 100*nascimentos[i]/(double)totalIndiv);
	return 0;
}
