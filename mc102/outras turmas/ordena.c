/*
Nicole Tavares 156881
*/

#include <stdio.h>

int mdc(int x, int y){
    int resto=x%y;
    while(resto!=0)
    {
        x=y;
        y=resto;
        resto = x%y;
    }
    return y;
}
int inverteAlg(int x){
    int contador = 0, result = 0;
    int ultimoDig;
    while (x > 0){
        ultimoDig = x%10;
        x = x/10;
        result = result * potencia(10,contador) + ultimoDig;
        contador++;
    }
    return result;
}
int potencia(int base, int exp){
    int result = 1, i;
    for (i = 0; i< exp; i++)
        result = result * base;
    return result;
}
int comparar(int x, int y, int m){
    if(mdc(x,m)>mdc(y,m))
        return x;
    if (mdc(x,m)==mdc(y,m))
        if (inverteAlg(x)< inverteAlg(y))
            return x;
        else if (inverteAlg(x)== inverteAlg(y))
            if(x<y)
                return x;
    return y;
}
void BubbleSort(int vet[], int tam){
    int i,j, aux;
    for(i=tam-1; i>0; i--){
        for(j=0; j < i; j++){
            if( vet[j] > vet[j+1] ){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int main(){
    int vetor[2000],result[2000], vetorMdc[2000], vetorInverte[2000], nroLinhas, M, achou, i, j,menor,iMaior,aux,maior,iMenor,k;
    
    scanf("%d %d",&nroLinhas,&M);
    
    
    for (i=0;i<nroLinhas;i++){
        scanf("%d",&vetor[i]);
    }
    BubbleSort(vetor,nroLinhas);

         /*cria um vetor com o resultado dos mdcs*/
    for (i=0;i<nroLinhas;i++){
        if (vetor[i]>=M)
            vetorMdc[i] = mdc(vetor[i],M);
        else
            vetorMdc[i] = 1;
    }

        
    int qts = 0;
    while (qts<nroLinhas){
        int maior = 1;
        /*maior mdc vem primeiro*/
        for (i=qts;i<nroLinhas;i++){            
            if (vetorMdc[i]>maior){
                maior = vetorMdc[i];
                iMaior = i;
            }
        }
        if (maior != 1){
            /*poe o maior na frente nos 2 vetores*/
            aux = vetor[qts];
            vetor[qts] = vetor[iMaior];
            vetor[iMaior] = aux;
            aux = vetorMdc[qts];
            vetorMdc[qts] = vetorMdc[iMaior];
            vetorMdc[iMaior] = aux;
        }
        /*evita que verifique a parte do vetor que ja foi rearranjada*/
        qts++;
    }

    /*vetor esta ordenado por mdc mas ainda pode existir mdcs iguais*/
    i=0;
    while (i < nroLinhas)
    {   
        maior = vetorMdc[i];
        achou = 0;
        k=i;
        while(vetorMdc[k]==maior){
            /*encontrar subvetor de mesmo mdc*/
            k++;
        }
        /*ultima casa que tem elemento de mesmo mdc*/
        achou = k-1;
        /*se existir esse mdc repetido, compara*/
        if (achou-i>0){
            /*ordenar esses elementos por menor inverteAlg*/
            qts = 0;
            while (qts<achou-i){
                menor = 99999;
                for(k = i+qts; k<=achou;k++)
                    if (inverteAlg(vetor[k])<menor){
                        menor = vetor[k];
                        iMenor = k;
                    }
            /*troca os elementos*/
                aux = vetor[i+qts];
                vetor[i+qts] = vetor[iMenor];
                vetor[iMenor] = aux;
        
                qts++;
            }
        }
        /*ajusta indice para procurar proximo subconjunto de mesmo mdc*/
        i = achou+1;
    }

    /*vetor ordenado por mdc e inverteAlg, mas ainda podem ter 2 iguais
        criar vetor de inverteAlg pra ver se algum se repete
    */
    for (i = 0; i < nroLinhas; ++i)
    {
        vetorInverte[i] = inverteAlg(vetor[i]);
    }
    

    i=0;
    while (i < nroLinhas)
    {  
        menor = vetorInverte[i];
        achou = 0;
        k=i;
        while(vetorInverte[k]==menor){
            /*encontrar subvetor de mesmo inverteAlg*/
            k++;
        }
        /*ultima casa que tem elemento de mesmo inverteAlg*/
        achou = k-1;
        /*se existir esse repetido, compara*/
        if (achou-i>0){
            /*ordenar esses elementos*/
            qts = 0;
            while (qts<achou-i){
                menor = 1000000;
                for(k = i+qts; k<=achou;k++)
                    if (vetor[k]<menor){
                        menor = vetor[k];
                        iMenor = k;
                    }
                    
            /*troca os elementos*/
                aux = vetor[i+qts];
                vetor[i+qts] = vetor[iMenor];
                vetor[iMenor] = aux;
        
                qts++;
            }
        }
        /*ajusta indice para procurar proximo subconjunto de mesmo inverteAlg*/
        i = achou+1;
    }

    for (i = 0; i < nroLinhas-1; ++i)
    {
        printf("%d ",vetor[i]);
    }
    printf("%d\n",vetor[nroLinhas-1]);
    return 0;
}
