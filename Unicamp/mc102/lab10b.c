/*
Daniela Palumbo Jorge
166301

Lab O Baile de Inverno
*/

#include <stdio.h>

#define FALSE 0
#define TRUE 1

void ordenar(int vet[], int tam){
	int i,j, maior,aux,iMaior;
	for (j = 0; j < tam; ++j)
	{
		for (i = 0; i < tam; ++i)
		{
			if (vet[i]>maior){
				maior=vet[i];
				iMaior =i;
			}
		}
		aux = vet[j];
		vet[j] = vet[iMaior];
		vet[iMaior] = aux;
	}
}
int main()
{
	int homens[1001],mulheres[1001],difMax,nroHomens,nroMulheres, i, j, total;
	
	scanf("%d %d %d", &nroHomens, &nroMulheres, &difMax);

	for (i = 0; i < nroHomens; ++i)
	{
		scanf("%d",&homens[i]);
	}
	for (i = 0; i < nroMulheres; ++i)
	{
		scanf("%d",&mulheres[i]);
	}
	
	/*ordena vetores*/
	ordenar(mulheres,nroMulheres);
	ordenar(homens,nroHomens);

	total = 0;
	for (i = 0; i < nroHomens; ++i)
	{
		for (j= 0; j < nroMulheres; ++j)
		{
			if (homens[i]-mulheres[j]<=difMax){
				total++;
				homens[i] = 0;
				mulheres[j] = 0;
			}
		}
	}
	printf("Numero maximo de duplas equilibradas = %d\n",total);
	return 0;	
}	