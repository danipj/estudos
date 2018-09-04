package br.unicamp.ic.mc302.veiculosMeta;

class PilhaDeVeiculos {
	int capacidade;
	int tamanho;
	Veiculo[] veiculos;

	public PilhaDeVeiculos(int quant) {
		veiculos = new Veiculo[quant];
		capacidade = quant;
		tamanho = 0; // inicialmente está vazia
	}

	public void adicionaVeiculo(Veiculo entrada) {
		if (capacidade > tamanho) {
			veiculos[tamanho] = entrada;
			tamanho++;
		}
		// Caso a fila esteja CHEIA
		else
			System.out.println("A Fila esta cheia!");
	}

	// Retorna e retira um índice da fila
	public Veiculo retiraVeiculo() {
		Veiculo retorno; // valor a ser retornado
		if (tamanho > 0) {
			tamanho--;
			retorno = veiculos[tamanho];
			veiculos[tamanho] = null;
		}
		// Caso a fila esteja VAZIA
		else {
			System.out.println("A Fila esta vazia!");
			retorno = null;
		}
		return retorno;
	}

	// mostra o valor de uma fila de veículos
	public void mostrarPilhaDeVeiculos() {
		for (int i = 0; i < tamanho; i++) {
			System.out.println("Veículo " + (i + 1));
			veiculos[i].mostrar();
			System.out.println("******************************");
		}
	}
}