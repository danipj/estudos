#include <stdio.h>

typedef struct grafo{
	int x, y, temp;
	grafo vizinhos[8];
} Grafo

int main()
{	
	int linhas,colunas,i,j,totalSaidas,temperaturas[][1000],ySaidas[],xSaidas[],xInicio,yInicio;

	scanf("%d %d",&linhas,&colunas);	
	for ( i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++j)
		{
			scanf("%d",&temperaturas[i][j]);
		}
	}
	scanf("%d %d",&xInicio,&yInicio);

	scanf("%d",&totalSaidas);

	for (i = 0; i < totalSaidas; ++i)
	{
		scanf("%d %d",&xSaidas[i],&ySaidas[i]);
	}

	return 0;
}