//Fernanda Wohlers Picerni 167474

#include <stdio.h>
int colunas,linhas;

/* Escreve a imagem em formato PGM na saida padrao */
void escrever_pgm(int img[][600], int col, int lin) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");

    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d\n255\n", col, lin);

    /* Escreve os pontos da imagem */
    for (i = 0; i < lin; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < col; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

void pintaArredores(int y, int x, int img[][600], int cor, int novaCor){
	//pinta linha superior: y-1 x-1, y-1 x, y-1 x+1
	if (y-1>=0)
	{	
		if (x-1 >=0 && img[y-1][x-1] == cor)
		{
			img[y-1][x-1] = novaCor;
			pintaArredores(y-1,x-1,img,cor,novaCor);
		}
		if (img[y-1][x] == cor)
		{
			img[y-1][x] = novaCor;
			pintaArredores(y-1,x,img,cor,novaCor);
		}
		if (x+1<=colunas && img[y-1][x+1] == cor)
		{
			img[y-1][x+1] = novaCor;
			pintaArredores(y-1,x+1,img,cor,novaCor);
		}
	}

	//pinta linha: y x-1, y x+1
	if (x-1 >=0 && img[y][x-1] == cor)
	{
		img[y][x-1] = novaCor;
		pintaArredores(y,x-1,img,cor,novaCor);
	}
	if (x+1<=colunas && img[y][x+1] == cor)
	{
		img[y][x+1] = novaCor;
		pintaArredores(y,x+1,img,cor,novaCor);
	}
	
	//pinta linha inferior: y+1 x-1, y+1 x, y+1 x+1
	if (y+1<linhas)
	{
		if (x-1 >=0 && img[y+1][x-1] == cor)
		{
			img[y+1][x-1] = novaCor;
			pintaArredores(y+1,x-1,img,cor,novaCor);
		}
		if (img[y+1][x] == cor)
		{
			img[y+1][x] = novaCor;
			pintaArredores(y+1,x,img,cor,novaCor);
		}
		if (x+1<=colunas && img[y+1][x+1] == cor)
		{
			img[y+1][x+1] = novaCor;
			pintaArredores(y+1,x+1,img,cor,novaCor);
		}
	}
	// pintar coord do clique: x y
	img[y][x] = novaCor;
}

int main(int argc, char const *argv[])
{
	int cliqueY,cliqueX,novaCor,i,j,aux,img[600][600];
	char str[200];
	FILE *arqImgOriginal,*arqParam;
	
	/*abrir arquivo pra leitura*/
	arqImgOriginal = fopen(argv[1],"r");
	
	/*desconsiderar string P2*/
	fscanf(arqImgOriginal, "%s", str);

	/*ler dimensao da img*/
	fscanf(arqImgOriginal, "%d %d", &colunas,&linhas);
	
	/*ler valor max de cinza - inutil na entrada*/
	fscanf(arqImgOriginal, "%d", &aux);

	/*ler imagem*/
	for (i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++j)
		{
			fscanf(arqImgOriginal, "%d", &img[i][j]);
		}
	}
	/*fim da leitura*/
	fclose(arqImgOriginal);

	/*lendo segundo arquivo de string pra int*/
	arqParam = fopen(argv[2],"r");
	fscanf(arqParam,"%d %d %d",&cliqueY,&cliqueX,&novaCor);
	fclose(arqParam);

	pintaArredores(cliqueY,cliqueX,img,img[cliqueY][cliqueX],novaCor);

	escrever_pgm(img,colunas,linhas);	

	return 0;
}