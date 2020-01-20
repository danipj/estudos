#include <stdio.h>
#include <stdlib.h>

#define MAX_MOLECULAS 10000

int bipartido(int i, int j, int** adj, int cor, int cores[MAX_MOLECULAS], int n){
  int res, k;
  /*se nao tem cor (0)*/
  if(cores[j]==0){
  /*colorir filho com cor oposta ao pai*/
    if(cor==1){
      cores[j] = 2;
    } else{
      cores[j]=1;
    }
    /*repetir para filho*/
    res=1;
    for(k=j+1;k<n;k++){
      if(adj[j][k]==1) /*achou um filho*/
        res = res && bipartido(j, k, adj, cores[j], cores, n); 
    }
    /*acabou todos os filhos retorna true pra ramo bicolor*/
    return res && 1;
  } else { /*senao (backedge/cross)*/
    if(cores[j]==cor){
      /*se filho tem mesma cor do pai retorna falso*/
      return 0;
    }else{
    /*senao vai pro proximo filho (de vdd)*/
      res=1;
      for(k=j+1;k<n;k++){
        if(adj[i][k]==1)
        res = res && bipartido(i, k, adj, cores[i], cores, n);
      }
    }
  }
  
  return res;
}

int main(){

  int i,j,k,nLigacoes,nMoleculas, ehBipartido, cores[MAX_MOLECULAS];
  int  **adjacencias;

  scanf("%d",&nMoleculas);
  scanf("%d",&nLigacoes);
  
  adjacencias = (int**)malloc(nMoleculas * sizeof(int*)); 
  for (i = 0; i < nMoleculas; i++){ 
    adjacencias[i] = (int*) malloc(nMoleculas * sizeof(int)); 
    cores[i]=0;
    for (j = 0; j < nMoleculas; j++){ 
      adjacencias[i][j] = 0;
    }
  }

  for(i=0;i<nLigacoes;i++){
    scanf("%d %d",&j, &k);
    if(j==k){
      printf("dotutama\n"); /*possui laco = veneno*/
      return 0;
    } 
    adjacencias[j-1][k-1]=1;
  }

  ehBipartido = 1;
  for(i=0;i<nMoleculas;i++){
    for(j=0;j<nMoleculas;j++){
      if(adjacencias[i][j]==1){
        if(cores[i]==0){
          cores[i]=1;
        }
        ehBipartido = ehBipartido && bipartido(i,j,adjacencias,cores[i],cores, nMoleculas);
      }
    }
  }

  if(!ehBipartido){
    printf("dotutama\n"); /*veneno*/
  } else{
    printf("doturacu ou dotutama\n");
  }

  return 0;
}