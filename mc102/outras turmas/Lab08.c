#include <stdio.h>

int fatorial(int nro){
	/*fatorial de 1 eh 1*/
	if (nro==1)
	{
		return 1;
	} else {
		/*fatorial: numero vezes o fatorial dele menos 1, ate chegar em 1*/
		return nro * fatorial(nro-1);
	} 
}

float expoente(float x, int ex){
	float result = 1;
	int i;
	/*mesmo se expoente zero, retorna 1*/
	for (i = 0; i < ex; ++i)
	{
		/*numero vezes ele mesmo*/
		result = result * x;	
	}
	return result;
}

float seno(float nro, int N){
	int i;
	int sinal = -1;
	float soma = 0;
	/*for = repeticao da somatoria*/
	for (i = 0; i < N; ++i)
	{	
		/*representacao da formula*/
		soma += expoente(sinal,i) * expoente(nro,2*i+1) / (double)fatorial(2*i+1);
	}
	return soma;
}

float cosseno(float nro,int N){
	int i;
	int sinal = -1;
	float soma = 0;
	for (i = 0; i < N; ++i)
	{
		soma += expoente(sinal,i) * expoente(nro,2*i) / (double)fatorial(2*i);
	}
	return soma;
}

float senoHiper(float nro,int N){
	int i;
	float soma = 0;
	/*for = repeticao da somatoria*/
	for (i = 0; i < N; ++i)
	{	
		/*representacao da formula*/
		soma += expoente(nro,2*i+1) / (double)fatorial(2*i+1);
	}
	return soma;
}
float cossenoHiper(float nro,int N){
	int i;
	float soma = 0;
	/*for = repeticao da somatoria*/
	for (i = 0; i < N; ++i)
	{	
		/*representacao da formula*/
		soma += expoente(nro,2*i) / (double)fatorial(2*i);
	}
	return soma;
}

int main()
{	
	int N;
	float x;
	char operacao;
	scanf(" %c",&operacao);
	while(operacao!='F'&&operacao!='f'){
		switch(operacao){
			case 's':
				scanf("%f %d",&x,&N);
				printf("O valor aproximado de seno de %.4f eh %.4f.\n",x,seno(x,N));
				break;
			case 'S':
				scanf("%f %d",&x,&N);
				printf("O valor aproximado de seno hiperbolico de %.4f eh %.4f.\n",x,senoHiper(x,N));
				break;
			case 'c':
				scanf("%f %d",&x,&N);
				printf("O valor aproximado de cosseno de %.4f eh %.4f.\n",x,cosseno(x,N));
				break;
			case 'C':
				scanf("%f %d",&x,&N);
				printf("O valor aproximado de cosseno hiperbolico de %.4f eh %.4f.\n",x,cossenoHiper(x,N));
				break;
			default:
				printf("Comando invalido.\n");
				break;
		}
		scanf(" %c",&operacao);	
	}
	return 0;
}