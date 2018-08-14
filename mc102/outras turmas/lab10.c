#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

int main()
{	
	int nInstrumento,nNota,nIntensidade,nInstante,nDuracao,totalEventos,i,ordenado;

	TpEvento *eventos = (TpEvento*) malloc(sizeof(TpEvento));

	/*inicializa para entrar no loop*/
	nInstrumento=-1;
	totalEventos=0;
	while(nInstrumento!=0){
 		scanf("%d %d %d %d %d",&nInstrumento,&nNota,&nIntensidade,&nInstante,&nDuracao);

 		if(nInstrumento!=0){
 			/*Evento de inicio*/
 			eventos = (TpEvento*) realloc(eventos, (totalEventos+1)*sizeof(TpEvento));
	 		eventos[totalEventos].instante = nInstante; 
	 		eventos[totalEventos].instrumento = nInstrumento;
	 		eventos[totalEventos].nota = nNota;
	 		eventos[totalEventos].intensidade = nIntensidade;
	 		totalEventos++;
	 		/*Evento de fim*/
	 		eventos = (TpEvento*) realloc(eventos, (totalEventos+1)*sizeof(TpEvento));
	 		eventos[totalEventos].instante = nInstante+nDuracao;
	 		eventos[totalEventos].instrumento = nInstrumento;
	 		eventos[totalEventos].nota = nNota;
	 		eventos[totalEventos].intensidade = 0;
	 		totalEventos++;
	 	}
 	}

 	/*ordenar vetor de eventos a partir de instante*/
 	ordenado = 0;
 	while(ordenado==0){
 		ordenado=1;
	 	for (i = 0; i < totalEventos-1; ++i)
	 	{
	 		if (eventos[i].instante > eventos[i+1].instante)
	 		{
	 			TpEvento aux = eventos[i+1];
	 			eventos[i+1] = eventos[i];
	 			eventos[i] = aux;
	 			ordenado=0;
	 		} else if (eventos[i].instante == eventos[i+1].instante){
	 			/*eventos de mesmo instante devem ser ordenados por instrumento*/
	 			if(eventos[i].instrumento > eventos[i+1].instrumento){
	 				TpEvento aux = eventos[i+1];
	 				eventos[i+1] = eventos[i];
	 				eventos[i] = aux;
	 				ordenado=0;
	 			} else if(eventos[i].instrumento == eventos[i+1].instrumento){
	 				/*eventos de mesmo instante e instrumento devem ser ordenados por nota*/
	 				if(eventos[i].nota > eventos[i+1].nota){
		 				TpEvento aux = eventos[i+1];
		 				eventos[i+1] = eventos[i];
		 				eventos[i] = aux;
		 				ordenado=0;
		 			} else if(eventos[i].nota == eventos[i+1].nota){
		 				/*se tudo for igual, terminar uma nota antes da outra*/
		 				if(eventos[i+1].intensidade==0 && eventos[i].intensidade>0){
			 				TpEvento aux = eventos[i+1];
			 				eventos[i+1] = eventos[i];
			 				eventos[i] = aux;
			 				ordenado=0;
			 			}
		 			}
	 			}
	 		} 
	 	}
	 }

 	saida(0,totalEventos,eventos);
 	/*libera vetor*/
 	free(eventos);
 	return 0;
}