/*
Eu calculei o numero de vendas de produtos total no dia
Fernanda Wohlers Picerni
167474
*/

#include <stdio.h>

int main()
{
	int nroVendas, qtdProd,i,j;
	float preco, totalDaVenda, totalDoDia;

	totalDoDia=0;

	/*ler qtd de vendas*/
	scanf("%d",&nroVendas);
	
	/*ler qtd de produtos vendidos pra essa venda*/
	for (i = 0; i < nroVendas; i++)
	{
		totalDaVenda=0;
		
		scanf("%d",&qtdProd);
		
		/*ler preco de cada produto da venda*/
		for (j = 0; j < qtdProd; ++j)
		{
			scanf("%f",&preco);
			totalDaVenda += preco; 
		}

		totalDoDia += totalDaVenda;
		printf("Venda %d - Total: R$ %.2f.\n", i+1, totalDaVenda);
	}

	printf("* Saldo do dia: R$ %.2f.\n", totalDoDia);
	return 0;
}