/*167474 Fernanda Wohlers */

#include <stdio.h>

int ehPrimo(int nro){
	int i;
	/*1 nao eh primo*/
	if(nro==1)
		return 0;
	/*verifica os numeros ate a metade do numero escolhido. comeca em 2 pq a divisao por 1 sempre da resto zero.*/
	for (i = 2; i <= nro/2; ++i)
	{
		if (nro % i == 0)
		{
			/*se o resto da divisao por algum numero for zero ele nao eh primo*/
			return 0;
		}
	}
	/*eh primo*/
	return 1;
}

int jogar(){
	int pontosDoTurno = 0;
	int carta1,carta2,maior,menor,soma,dif,i;
	scanf("%d",&carta1);
	scanf("%d",&carta2);
	/*achar qual carta eh maior*/
	if(carta1>carta2){
		maior = carta1;
		menor = carta2;
	} else if (carta2>carta1){
		maior = carta2;
		menor = carta1;
	}
	/*calcular diferenca*/
	dif = maior-menor;
	/*se for primo, dar 5 pontos*/
	if (ehPrimo(dif)==1)
		pontosDoTurno += 5;
	/*achar nros primos entre as cartas*/
	soma = 0;
	for (i = menor; i <= maior; ++i)
	{
		/*se for primo somar*/
		if(ehPrimo(i)==1)
			soma+=i;
	}
	/*verifica se eh maior ou igual a 1000*/
	if (soma>=1000)
	{
		pontosDoTurno+=2;
	}
		/*se ainda nao ganhou nenhum ponto eh pq tudo deu errado.*/
	if (pontosDoTurno==0)
	{	/*dai ganha um ponto*/
		pontosDoTurno=1;
	}

	return pontosDoTurno;
}

int main()
{	
	int pontosJogadorA, pontosJogadorB, turno;
	pontosJogadorA=0;
	pontosJogadorB=0;
	/*ler cartas por todo o infinito ate algum jogador atingir os pontos e vencer*/
	/*cada turno tem 4 cartas, 2 pra cada jogador*/
	/*ver se a diferenca entre as cartas eh nro primo - 5 pontos*/
	/*ver se a soma dos primos entre as cartas eh >=1000 - 2 pontos*/
	/*se n der nada - 1 ponto*/
	turno = 0;
	while((pontosJogadorB<50)&&(pontosJogadorA<50)){
		/*comeca o turno*/
		turno++;
		/*os 2 jogadores jogam*/
		pontosJogadorA += jogar();
		pontosJogadorB += jogar();
	}
	/*sai do while quando algum dos dois (pode ser os 2) atingir 50 pontos. escrever o status da partida*/
	printf("Numero de turnos: %d\nJogador 1: %d pontos\nJogador 2: %d pontos\n",turno,pontosJogadorA,pontosJogadorB);

	/*verifica quem ganhou*/
	if (pontosJogadorA>pontosJogadorB)
	{
		printf("* Vencedor: Jogador 1\n");
	} else if (pontosJogadorB>pontosJogadorA)
	{
		printf("* Vencedor: Jogador 2\n");
	} else{
		printf("* Jogo empatado\n");
	}

	return 0;
}