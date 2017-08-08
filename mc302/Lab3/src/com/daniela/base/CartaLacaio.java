package com.daniela.base;
public class CartaLacaio {
	
	private int ID;
	private String nome;
	private int ataque;
	private int vidaAtual;
	private int vidaMaxima;
	private int custoMana;
	
	public CartaLacaio(int iD, String nome, int ataque, int vida, int custoMana) {
		this.ID = iD;
		this.nome = nome;
		this.ataque = ataque;
		this.vidaAtual = vida;
		this.vidaMaxima = vida;
		this.custoMana = custoMana;
	}
	
	public CartaLacaio(int iD, String nome, int custoMana) {
		this.ID = iD;
		this.nome = nome;
		//marcar atributos não passados como zero pra evitar lixo
		//this.ataque = 0;
		//this.vidaAtual = 0;
		//this.vidaMaxima = 0;
		this.custoMana = custoMana;
	}
	
	public CartaLacaio(CartaLacaio origem) {
		this.ID = origem.ID;
		this.nome = origem.nome;
		this.ataque = origem.ataque;
		this.vidaAtual = origem.vidaAtual;
		this.vidaMaxima = origem.vidaMaxima;
		this.custoMana = origem.custoMana;
	}
	
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
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

	public int getCustoMana() {
		return custoMana;
	}

	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}

	public int getID() {
		return ID;
	}

	public void setID(int ID) {
		this.ID = ID;
	}


	@Override
	public String toString() {
		String out = getNome() + " (ID: " + getID() + ")\n";
		out = out + "Ataque = " + getAtaque() + "\n";
		out = out + "Vida Atual = "+ getVidaAtual()+ "\n";
		out = out + "Vida Máxima = "+ getVidaMaxima()+ "\n";
		out = out + "Custo de Mana = " + getCustoMana()+ "\n";
		return out;
	}
/*
	public void buffar(int a){
		this.ataque +=a;
		this.vidaAtual+=a;
		alteraNomeFortalecido();
	}
	
	public void buffar(int a, int v){
		this.ataque +=a;
		this.vidaAtual+=v;
		alteraNomeFortalecido();
	}
	
	public void alteraNomeFortalecido(){
		this.nome+= " Buffed";
	}
	*/
}
