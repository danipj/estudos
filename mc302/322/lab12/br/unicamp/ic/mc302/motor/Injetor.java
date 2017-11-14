package br.unicamp.ic.mc302.motor;

public class Injetor {

	private int qtdCombustivel = 0;
	
	public Injetor(int qtdCombustivel) {
		this.qtdCombustivel = qtdCombustivel;
	}
	
	public boolean injetar() {
		if (qtdCombustivel-- > 0) {
			System.out.println("--- combustivel injetado ---");
			return true;
		}
		System.out.println("--- sem combustivel ---");
		return false;
	}

	public int getQtdCombustivel() {
		return qtdCombustivel;
	}
	
}
