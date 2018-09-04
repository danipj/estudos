#include "lab8.h"
#include <math.h>

/*Definicao das constantes*/
#define MAX_POINTS      500
#define MAX_OPERATIONS  60000
#define MAX_STYLE       256

#define MY_PI 3.14159265358979323846
	
int main(){
	int i,j;
	/* Variáveis para armazenar todas as operações */
	int    totalOperacoes[1];
	double op_pontos[MAX_OPERATIONS][2];
	char   tipo[MAX_OPERATIONS];
	/* Variáveis que armazenam um polígono */
	int    totalPontos[1];
	double pontos[MAX_POINTS][2];
	char   estilo[MAX_STYLE];
	double pontosnovo[MAX_POINTS][2];
	
	/* Lendo as operações */
	scan_svg(totalOperacoes,op_pontos,tipo);
	
	
	/* Polígonos */
	scan_svg(totalPontos,pontos,estilo);

	while(totalPontos[0]>=0){
		for (i = 0; i < totalPontos[0]; ++i)
		{
			
			pontosnovo[i][0] = pontos[i][0];
			pontosnovo[i][1] = pontos[i][1];
		}
		/*Aplicar transformaçoes*/
		for(i=1;i<totalOperacoes[0];++i){
			
			if(tipo[i]=='S')
				for (j = 0; j < totalPontos[0]; ++j)
				{
					pontosnovo[j][0] = pontosnovo[j][0] * op_pontos[i][0];
					pontosnovo[j][1] = pontosnovo[j][1] * op_pontos[i][1];	
				}
			else if(tipo[i]=='T')
				for ( j = 0; j < totalPontos[0]; ++j)
				{
					pontosnovo[j][0] = pontosnovo[j][0] + op_pontos[i][0];
					pontosnovo[j][1] = pontosnovo[j][1] + op_pontos[i][1];
				}
			else if(tipo[i]=='R'){
				double grau,xNovo,yNovo;
				grau = op_pontos[i][0] *  ((double)MY_PI/180);
				for ( j = 0; j < totalPontos[0]; ++j)
				{
					xNovo = pontosnovo[j][0] * cos(grau) - (pontosnovo[j][1] * sin(grau));
					yNovo = pontosnovo[j][0] * sin(grau) + (pontosnovo[j][1] * cos(grau));
					pontosnovo[j][0] = xNovo;
					pontosnovo[j][1] = yNovo;	
				}
			}
			else{
				print_svg(totalPontos,pontosnovo,estilo);
				for (j = 0; j < totalPontos[0]; ++j)
				{
					pontosnovo[j][0] = pontos[j][0];
					pontosnovo[j][1] = pontos[j][1];
				}
			}
		}
		print_svg(totalPontos,pontosnovo,estilo);
		scan_svg(totalPontos,pontos,estilo);
	}
	close_svg();
	return 0;
}