package br.unicamp.ic.mc302.banco;

public class CadastroContas {

	private IRepositorioContas repositorio;

	public CadastroContas(IRepositorioContas argRep) {
		this.repositorio = argRep;
	}

	public boolean inserir(ContaCor c) {
		return repositorio.inserir(c);
	}

	public ContaCor procurar(int numConta) {
		return repositorio.procurar(numConta);
	}

	public boolean remover(int numConta) {
		return repositorio.remover(numConta);
	}

	public boolean creditar(int numConta, double valor) {
		boolean operacaoOk = false;
		ContaCor c = repositorio.procurar(numConta);
		if (c != null) {
			c.creditaValor(valor);
			operacaoOk = repositorio.atualizar(c);
		}

		return operacaoOk;
	}
}