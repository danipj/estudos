package base.cartas.magia;

import java.util.UUID;

import base.cartas.Lacaio;

public class Buff extends Magia{
	
	private int aumentoEmAtaque;
	private int aumentoEmVida;
	
	public Buff(UUID id, String nome, int custoMana, int aumentoEmAtaque, int aumentoEmVida) {
		super(id, nome, custoMana);
		this.aumentoEmAtaque = aumentoEmAtaque;
		this.aumentoEmVida = aumentoEmVida;
	}
	
	public Buff( String nome, int custoMana, int aumentoEmAtaque, int aumentoEmVida) {
		super( nome, custoMana);
		this.aumentoEmAtaque = aumentoEmAtaque;
		this.aumentoEmVida = aumentoEmVida;
	}
	
	public int getAumentoEmAtaque() {
		return aumentoEmAtaque;
	}

	public void setAumentoEmAtaque(int aumentoEmAtaque) {
		this.aumentoEmAtaque = aumentoEmAtaque;
	}

	public int getAumentoEmVida() {
		return aumentoEmVida;
	}

	public void setAumentoEmVida(int aumentoEmVida) {
		this.aumentoEmVida = aumentoEmVida;
	}
	
	//@Override ??????????
	public void usar(Lacaio alvo) {
		alvo.setAtaque(alvo.getAtaque()+this.aumentoEmAtaque);
		alvo.setVidaAtual(alvo.getVidaAtual()+this.aumentoEmVida);
	}
	
	@Override
	public String toString() {
		String out = super.toString();
		out = out + "Aumento em Ataque = "+ getAumentoEmAtaque()  + "\n";
		out = out + "Aumento em Vida = "+ getAumentoEmVida()  + "\n";
		return out;
	}


}
