/*Daniela Palumbo Jorge
166301
Lab WalkBot 2*/

#include <stdio.h>

int colunas, tabuleiro[21][21];

int praBinario(int n){
	if (n<2)
	return n%2;

	return praBinario(n/2) * 10 + n%2;
}

int praEsquerda(int n){
	return n%10;
}

int praBaixo(int n){
	return (n%100)/10;
}

int praDireita(int n){
	return (n%1000)/100;
}

int praCima(int n){
	return (n%10000)/1000;
}

int andar(int i, int j, int e){
	int soma = 0;
	/*acabou a energia = nao chega ao final*/
	if (e==0)
		return 0;
	/*se for armadilha = nao chega ao final*/
	if (tabuleiro[i][j]==0)
		return 0;
	/*se nao tiver energia pra chegar nem em linha reta, nao chega mais*/
	if (colunas-j>e)
		return 0;
	/*se tiver como ir pra direita e alcançar o nro de colunas, chegou ao final*/
	if (praDireita(tabuleiro[i][j])==1 && j+1==colunas)
		return 1;
	/*testa todas as direcoes possiveis*/
	if (praDireita(tabuleiro[i][j])==1)
		soma += andar(i, j+1,e-1);
	if (praEsquerda(tabuleiro[i][j])==1)
		soma += andar(i, j-1,e-1);
	if (praBaixo(tabuleiro[i][j])==1)
		soma += andar(i+1, j,e-1);
	if (praCima(tabuleiro[i][j])==1)
		soma += andar(i-1, j,e-1);
	return soma;
}

int main()
{
	int linhas,energia,i,j,aux;

	/*lendo tabuleiro*/
	scanf("%d %d %d",&linhas,&colunas, &energia);
	for (i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++j)
		{
			scanf("%d",&aux);
			tabuleiro[i][j]=praBinario(aux);
		}
	}	

	/*verifica os caminhos*/
	for (i = 0; i < linhas; ++i)
	{
		if (andar(i,0,energia)==0)
			printf("Nao\n");
		else
			printf("Sim\n");
	}

	return 0;
}