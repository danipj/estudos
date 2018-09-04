package br.unicamp.ic.mc302.banco;

public abstract class Repositorio implements IRepositorioContas{

	public boolean atualizar(ContaCor c) {
		int num = c.getNumConta();
		boolean ok = remover(num);
		if (ok) {
			ok = inserir(c);
		}

		return ok;
	}
}
