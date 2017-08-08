/*
Daniela Palumbo
166301
Lab Hanabi
*/

#include <stdio.h>

int contaAltura(int nro){
    int n, i, altura, maior=0;
    /*condicao de parada, zero = nao tem mais filha*/
    if (nro==0){
        return 1;   
    }else{
        /*percorre as filhas*/
        for (i = 0; i < nro; ++i)
        {   
            /*le nro de bombas filhas*/
            scanf("%d",&n);
            altura = contaAltura(n);
            /*a altura final e a maior dos ramos*/
            if (altura>maior)
                maior = altura;
        }
        /*se inclui no maior ramo*/
        return 1+maior;
    }
}
int main()
{   
    int nro;
    scanf("%d", &nro);
    printf("%d\n",contaAltura(nro));
    return 0;
}