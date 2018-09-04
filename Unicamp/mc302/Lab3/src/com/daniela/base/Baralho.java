package com.daniela.base;

import java.util.Random;

public class Baralho {
	CartaLacaio[] vetorCartas;
	int nCartas;
	static Random gerador = new Random();
	
	public Baralho(){
		vetorCartas = new CartaLacaio[10];
		nCartas = 0;
	}
	
	public void adicionarCarta(CartaLacaio card){
		vetorCartas[nCartas] = card;
		nCartas++;
	}
	
	public CartaLacaio comprarCarta(){
		nCartas--;
		return vetorCartas[nCartas];
	}
	
	public void embaralhar(){
		int i, j;
		
		for(i=1;i<nCartas;i++){
			j = gerador.nextInt(i+1);
			if (j!=i) {
				CartaLacaio a = vetorCartas[i];
				CartaLacaio b = vetorCartas[j];
				vetorCartas[j] = a;
				vetorCartas[i] = b;
			}
		}
		
		for(i=nCartas-1;i>0;i--){
			System.out.println(vetorCartas[i]);
		}
	}
	
}
