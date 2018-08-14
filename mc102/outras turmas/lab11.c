#include <stdio.h>

int jogo(int n){
	int result2, result34, result5,passo;

	/*caso de parada - sucesso*/
	if(n==42)
		return 1;
	/*caso de parada - falha */
	if(n<42)
		return 0;

	/*testar as possibilidades*/
	result5 = result34 = result2 = 0;

	if(n%5==0)
		result5 = jogo(n-42);
	if(n%3==0||n%4==0){
		passo = (n%100)/10 * (n%10);
		/*evitar que trave no mesmo numero*/
		if (passo!=0)
			result34 = jogo(n - passo);
	}
	if(n%2==0)
		result2 = jogo(n/2);

	/*se algum dos caminhos der certo, retorna 1*/
	return result2 || result34 || result5;	

	return 0;
}

int main()
{ int totalGremlins;

	scanf("%d",&totalGremlins);

	if(jogo(totalGremlins))
		printf("Sim\n");
	else
		printf("Não\n");

	return 0;
}