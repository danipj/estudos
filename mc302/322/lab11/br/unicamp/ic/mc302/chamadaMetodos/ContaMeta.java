package br.unicamp.ic.mc302.chamadaMetodos;

public class ContaMeta {
	private float saldo;
	private int contadorNumMsgObjeto;

	public ContaMeta() {
		saldo = 0;
		contadorNumMsgObjeto = 0;
	}

	public void creditar(float valor) {
		saldo += valor;
		System.out.println("O metodo foi executado;");
		// incrementar o contador de chamadas do objeto
		contadorNumMsgObjeto++;
	}

}
