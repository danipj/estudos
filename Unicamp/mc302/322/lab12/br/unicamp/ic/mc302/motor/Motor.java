package br.unicamp.ic.mc302.motor;

public class Motor {
	private Bateria bateria;
	private Injetor injetor;
	private VelaDeIgnicao velaDeIgnicao;
	
	
	public Motor(Bateria bateria, Injetor injetor, VelaDeIgnicao velaDeIgnicao) {
		this.bateria = bateria;
		this.injetor = injetor;
		this.velaDeIgnicao = velaDeIgnicao;
	}

	public void ligar(){
		if (bateria.verificar() && injetor.injetar()){
			velaDeIgnicao.ignicao(bateria.getCarga());
			System.out.println("Motor ligado");
		} else {
			System.out.println("Motor falhou ao ligar");
		}
	}
	
}
