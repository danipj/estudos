package br.unicamp.ic.mc302.motor;

public class Bateria {

	private int carga;
	
	public Bateria(int carga) {
		this.carga = carga;
	}
	
	public boolean verificar() {
		if (carga > 0) {
			System.out.println("--- bateria com carga ---");
			return true;
		}
		System.out.println("--- bateria sem carga ---");
		return false;
	}

	public int getCarga() {
		return carga;
	}

	public void setCarga(int carga) {
		this.carga = carga;
	}

}
