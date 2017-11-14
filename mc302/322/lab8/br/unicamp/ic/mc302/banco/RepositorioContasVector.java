package br.unicamp.ic.mc302.banco;

import java.util.Vector;

public class RepositorioContasVector extends Repositorio implements IRepositorioContas {

	private Vector<ContaCor> elementos;

	private static final int NAO_ENCONTRADO = -1;

	public RepositorioContasVector() {
		elementos = new Vector<ContaCor>();
	}

	public boolean inserir(ContaCor c) {
		elementos.add(c);
		return true;
	}

	public ContaCor procurar(int numConta) {

		ContaCor retorno = null;
		int i = obterIndiceElemento(numConta);
		if (i != NAO_ENCONTRADO) {
			retorno = (ContaCor) elementos.elementAt(i);
		}

		return retorno;
	}

	private int obterIndiceElemento(int numConta) {
		int indice = 0;
		boolean achou = false;
		while (indice < elementos.size() && !achou) {
			ContaCor c = (ContaCor) elementos.elementAt(indice);
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
			elementos.remove(i);
			retorno = true;
		}

		return retorno;
	}

}