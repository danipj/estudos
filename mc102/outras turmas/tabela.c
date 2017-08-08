/*
Nicole Tavares 156881
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
	int i, j, qtasLinhas,achou, coluna,charProcurada,qtsChar,escreveu;
	char procurada[101],str[100],linha[126];
	char linhas[1000][126];

	/*le a palavra buscada*/
	scanf("%[^\n]s", procurada);
	getchar();

	/*ler nro de linhas da tabela*/
	scanf("%d",&qtasLinhas);
	getchar();

	/*le cabecalho - nao sera necessario*/
	scanf("%[^\n]s",str);
	getchar();

	for (i = 0; i < qtasLinhas; ++i)
	{
		scanf("%[^\n]s", linha);
		/*poe char a char na tabela*/
		for (j= 0; linha[j]!='\0'; ++j)
		{
			linhas[i][j] = linha[j];
		}
		/*marca o final da string*/
		linhas[i][j] = '\0';
		getchar();
	}

	/*saber o tamanho da palavra procurada*/
	for (charProcurada = 0; procurada[charProcurada]!='\0'; ++charProcurada){
		if(procurada[charProcurada]==',')
			/*se tiver virgula, nunca sera encontrado*/
			return 0;
	}

	/*procura na tabela*/
	for (i = 0; i < qtasLinhas; ++i)
	{	
		achou = FALSE;
		qtsChar = 0;
		j = 0;
		coluna = 1;

		/*percorre a linha toda*/
		while(linhas[i][j]!='\0')
		{	
			if(linhas[i][j]==','){
				/*virgula = nova coluna*/
				coluna++;
				escreveu = FALSE;
				achou = FALSE;
			}

			if (qtsChar>0 && linhas[i][j]!=procurada[qtsChar])
				/*string comecou igual mas mudou*/
				qtsChar =0;

			if (achou==FALSE && linhas[i][j]==procurada[qtsChar])
				/*possivel match com procurada*/
				qtsChar++;

			if (qtsChar==charProcurada)
				/*achou a string completa*/
				achou=TRUE;
		
	
			if(achou==TRUE&&escreveu==FALSE){
				/*escreve mensagem*/
				printf("Linha %d, Coluna \"", i+1);

				switch(coluna-1){
					case 0:
						printf("RA");
						break;
					case 1:
						printf("Nome");
						break;
					case 2:
						printf("Curso");
						break;
					case 3:
						printf("Telefone");
						break;
					case 4:
						printf("Estado");
						break;
				}
				printf("\"\n");
				achou = FALSE;
				qtsChar = 0;
				escreveu = TRUE;
			}

			/*continua percorrendo linha*/
			j++;
		}
	}
	return 0;
}