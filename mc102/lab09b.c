/*
Daniela Palumbo Jorge
166301
Lab Peladeiros
*/
#include <stdio.h>

int main()
{	
	int i, j, nroJogadores, nroTimes, iMaior, times[50][50],qts;
	float soma, maior, media[53], notas[53][53];

	/*ler as informacoes*/
	scanf("%d %d",&nroJogadores, &nroTimes);

	for (i = 0; i < nroJogadores; ++i)
	{
		for (j= 0; j < nroJogadores; ++j)
		{
			scanf("%f",&notas[i][j]);
		}
	}

	/*inicializa a matriz*/
	for (i = 0; i < nroTimes; ++i)
	{
		for (j = 0; j < nroJogadores/nroTimes; ++j)
		{
			times[i][j]=-1;
		}
	}

	/*percorrer as colunas e calcular media do jogador*/
	for (i = 0; i < nroJogadores; ++i)
	{
		soma = 0;
		for (j = 0; j < nroJogadores; ++j)
		{
			soma += notas[j][i];
		}
		media[i] = soma / (double)nroJogadores;
	}


	/*achar capitaes (maiores medias)*/
	for (i = 0; i < nroTimes; ++i)
	{
		maior = -1;
		iMaior = 0;
		for (j = 0; j < nroJogadores; ++j)
		{
			if (media[j] > maior){
				maior = media[j];
				iMaior = j;
			}
		} 	
		/*ja foi escolhido = nao precisa mais da media*/
		media[iMaior] = -1;
		
		/*tira da lista pra nao ser escolhido de novo*/
		for (j= 0; j < nroJogadores; ++j)
		{
			notas[j][iMaior] = -1;
		}
		
		/*coloca capitao no time*/
		times[i][0] = iMaior;
	}

	/*escolher time (maior nota dada pelo capitao)*/
	for(qts = 1; qts < nroJogadores/nroTimes; qts++){
		for (i = 0; i < nroTimes; ++i)
		{
			maior = -1;
			iMaior = 0;
			for (j = 0; j < nroJogadores; ++j)
			{
				if(notas[times[i][0]][j]>maior){
					maior = notas[times[i][0]][j];
					iMaior = j;
				}
			}
			
			times[i][qts] = iMaior;
			
			/*tira da lista pra nao ser escolhido de novo*/
			for (j= 0; j < nroJogadores; ++j)
			{
				notas[j][iMaior] = -1;
			}
		}
	}

	/*escrever resultado*/
	for (i = 0; i < nroTimes; ++i)
	{
		printf("Time %d:",i+1);
		for (j = 0; j < nroJogadores/nroTimes; ++j)
		{
			printf(" %d",times[i][j]+1);
		}
		printf("\n");
	}

	return 0;
}