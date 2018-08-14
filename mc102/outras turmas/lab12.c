#include <stdio.h>

#define MAX_LINHAS = 10;

char* jogo(int nivel,int entrada, int linhas,int lab[][]){
	int result2, result34, result5,passo;

	/*caso de parada - sucesso*/
	if(nivel==linhas)
		return "E "+entrada+"\n";

	/*lab[nivel+1][0] = total de entradas*/
	for (i = 0; i < lab[nivel+1][0]-1; ++i)
	{ /*lab[nivel][0] = total de barreiras*/
		for (j = 0; j < lab[nivel][0]-1; ++j)
		{
			if(entrada < lab[nivel][j]){ /*pode seguir no anti horario*/
			if (lab[nivel][j] > lab[nivel+1][i]) /*entrada esta antes dessa barreira*/
			{
				/* nao tem barreiras entre vc e a entrada pelo sentido anti horario*/
				return "E "+ lab[nivel+1][i] + "\n" + jogo(nivel+1,lab[nivel+1][i],linhas,lab);
			}} else {
				/*pode falhar pq tem que verificar se a outra barreira tambem nao esta*/
			}
		}
	}
/*verificar se da pra subir um nivel tbm*/
}

int main()
{ 	
	int totalLinhas;
	int labirinto[MAX_LINHAS*2][360];
	char linha[360*4];

	scanf("%d",&totalLinhas);

	for (i = 0; i < 2*totalLinhas-1; ++i)
	{
		/*ler a linha de entradas/barreiras*/
		scanf("%[^\n]",&linha);
		
		/*separar*/
		n = 0;
		count = 0
		for (j = 0; linha[j]!='\0'; ++j)
		{
			if (linha[j]==' '||linha[j+1]=='\0'){
				sscanf(linha+n,"%d",&labirinto[i][count+1]);
				n = j;
				count++;
			}
		}
		/*primeiro elemento da linha é o total de entradas/barreiras daquela linha*/
		labirinto[i][0] = count;
	}

	printf("%s",jogo(1,labirinto[0][0],totalLinhas,labirinto));

	return 0;
}