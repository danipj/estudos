/*
Daniela Palumbo Jorge
166301

Lab O Lobo de Wall Street
*/

#include <stdio.h>

int main()
{	int nroDias, capitalInicial, maiorLucro = 0, acoes1, acoes2, capitalCompra1, capitalCompra2, capitalVenda1, capitalVenda2, i, j, k , l;

	scanf("%d %d",&nroDias,&capitalInicial);

	int valorAcao[nroDias];

	for (i = 0; i < nroDias; ++i)
	{
		scanf("%d", &valorAcao[i]);
	}

	for (i = 0; i < nroDias; ++i)
	{ /*compra tudo o que puder de acoes*/
		acoes1 = capitalInicial / valorAcao[i];
		capitalCompra1 = capitalInicial - acoes1 * valorAcao[i];
		for (j = i+1; j < nroDias; ++j)
		{ /*tenta vender todos os dias*/
			capitalVenda1 = capitalCompra1 + acoes1 * valorAcao[j];
			for (k = j+1; k < nroDias; ++k)
			{ /*faz segunda compra*/
				acoes2 = capitalVenda1 / valorAcao[k];
				capitalCompra2 = capitalVenda1 - acoes2 * valorAcao[k];
				for (l = k+1; l < nroDias; ++l)
				{ /*vende tudo*/
					capitalVenda2 = capitalCompra2 + acoes2 * valorAcao[l];
					if (capitalVenda2 > maiorLucro){
						maiorLucro = capitalVenda2;
					}
				}
			}
		}
	}

	if (maiorLucro > capitalInicial)
		printf("Capital final = R$%d\n", maiorLucro);
	else
		printf("Melhor nao investir agora, cara!\n");


	return 0;
}
