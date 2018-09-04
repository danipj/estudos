package base;

import java.util.ArrayList;
import java.util.Collections;


public class Baralho {
	
	private ArrayList<Carta> vetorCartas;
	
	public Baralho() {
		vetorCartas = new ArrayList<Carta>();
	}
	
	public void adicionarCarta(Carta card){
		if (vetorCartas.size()<util.Util.MAX_CARDS) {
			vetorCartas.add(card);
		}
	}
	
	public Carta comprarCarta(){
		return vetorCartas.remove(vetorCartas.size()-1);
	}
	
	public void embaralhar(){
		Collections.shuffle(vetorCartas);
	}
	
	public ArrayList<Carta> getCartas(){
		return vetorCartas;
	}
	
	public String toString(){
		String out = "Baralho: \n";
		for(Carta c:this.getCartas()){
			out = out + c ;
		}
		return out;
	}
}
