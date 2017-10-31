package br.unicamp.ic.mc302.banco;

public class Principal3 {

	public static void main(String args[]) {

		// Alternativa 1
		RepositorioContasArray rep = new RepositorioContasArray();

		// Alternativa 2
		// RepositorioContasVector rep = new RepositorioContasVector();

		CadastroContas cad = new CadastroContas(rep);

		ContaCor cc = new ContaCor("Fernando", 0, 1, 1);

		if (cad.inserir(cc) == true) {
			System.out.println("Conta 1 cadastrada com sucesso. Saldo: " + cc.getSaldo(1));
		}

		cad.creditar(1, 200);

		ContaCor cc2 = cad.procurar(1);

		System.out.println("Conta " + cc2.getNumConta() + " encontrada. Saldo: " + cc2.getSaldo(1));

		cad.remover(1);

		if (cad.remover(1) == false) {
			System.out.println("Conta 1 removida com sucesso.");
		}
	}
}
