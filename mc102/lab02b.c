/*
Daniela Palumbo Jorge
RA 166301

Lab Dolares Elficos
*/

#include <stdio.h>
#include <math.h>

int main()
{	int nroCasas, gramas, cambio, totalNotas, expoente, totalDolar, atualDolar, menor, casaAtual, i;
	scanf("%d %d %d", &nroCasas, &gramas, &cambio);

	/*criar vetor do tamanho das casas que serao lidas*/
	int basePorCasa[nroCasas], notasPorCasa[nroCasas];

	/*ler casa por casa*/
	for(i = 0; i< nroCasas; ++i)
	{
		scanf("%d", &basePorCasa[i]);
	}

	/*determinar quanto valem as gramas de ouro*/
	totalDolar = gramas * cambio;

	/*verificar casa por casa qual o nro de notas necessarias*/
	for (casaAtual = 0; casaAtual < nroCasas; ++casaAtual)
	{
		atualDolar = totalDolar;
		totalNotas = 0;

		/*subtraindo as notas encontradas, chegara a zero*/
		while(atualDolar > 0)
		{
		
		/*achar maior potencia da casa que seja menor que atualDolar*/
			expoente = 1;		
			while(pow((double)basePorCasa[casaAtual], expoente) <= atualDolar)
			{
				expoente++;
			}
		
		/*quando sair do while, sera o maior expoente menor que atualDolar
		subtrair maior potencia do montante de dinheiro atual e acrescentar nota*/
			atualDolar = atualDolar - pow(basePorCasa[casaAtual], expoente-1);
			totalNotas++;
		}

		/*acrescentar no indice correspondente o minimo de notas que esse casa vai dar*/
		notasPorCasa[casaAtual] = totalNotas;
	}

	/*tendo o total de notas que cada casa pode dar, falta descobrir qual das casas da o menor nro de notas*/
	menor = totalDolar;
	for (casaAtual = 0; casaAtual < nroCasas; ++casaAtual)
	{
		if (notasPorCasa[casaAtual] < menor){
			menor = notasPorCasa[casaAtual];
		}
	}
	printf("Numero minimo de notas = %d\n",menor);
	return 0;
}
