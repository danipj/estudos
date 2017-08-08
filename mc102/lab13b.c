/*
Daniela Palumbo
166301
Lab Quadtree
*/
#include <stdio.h>

/*declara matriz que sera usada pelo programa*/
int mat[1025][1025];

int contaQuad(int iComeco, int jComeco, int tam){
	int i,j, cor;
	/*pegar cor do quadrante*/
	cor = mat[iComeco][jComeco];
	/*percorre matriz*/
	for (i = iComeco; i < iComeco+tam; ++i)
	{
		for (j = jComeco; j < jComeco+tam; ++j)
			{
				/*se achar pixel de outra cor, divide em quadrantes*/
				if (mat[i][j]!=cor)
				{
					return contaQuad(iComeco, jComeco, tam/2) + contaQuad(iComeco+tam/2, jComeco, tam/2) + contaQuad(iComeco, jComeco+tam/2, tam/2) + contaQuad(iComeco+tam/2, jComeco+tam/2, tam/2);
				}
			}
	}
	return 1;
}

int main()
{	
	int i,j,tam;
	/*le tamanho da matriz*/
	scanf("%d",&tam);
	/*le matriz*/
	for (i = 0; i < tam; ++i)
	{
		for (j = 0; j < tam; ++j)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Numero de regioes = %d\n",contaQuad(0,0,tam));
	return 0;
}