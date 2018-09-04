/*Daniela Palumbo Jorge
166301
Lab O o CR*/

#include <stdio.h>

int main()
{   
    int tamPerm,perm[11],i,breakpoints;
 	
 	/*ler permutacao*/
    scanf("%d",&tamPerm);
    for (i = 0; i < tamPerm; ++i)
    {
    	scanf("%d",&perm[i]);
    }

    /*encontrar breakpoints (distancia = nro de bp)*/
	breakpoints = 0;
	for (i = 0; i < tamPerm-1; ++i){
		/*se o proximo for menor, quebra a ordem crescente*/
		if(perm[i+1]<perm[i])
			breakpoints++;
	}    

	printf("%d\n",breakpoints);
     
    return 0;
}