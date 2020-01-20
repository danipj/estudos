#include <stdio.h>
#include <stdlib.h> 
#define MAX_VERTICES 500
#define MAX_CUSTO 1000001

int main(){
  int nVertices, nArestas, i,j, aux,tries, fonte,destino,peso, menorCusto, nAreas, result, custos[MAX_VERTICES];
  int ** adjacencias, **arvore;

  scanf("%d %d", &nVertices, &nArestas);

  adjacencias = (int**)malloc(nVertices * sizeof(int*)); 
  arvore = (int**)malloc(nVertices * sizeof(int*)); 
  for (i = 0; i < nVertices; i++){ 
    adjacencias[i] = (int*) malloc(nVertices * sizeof(int)); 
    arvore[i] = (int*) malloc(nVertices * sizeof(int)); 
    for (j = 0; j < nVertices; j++){ 
      adjacencias[i][j] = 0;
      arvore[i][j] = 0;
    }
  }

  for (i=0;i<nArestas;i++){
    scanf("%d %d %d", &fonte, &destino, &peso);
    adjacencias[fonte][destino] = peso;
    adjacencias[destino][fonte] = peso;
  }

  /*constroi MST com Prim*/

  /*atribui custo infinito*/
  for(i=0;i<nVertices;i++){
    custos[i] = MAX_CUSTO;
  }

  fonte = 0;
	for(i=0;i<nVertices-1;i++){
    /*atualiza custos das adjacentes*/
    for(j=0;j<nVertices;j++){
      if(adjacencias[fonte][j]>0){
        if(adjacencias[fonte][j] < custos[j]){
          custos[j] = adjacencias[fonte][j];
        }
      }
    }
    /*extrai a aresta leve*/
    menorCusto = MAX_CUSTO;
    for(j=0;j<nVertices;j++){
      if(custos[j] < menorCusto){
        menorCusto = custos[j];
        destino = j;
      }
    }
    custos[destino] = MAX_CUSTO;
    
    /*coloca na mst*/
    arvore[fonte][destino] = adjacencias[fonte][destino];
    adjacencias[fonte][destino] = 0;
    adjacencias[destino][fonte] = 0;
    /*vai pra proximo no*/
    fonte = destino;
	}
	
  scanf("%d", &nAreas);
  for (i=0;i<nAreas;i++){
    scanf("%d %d", &fonte, &destino);
    /*ve maior aresta*/
    result = 0;
    if(fonte > destino){ /*nossa arvore utiliza sempre do menor pro maior*/
      aux = fonte;
      fonte = destino;
      destino = aux;
    }
    tries = 0;
    while(fonte!=destino){
      tries++;
      if(tries > nVertices){ /*se nao tiver achado pode ser pq a arvore ta com a aresta no outro sentido*/
        aux = fonte;
      fonte = destino;
      destino = aux;
      }
      for(j=0;j<nVertices;j++){
        if(arvore[fonte][j]){ /*aresta da arvore*/
          if(arvore[fonte][j] > result){ /*ve se eh a maior*/
            result = arvore[fonte][j];
          } 
          fonte = j;
          break;
        }
      }
    }
    printf("%d\n", result);
  }
  return 0;
}