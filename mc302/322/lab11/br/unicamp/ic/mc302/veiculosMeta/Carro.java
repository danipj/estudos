package br.unicamp.ic.mc302.veiculosMeta;

class Carro extends Veiculo {
	private static int contadorCarros;
	private int numPassageiros;

	public Carro(int placa, int numPassageiros) {
		super(placa);
		this.numPassageiros = numPassageiros;
	}

	public static int getContadorCarros() {
		return contadorCarros;
	}

	public void mostrar() { // imprime dados do veículo
		System.out.println("Carro, com CAPACIDADE PARA: " + numPassageiros);
		super.mostrar();
	}
}
