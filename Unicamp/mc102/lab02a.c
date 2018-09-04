/*
Daniela Palumbo Jorge
RA 166301

Lab Coeficiente de Rendimento
*/

#include <stdio.h>
#define A 4
#define B 3
#define C 2
#define D 1
#define E 0

int main()
{
	int credito,  somatoria = 0, creditos = 0;
	char conceito = 0;

	/*
	CALCULO DO CR:
	Somatoria de conceito multiplicado por credito, dividido pela soma dos creditos
	*/

	/* Ler varios conceitos e creditos ate encontrar o asterisco*/
	while (1 != 2){ /* while infinito pois a execucao sera encerrada dentro*/
		
		scanf("%s", &conceito);

		if (conceito == '*'){
			
			if (creditos == 0){ /* se nenhuma materia tiver sido lida, o aluno nao cursou nada*/
				printf("CR = Indefinido\n");
				return 0; /* encerra a execucao do programa pois nao ha o que calcular ou escrever */
			}

			break; /* sai do while pois nao ha mais o que ler ou calcular */
		}
		
		scanf("%d", &credito);

	/* Multiplicar cada conceito pelo credito da materia e somar ao montante */
		switch(conceito){
			case 'A':
				somatoria += A * credito;
				break;
			case 'B':
				somatoria += B * credito;
				break;
			case 'C':
				somatoria += C * credito;
				break;
			case 'D':
				somatoria += D * credito;
				break;
			case 'E':
				somatoria += E * credito;
				break;
		}
	/* Somar os creditos que o aluno cursa para ser o divisor da somatoria */
		creditos += credito;
	}

	printf("CR = %.4f\n", (double)somatoria/creditos );
	return 0;
}
