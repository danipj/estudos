#include <stdio.h>
 

int encontraSuperior(int funcionario, int matriz[][30], int tamanho){
    int i;
    if (funcionario==0)
    /*ja e o presidente*/
    	printf ("0\n");
    else{
    	/*escreve funcionario*/ 
	    printf ("%d ", funcionario);
     	/*percorre coluna para achar superior*/
    	for (i=0; i<tamanho; i++){
        	if (matriz[i][funcionario]==1){
            	encontraSuperior(i,matriz,tamanho);
	        }
    	}
	}
}
 
int main (){

    int mat[30][30],tam,func,i,j;

    /*lendo tamanho da matriz, funcionario a ser buscado e matriz da empresa*/
    scanf ("%d %d", &tam, &func);
    for (i=0; i<tam; i++) {
        for (j=0; j<tam; j++){
            scanf ("%d", &mat[i][j]);
        }
    }
    /*escreve a hierarquia do funcionario*/
    encontraSuperior(func,mat,tam);
    
    return 0;
}