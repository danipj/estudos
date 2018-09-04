package br.unicamp.ic.mc302.banco;

public class RepositorioContasArray extends Repositorio implements IRepositorioContas {

	private ContaCor[] elementos;

	private static final int NAO_ENCONTRADO = -1;
	private static final int MAX_ELEMENTOS = 20;
	private int contador = 0;

	public RepositorioContasArray() {
		elementos = new ContaCor[MAX_ELEMENTOS];
	}

	public boolean inserir(ContaCor c) {
		boolean retorno = false;
		if (contador < MAX_ELEMENTOS) {
			elementos[contador] = c;
			contador++;
			retorno = true;
		}
		return retorno;
	}

	public ContaCor procurar(int numConta) {

		ContaCor retorno = null;
		int i = obterIndiceElemento(numConta);
		if (i != NAO_ENCONTRADO) {
			retorno = elementos[i];
		}

		return retorno;
	}

	private int obterIndiceElemento(int numConta) {
		int indice = 0;
		boolean achou = false;
		while (indice < contador && !achou) {
			ContaCor c = elementos[indice];
			if (c.getNumConta() == numConta) {
				achou = true;
			} else {
				indice++;
			}
		}

		if (!achou) indice = NAO_ENCONTRADO;

		return indice;
	}

	public boolean remover(int numConta) {
		boolean retorno = false;
		int i = obterIndiceElemento(numConta);
		if (i != NAO_ENCONTRADO) {
			// "puxa" os elementos do array para trás (para não deixar um
			// espaço vazio no array).
			while (i < contador - 1) {
				elementos[i] = elementos[i + 1];
				i++;
			}
			contador--;
			retorno = true;
		}

		return retorno;
	}

}