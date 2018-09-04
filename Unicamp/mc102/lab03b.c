/*
Daniela Palumbo Jorge
RA 166301

Lab O Enigma dos Guardioes Quanticos
*/

#include <stdio.h>

int main()
{	int guardioes, guardiao, i, nroSinceros=0, avanco, opcoes, qtd, qtd2, sinceros;
	scanf("%d", &guardioes);
	printf("TOTAL GUARDIOES = %d\n", guardioes);
	/*cria uma matriz de acordo com o numero de guardioes pra armazenar o intervalo dado*/
	int intervalos[guardioes][2];

	/*le o intervalo*/
	for (i = 0; i < guardioes; ++i)
	{	printf("lendo intervalo guard %d\n", i+1);
		scanf("%d %d", &intervalos[guardioes][0], &intervalos[guardioes][1]);
		printf("comeco %d\n", intervalos[guardiao][1]);
		printf("fim %d\n", intervalos[guardiao][1]);
	}

	/*o numero de guardioes sinceros tem que coincidir com as posicoes em que foi dito que existem guard sinceros*/
	for (guardiao = 0; guardiao < guardioes; ++guardiao)
	{ /*verifica se esse guardiao e sincero*/
		printf("vendo se o guard %d e sincero\n", guardiao+1);

		/*qtd de opcoes desse guardiao*/
		qtd = intervalos[guardiao][1]-intervalos[guardiao][0];
		printf("opcoes do guard %d = %d\n", guardiao+1, qtd);
		
		for (opcoes = 0;opcoes <= qtd;opcoes++)
		{  /*verifica se existe nro - 1 guardiao que tambem falou aquilo*/

			/*percorrer o intervalo que ele disse*/
			sinceros = intervalos[guardiao][0] + opcoes;
			printf("verificando se existem %d guardioes sinceros\n", sinceros);
			
			/*percorre os outros guardioes*/
			for (i=0;i<guardioes;i++)
				if (i != guardiao)
				{	printf("vendo se o guard %d bate com o %d\n", i+1, guardiao+1);
					/*percorre o intervalo dos outros guardioes*/
					qtd2 = intervalos[i][1]-intervalos[i][0];
					printf("guard %d tem %d opcoes\n", i+1, qtd2);
					for (avanco = 0; avanco <=qtd2; avanco++)
						/*se o nro dito pelo guardiao principal estiver no intervalo do
						guardiao avaliado, ele pode ser sincero. diminui 1 do total de verificacoes
						de guardioes sinceros que ainda precisam ser feitas*/
						if(intervalos[i][0]+avanco == intervalos[guardiao][0]+opcoes)
							sinceros--;
				}
			if (sinceros==0)
				/*esse guard e sincero*/
				nroSinceros++;
		}
	}

	return 0;
}	