/*Não se esqueça de incluir no início do programa uma breve descrição dos objetivos, da entrada, da saída, seu nome e RA;*/
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
	int mat[3][3],divisor,i,j,aux,colunas,linhas,img[600][600],imgFinal[600][600];
	char str[200];
	FILE *arqImgOriginal,*arqDivMat;
	
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
	arqDivMat = fopen(argv[2],"r");
	fscanf(arqDivMat,"%d %d %d %d %d %d %d %d %d %d",&divisor,&mat[0][0],&mat[0][1],&mat[0][2],&mat[1][0],&mat[1][1],&mat[1][2],&mat[2][0],&mat[2][1],&mat[2][2]);
	fclose(arqDivMat);

	/*aplicar para cada pixel a formula de convolucao*/
	for (i = 1; i < linhas-1; ++i)
	{
		for (j = 1; j < colunas-1; ++j)
		{	
			imgFinal[i][j]=(mat[0][0]*img[i-1][j-1]+mat[0][1]*img[i][j-1]+mat[0][2]*img[i+1][j-1]+mat[1][0]*img[i-1][j]+mat[1][1]*img[i][j]+mat[1][2]*img[i+1][j]+mat[2][0]*img[i-1][j+1]+mat[2][1]*img[i][j+1]+mat[2][2]*img[i+1][j+1])/divisor;
			if (imgFinal[i][j]>255)
			{
				imgFinal[i][j] = 255;
			} 
			if (imgFinal[i][j]<0){
				imgFinal[i][j] = 0;
			}
		}
	}
	/*manter bordas*/
	for (i = 0; i < colunas; ++i)
	{
		imgFinal[0][i]=img[0][i];
		imgFinal[linhas-1][i]=img[linhas-1][i];
	}
	for (i = 1; i < linhas-1; ++i)
	{
		imgFinal[i][0]=img[i][0];
		imgFinal[i][colunas-1]=img[i][colunas-1];
	}
	
	escrever_pgm(imgFinal,colunas,linhas);
	return 0;
}