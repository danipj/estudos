package br.unicamp.ic.mc302.veiculos;

public class Carro extends Veiculo implements Motorizado {
	private int lotacao;
	private int numPortas;

	public Carro(int lot, int num, int ano, String mar, String mod, String pl) {
		super(ano, mar, mod, pl);
		lotacao = lot;
		numPortas = num;
	}

	public void mostra() {
		System.out.println("\nTipo --> Carro");
		System.out.println("Lotação = " + lotacao);
		System.out.println("Numero de Portas = " + numPortas);
		super.mostra();
	}

	@Override
	public void ligar() {
		System.out.println("Ligando carro...");
	}
}