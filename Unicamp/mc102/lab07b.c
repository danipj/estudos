/*
Daniela Palumbo Jorge
166301
Lab Walk-Bot
*/

#include <stdio.h>

int linhas, colunas, passos, passosLoop;
char tabuleiro[60][60], caminho[60][60];

/*
funcao que verifica para cada casa passada qual caminho seguir
return codes:
0 = ja printou a mensagem
1 = loop    
*/
int andar(int linha, int coluna){
    
    /*verifica se esta na ultima casa do tabuleiro*/
    if(coluna == colunas){
        printf("Saiu em (%d,%d) apos %d passo(s)\n",linha+1, colunas, passos-1);
        return 0;
    }
    
    /*verifica se ele ja passou por essa casa e marca como inicio do loop*/
    if(caminho[linha][coluna] == '*'){
        caminho[linha][coluna] = '!';
        return 1;
    }

    /*marca o caminho andado*/
    caminho[linha][coluna] = '*';

    switch(tabuleiro[linha][coluna]){
        case 'L':
            passos+=1;
            andar(linha,coluna-1);
            break;
        case 'R':
            passos+=1;
            andar(linha,coluna+1);
            break;
        case 'U':
            passos+=1;
            andar(linha-1,coluna);
            break;
        case 'D':
            passos+=1;
            andar(linha+1,coluna);
            break;
        case 'X':
            printf("Armadilha em (%d,%d) apos %d passo(s)\n",linha+1, coluna+1, passos);
            return 0;
            break;
        }
}

/*funcao que conta o tamanho do loop*/
int loop(int linha, int coluna){

    /*quando achar a casa do loop, subtrai os passos ate la do total de passos*/
    if(caminho[linha][coluna]=='!')
        return passos - passosLoop;

    switch(tabuleiro[linha][coluna]){
        case 'L':
            passosLoop+=1;
            loop(linha,coluna-1);
            break;
        case 'R':
            passosLoop+=1;
            loop(linha,coluna+1);
            break;
        case 'U':
            passosLoop+=1;
            loop(linha-1,coluna);
            break;
        case 'D':
            passosLoop+=1;
            loop(linha+1,coluna);
            break;
        }
}

int main()
{
	int i, j, k, code;

	scanf("%d %d", &linhas, &colunas);

	/*le cada casa do tabuleiro*/
	for (i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++j)
		{
			scanf(" %c",&tabuleiro[i][j]);
		}
	}

    /*testa o caminho para cada casa (i, 1)*/
    for (i = 0; i < linhas; ++i)
    {   
        /*limpa total de passos e caminho percorrido*/
        passos = 0;
        passosLoop = 0;
        for (j = 0; j < linhas; ++j)
        {
            for (k = 0; k < colunas; ++k)
            {
                caminho[j][k]='.';
            }
        }

        code = andar(i,0);
        
        /*code 1 = loop*/
        if (code == 1)
            printf("Loop de tamanho %d\n", loop(i,0));
    }

	return 0;
}