package base.cartas.magia;

import java.util.UUID;

import base.cartas.Lacaio;

public class Dano extends Magia{
	
	private int dano;
	
	public Dano(String nome, int custoMana, int dano) {
		super(nome, custoMana);
		this.dano = dano;
	}

	public Dano(UUID id, String nome, int custoMana, int dano) {
		super(id,nome, custoMana);
		this.dano = dano;
	}

	public int getDano() {
		return dano;
	}

	public void setDano(int dano) {
		this.dano = dano;
	}
	
	public void usar(Lacaio alvo){
		alvo.setVidaAtual(alvo.getVidaAtual()-this.getDano());
	}
	
	public String toString() {
		String out = super.toString();
		out = out +" Dano = " + getDano()+ "\n";
		return out;
	}
}
