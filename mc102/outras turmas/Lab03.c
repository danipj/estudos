#include <stdio.h>
int main()
{	
	int A,B,i,somaA,somaB;

	scanf("%d %d",&A,&B);
	somaA = 0;
	somaB = 0;
	/*os divisores de um numero sao no minimo 1 e no maximo ele mesmo*/
	for (i = 1; i < A; ++i)
	{
		/*um numero e divisor se nao tem resto*/
		if (A % i == 0)
		{
			somaA += i;
		}
	}
	for (i = 1; i < B; ++i)
	{
		/*um numero e divisor se nao tem resto*/
		if (B % i == 0)
		{
			somaB += i;
		}
	}
	/*se a soma dos div de A for igual a B e a soma dos div de B for igual a A: eles sao brothers*/
	if (somaA==B && somaB==A)
	{
		printf("Os numeros sao amigos.\n");
	}
	else
		printf("Os numeros nao sao amigos.\n");
	
	return 0;
}