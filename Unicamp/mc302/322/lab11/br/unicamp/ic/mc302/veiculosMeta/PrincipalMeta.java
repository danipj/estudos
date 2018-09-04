package br.unicamp.ic.mc302.veiculosMeta;

public class PrincipalMeta {

	public static void main(String[] args) {
		PilhaDeVeiculos pilha;
		pilha = new PilhaDeVeiculos(10); // pilha de 10 elementos
		System.out.println("\nA Fila de Veiculos contem: \n");
		pilha.adicionaVeiculo(new Carro(1001, 5));
		pilha.adicionaVeiculo(new Caminhao(1002, 2));
		pilha.adicionaVeiculo(new Carro(1003, 2));
		pilha.adicionaVeiculo(new Carro(1004, 5));
		pilha.adicionaVeiculo(new Caminhao(1005, 1));
		pilha.adicionaVeiculo(new Carro(1006, 6));
		pilha.adicionaVeiculo(new Caminhao(1007, 2));

		pilha.mostrarPilhaDeVeiculos();

		// Mostrar total de instanciações
		System.out.println("==============================");
		System.out.println("           TOTAIS");
		System.out.println("==============================");
		System.out.println("TOTAL DE VEICULOS:");
		System.out.println("   " + Veiculo.getContadorVeiculos() + " unidades");
		System.out.println("TOTAL DE CARROS:");
		System.out.println("   " + Carro.getContadorCarros() + " unidades");
		System.out.println("TOTAL DE CAMINHOES:");
		System.out.println("   " + Caminhao.getContadorCaminhoes() + " unidades");
	}
}
