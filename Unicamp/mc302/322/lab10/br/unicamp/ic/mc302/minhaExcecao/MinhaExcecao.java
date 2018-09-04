package br.unicamp.ic.mc302.minhaExcecao;

public class MinhaExcecao extends Exception {
	private String attr;

	public MinhaExcecao() {
	}

	public MinhaExcecao(String nome) {
		super(nome);
		this.attr = nome;
	}
}
