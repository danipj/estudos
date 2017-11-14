package br.unicamp.ic.mc302.documento2;

import java.sql.Date;

public class Encomenda extends CartaRegistrada{
	private String conteudo;
	
	public Encomenda(Date dataEnvio, String local) {
		super(dataEnvio, local);
		// TODO Auto-generated constructor stub
	}

	public Encomenda(Date dataEnvio, String local, String conteudo) {
		super(dataEnvio, local);
		this.conteudo = conteudo;
	}

	public String getConteudo() {
		return conteudo;
	}

	public void setConteudo(String conteudo) {
		this.conteudo = conteudo;
	}

	
}
