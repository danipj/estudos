/*
Daniela Palumbo
166301
Lab PaMonHa
*/
#include <stdio.h>

int main()
{
	int i, totalParl, minimo, custoParl[21], inflParl[21][21],menor,p[21], j, qtos, custo, partido[21], valido, k, totalP;
	
	scanf("%d %d",&totalParl,&minimo);
	
	/*ler custo dos parlamentares*/
	for (i = 0; i < totalParl; ++i)
	{
		scanf("%d",&custoParl[i]);
	}
	
	/*ler matriz de influencias*/
	for (i = 0; i < totalParl; ++i)
	{
		for (j = 0; j < totalParl; ++j)
		{
			scanf("%d",&inflParl[i][j]);
		}
	}
    
	/*guardar quantos cada um influencia*/
	for (i = 0; i < totalParl; ++i)
	{  
        p[i]=1;
		for (j = 0; j < totalParl; ++j)
		{
			 /*verificar se tem influencia*/
            if (j!=i && inflParl[i][j]==1)
                p[i]++;

		}
	}

    /*achar combinacoes de menor custo*/
    menor = 99999;
    for (i = 0; i < totalParl; ++i)
    {   
        qtos = 0;
        custo = 0;
        totalP = 0;
        for (j = 0; j < totalParl; ++j)
        {
            partido[j] = 0;
        }
        valido = 1;
        for (j = 0; j < totalParl && qtos < minimo; ++j)
        {
            /*incrementa total de parlamentares + influencias*/
            qtos += p[j];
            custo += custoParl[j];
            totalP++;
            for (k = 0; k <= totalP; ++k)
            {
                if(inflParl[j][partido[k]]==1 && j!=partido[k])
                    valido = 0;
            }
            partido[j] = j;   
        }
        
        /*troca pelo menor custo*/
        if (custo < menor && valido==1){
            menor = custo;
        }
    }

    printf("%d\n", menor);
	return 0;
}