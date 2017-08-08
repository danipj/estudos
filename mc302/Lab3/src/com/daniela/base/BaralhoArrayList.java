package com.daniela.base;

import java.util.ArrayList;
import java.util.Collections;

public class BaralhoArrayList {
	
	private ArrayList<CartaLacaio> vetorCartas;
	public static int MAX_CARDS = 30;
	
	public BaralhoArrayList() {
		vetorCartas = new ArrayList<CartaLacaio>();
	}
	
	public void adicionarCarta(CartaLacaio card){
		if (vetorCartas.size()<MAX_CARDS) {
			vetorCartas.add(card);
		}
	}
	
	public CartaLacaio comprarCarta(){
		return vetorCartas.remove(vetorCartas.size()-1);
	}
	
	public void embaralhar(){
		Collections.shuffle(vetorCartas);
	}
}
