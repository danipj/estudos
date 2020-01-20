#include <stdio.h>
#include <stdlib.h>
#define MAX_DIST 1001

struct Aresta {
  struct Aresta* prox;
  int peso, destino;
};
struct Vertice {
  struct Aresta* adjacencias;
};


int main(){
  struct Aresta *nova, *arestaAtual;
  struct Vertice *vertices;
  int nSistemas, nBuracos, i,k, fonte, destino, peso, distancias[MAX_DIST];

  scanf("%d %d", &nSistemas, &nBuracos);
  /* inicializa vetor de vertices*/
  vertices = (struct Vertice*)malloc(nSistemas*sizeof(struct Vertice));
  
  /*inicializa distancias com inifinito*/
  for(i=1; i<nSistemas;i++){
    distancias[i] = MAX_DIST;
  }
  /*fonte tem dist zero*/
  distancias[0] = 0;

  /*le e inicializa as arestas*/
  for(i=0; i<nBuracos;i++){
    scanf("%d %d %d", &fonte, &destino, &peso);
    nova = malloc(sizeof(struct Aresta));
    nova->destino = destino;
    nova->peso = peso;
    nova->prox = NULL;
    if(vertices[fonte].adjacencias == NULL){
      vertices[fonte].adjacencias = nova;
    } else{
      arestaAtual = vertices[fonte].adjacencias;
      while(arestaAtual->prox != NULL) arestaAtual = arestaAtual->prox;
      arestaAtual->prox = nova;
    }
  }

  /*atualiza vetor de distancias com bellman-ford*/
  for(k=0; k<nSistemas;k++){
    for(i=0; i<nSistemas;i++){
      arestaAtual = vertices[i].adjacencias;
      /*relaxa todas as arestas do vertice*/
      while (arestaAtual != NULL){
        /*se a distancia da fonte ate o vertice eh menor com a aresta, atualizar
        se o vertice nao for alcancavel nao mudar o valor da dist*/
        if (distancias[arestaAtual->destino] > distancias[i] + arestaAtual->peso)
          distancias[arestaAtual->destino] = distancias[i] + arestaAtual->peso;
        arestaAtual = arestaAtual->prox;
      }
    }
  }

  /*procura se existe ciclo negativo*/
  for(i=0; i<nSistemas;i++){
    arestaAtual = vertices[i].adjacencias;
    /*percorre todas as arestas do vertice*/
    while (arestaAtual != NULL){
      /*se a distancia da fonte ate o vertice eh menor com a aresta, existe ciclo
      OBS nao considerar vertices que nao sao alcancaveis a partir da fonte*/
      if (distancias[arestaAtual->destino] > distancias[i] + arestaAtual->peso && distancias[arestaAtual->destino] < MAX_DIST){
        printf("Possivel\n");
        return 0;
      }
      arestaAtual = arestaAtual->prox;
    }
  }
  /*se nao saiu do programa até aqui nao existe ciclo*/
  printf("Impossivel\n");
  return 0;
}