#include <stdio.h>

int main()
{	
	int nTermos,i,denom,sinal;
	double soma;

	scanf("%d",&nTermos);
	
	/*conta = 4 * (1 - 1/impar+  1/proximpar.....)*/
	
	denom = 1;
	sinal = 1;
	soma = 0;
	for (i = 1; i <= nTermos; ++i)
	{	
		/*se o termo atual for par, subtrair*/
		if(i % 2 == 0)
			sinal = -1;
		else
			sinal = 1;

		soma += sinal*(1/(double)denom);

		/*pega o prox impar*/
		denom+=2;
	}
	printf("%.4f\n", soma * 4); 

	return 0;
}