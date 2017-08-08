package base.cartas.magia;

import java.util.ArrayList;
import java.util.UUID;

import base.cartas.Lacaio;

public class DanoArea extends Dano{

	public DanoArea(UUID id, String nome, int custoMana, int dano) {
		super(id, nome, custoMana, dano);
	}

	public DanoArea(String nome, int custoMana, int dano) {
		super(nome, custoMana, dano);
	}
	
	public void usar(ArrayList<Lacaio> alvos){
		for(Lacaio lac :alvos){
			lac.setVidaAtual(lac.getVidaAtual()-this.getDano());
		}
	}
	
	public String toString(){
		String out = super.toString();
		return out;
	}
}
