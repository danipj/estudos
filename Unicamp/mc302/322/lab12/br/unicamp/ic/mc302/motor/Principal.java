package br.unicamp.ic.mc302.motor;

public class Principal {

	public static void main(String[] args) {
		VelaDeIgnicao velaDeIgnicao = new VelaDeIgnicao();
		Injetor injetor = new Injetor(0);
		Bateria bateria = new Bateria(100);
		Motor motor = new Motor(bateria, injetor, velaDeIgnicao);
		motor.ligar();
	}
	
}
