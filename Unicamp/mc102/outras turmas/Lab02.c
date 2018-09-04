#include <stdio.h>

int main() {

	float prova1,prova2;
	float mediaProva,mediaProvaLab,mediaLab;
	float Lab1, Lab2, Lab3, Lab4, Lab5;
	int Pes1, Pes2, Pes3,Pes4,Pes5;
	float mediaFinal;
	float Exm;



	scanf("%f", &prova1);
	scanf("%f", &prova2);
	scanf("%f", &Lab1);
	scanf("%d", &Pes1);
	scanf("%f", &Lab2);
	scanf("%d", &Pes2);
	scanf("%f", &Lab3);
	scanf("%d", &Pes3);
	scanf("%f", &Lab4);
	scanf("%d", &Pes4);
	scanf("%f", &Lab5);
	scanf("%d", &Pes5);


	mediaProva = (prova1*2 + prova2*3)/5;
	mediaLab = (Lab1*Pes1 + Lab2*Pes2 + Lab3*Pes3 + Lab4*Pes4 + Lab5*Pes5)/ (Pes1+Pes2+Pes3+Pes4+Pes5);

	if (mediaProva <5 || mediaLab<5) {
	    if (mediaProva < mediaLab){
			mediaProvaLab = mediaProva;
		}
 		else 
 			mediaProvaLab= mediaLab;
	}
		else {
			mediaProvaLab= (7*mediaProva+3*mediaLab)/10;
		}

  	if (mediaProvaLab>=2.5 && mediaProvaLab<5) {
	    /*ler nota exame*/
	    scanf("%f", &Exm);
	    mediaFinal = (mediaProvaLab + Exm)/2;
	} else 
		mediaFinal = mediaProvaLab;

	printf("Media final: %.1f. Resultado: ",mediaFinal);

	/*verificar se passou ou nao*/
	if (mediaFinal>=5)
	{
		printf("Aprovado.\n");
	} else
		printf("Reprovado.\n");
}









