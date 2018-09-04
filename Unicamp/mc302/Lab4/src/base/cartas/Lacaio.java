package base.cartas;

import java.util.UUID;

import base.Carta;

public class Lacaio extends Carta{

	private int ataque;
	private int vidaAtual;
	private int vidaMaxima;

	public Lacaio(UUID id, String nome, int custoMana, int ataque, int vidaAtual, int vidaMaxima) {
		super(id, nome, custoMana);
		this.vidaMaxima = vidaMaxima;
		this.ataque = ataque;
		this.vidaAtual = vidaAtual;
	}
	
	public Lacaio( String nome, int custoMana, int ataque, int vidaAtual, int vidaMaxima) {
		super( nome, custoMana);
		this.vidaMaxima = vidaMaxima;
		this.ataque = ataque;
		this.vidaAtual = vidaAtual;
	}
	
	public int getAtaque() {
		return ataque;
	}

	public void setAtaque(int ataque) {
		this.ataque = ataque;
	}

	public int getVidaAtual() {
		return vidaAtual;
	}

	public void setVidaAtual(int vidaAtual) {
		this.vidaAtual = vidaAtual;
	}

	public int getVidaMaxima() {
		return vidaMaxima;
	}

	public void setVidaMaxima(int vidaMaxima) {
		this.vidaMaxima = vidaMaxima;
	}

	//@Override ????????????????
	public void usar(Lacaio alvo){
		alvo.setVidaAtual(alvo.getVidaAtual()-this.getAtaque());
	}
	
	@Override
	public String toString() {
		String out = super.toString();
		out = out + "Ataque = " + getAtaque() + "\n";
		out = out + "Vida Atual = "+ getVidaAtual()+ "\n";
		out = out + "Vida Máxima = "+ getVidaMaxima()+ "\n";
		return out;
	}
	

}
