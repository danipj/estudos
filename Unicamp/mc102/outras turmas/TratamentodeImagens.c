#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void cinza(int img[][130*3],int col, int lin){
  int i,j;
  float piso;
  double media;

  //ler R G B e calcular piso
  for (i = 0; i < lin; ++i)
  {
    for (j = 0; j < col; j=j+3)
    {
      media = (img[i][j]+img[i][j+1]+img[i][j+2])/3;
     
      piso = floor(media);
     
      //aplicar piso como rgb
      img[i][j] = piso;
      img[i][j+1] = piso;
      img[i][j+2] = piso;
    }
  }                          
                                                                                                                                                                                                                                                                                                                                         
}
void esticar(int img[][130*3],int col, int lin){
  int i,j;
  float Rmin,Rmax,Bmin,Bmax,Gmin,Gmax;
  Rmin=255;
  Gmin=255;
  Bmin=255;
  Rmax = 0;
  Gmax = 0;
  Bmax = 0;
  //encontrar max e min
  for (i = 0; i < lin; ++i)
  {
    for (j = 0; j < col; j=j+3)
    {
      if(img[i][j]<Rmin){
        Rmin = img[i][j];
      }
      if(img[i][j]>Rmax){
        Rmax = img[i][j];
      }
      if(img[i][j+1]<Gmin){
        Gmin = img[i][j+1];
      }
      if(img[i][j+1]>Gmax){
        Gmax = img[i][j+1];
      }
      if(img[i][j+2]<Bmin){
        Bmin = img[i][j+2];
      }
      if(img[i][j+2]>Bmax){
        Bmax = img[i][j+2];
      }
    }
  }
  //aplicar esticamento
  for (i = 0; i < lin; ++i)
  {
    for (j = 0; j < col; j=j+3)
    {
      //red
      img[i][j] = floor((double)((img[i][j] - Rmin) * 255)/(double)(Rmax - Rmin));
      //green
      img[i][j+1] = floor((double)((img[i][j+1] - Gmin) * 255)/(double)(Gmax - Gmin));
      //blue
      img[i][j+2] = floor((double)((img[i][j+2] - Bmin) * 255)/(double)(Bmax - Bmin));
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Argumentos invalidos. Use:\n");
    fprintf(stderr, "./lab16 <arqEntrada> <arqSaida>\n");
    fprintf(stderr, "Usado:");
    for (int i=0; i<argc; i++) {
	fprintf(stderr, " %s", argv[i]);
    }
    fprintf(stderr, "\n");
    return 1;
  }

  char efeito[20];
  char *arqEntrada = argv[1];
  char *arqSaida = argv[2];

  scanf("%s", efeito);

  int img[130*3][130*3],i,j,colunas,linhas;
  FILE *arqImgOriginal;

  /*abrir arquivo pra leitura*/
  arqImgOriginal = fopen(arqEntrada,"r");
   

  /*ler dimensao da img*/
  fscanf(arqImgOriginal, "P3 %d %d 255", &colunas,&linhas);

  /*ler imagem*/
  for (i = 0; i < linhas; ++i)
  {
      for (j = 0; j < colunas*3; ++j)
      {
          fscanf(arqImgOriginal, "%d", &img[i][j]);
      }
  }
  /*fim da leitura*/
  fclose(arqImgOriginal);

  if (strcmp(efeito,"cinza")==0){
    cinza(img,colunas*3,linhas);
  } else {
    esticar(img,colunas*3,linhas);
  }

  //escrever no arquivo
  FILE *f = fopen(arqSaida, "w");
  fprintf(f,"P3\n%d %d\n255\n",colunas,linhas);

  for (i = 0; i < linhas; ++i)
  {
      fprintf(f, "%d", img[i][0]);
      for (j = 1; j < colunas*3; ++j)
      {
          fprintf(f, " %d", img[i][j]);
      }
      fprintf(f, "\n");
  }

  fclose(f);
  
  return 0;
}
