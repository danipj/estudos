	package br.unicamp.ic.mc302.documento2;

import java.sql.Date;

public class CartaRegistrada extends Carta2 {
	private Date dataEnvio;
	private String local;
	
	public CartaRegistrada(Date dataEnvio, String local) {
		super();
		this.dataEnvio = dataEnvio;
		this.local = local;
	}
	public Date getDataEnvio() {
		return dataEnvio;
	}
	public void setDataEnvio(Date dataEnvio) {
		this.dataEnvio = dataEnvio;
	}
	public String getLocal() {
		return local;
	}
	public void setLocal(String local) {
		this.local = local;
	}
	
}
