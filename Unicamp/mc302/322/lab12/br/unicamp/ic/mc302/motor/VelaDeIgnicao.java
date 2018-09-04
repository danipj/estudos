package br.unicamp.ic.mc302.motor;

public class VelaDeIgnicao {
	
	public static final int cargaMinima = 5; 

	public boolean ignicao(int carga) {
		if (carga >= cargaMinima) {
			System.out.println("--- ignicao ---");
			return true;
		}
		System.out.println("--- carga insuficiente ---");
		return false;
	}
	
}
